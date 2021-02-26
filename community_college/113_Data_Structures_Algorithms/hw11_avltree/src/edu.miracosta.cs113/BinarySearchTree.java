package edu.miracosta.cs113;

/**
 * BinarySearchTree : an implementation of a binary tree which allows for a more efficient means of insertion and
 * obtaining data at the best-case time complexity of O(log n).
 *
 * @author Elliot B. Koffman, Paul A. T. Wolfgang
 * @author Data Structures: Abstraction and Design Using Java (2nd ed.), pp. 317
 */
public class BinarySearchTree<E extends Comparable<E>> extends BinaryTree<E> implements SearchTree<E> {
    /** Return value from the public add method. */
    protected boolean addReturn;
    /** Return value from the public delete method. */
    protected E deleteReturn;

    /**
     * Constructs an empty binary search tree, where the root is set to null.
     */
    public BinarySearchTree() {
        super();
    }

    /**
     * Constructs a binary search tree with the given node as the root.
     *
     * @param root node representing the root of the subtree
     */
    protected BinarySearchTree(Node<E> root) {
        super(root);
    }

    /**
     * Constructs a new binary search tree with data in its root leftTree as its left subtree and rightTree as its
     * right subtree.
     *
     * @param data the data Object representing the root of this tree
     * @param leftTree the left subtree
     * @param rightTree the right subtree
     */
    public BinarySearchTree(E data, BinaryTree<E> leftTree, BinaryTree<E> rightTree) {
        super(data, leftTree, rightTree);
    }

    /**
     * Starter method find.
     * pre: The target object must implement the Comparable interface.
     *
     * @param target The Comparable object being sought
     * @return The object (if found), otherwise null
     */
    @Override
    public E find(E target) {
        return find(root, target);
    }

    /**
     * Recursive find method.
     *
     * @param localRoot The local subtree's root
     * @param target The object being sought
     * @return The object (if found), otherwise null
     */
    private E find(Node<E> localRoot, E target) {
        if (localRoot == null) {
            return null;
        }

        // Compare the target with the data field at this root.
        int compResult = target.compareTo(localRoot.data);
        if (compResult == 0) {
            return localRoot.data;
        }
        else if (compResult < 0) {
            return find(localRoot.left, target);
        }
        else {
            return find(localRoot.right, target);
        }
    }

    /**
     * Returns true if the target is found in the tree.
     *
     * @param target The item whose presence in the tree is to be determined
     * @return true if target is found in the tree, false otherwise
     */
    @Override
    public boolean contains(E target) {
        return (find(target) != null);
    }

    /**
     * Starter method add.
     * pre: The object to insert must implement the Comparable interface.
     *
     * @param item The item to be inserted
     * @return true if the object is inserted, false if it already exists in the tree
     */
    @Override
    public boolean add(E item) {
        root = add(root, item);
        return addReturn;
    }

    /**
     * Recursive add method.
     * post: The data field addReturn is set true if the item is added to the tree, false if the item is already
     * in the tree.
     *
     * @param localRoot The local root of the subtree
     * @param item The object to be inserted
     * @return The new local root that now contains the inserted item
     */
    private Node<E> add(Node<E> localRoot, E item) {
        if (localRoot == null) {
            // item is not in the tree - insert it.
            addReturn = true;
            return new Node<E>(item);
        }
        else if (item.compareTo(localRoot.data) == 0) {
            // item is equal to localRoot.data;
            addReturn = false;
            return localRoot;
        }
        else if (item.compareTo(localRoot.data) < 0) {
            // item is less than localRoot.data
            localRoot.left = add(localRoot.left, item);
            return localRoot;
        }
        else {
            // item is greater than localRoot.data
            localRoot.right = add(localRoot.right, item);
            return localRoot;
        }
    }

    /**
     * Removes target (if found) from the tree and returns true; otherwise returns null.
     *
     * @param target The item to be removed from the tree
     * @return true if the item was found and removed from the tree, false otherwise
     */
    @Override
    public boolean remove(E target) {
        return (delete(target) != null);
    }

    /**
     * Starter method delete.
     * posr: The object is not in the tree.
     *
     * @param target The item to be deleted from the tree
     * @return The object deleted from the tree, or null if the object was not in the tree
     * @throws ClassCastException if target does not implement Comparable
     */
    @Override
    public E delete(E target) {
        root = delete(root, target);
        return deleteReturn;
    }

    /**
     * Recursive delete method.
     * post: The item is not in the tree; deleteReturn is equal to the deleted item as it was stored in the tree,
     * or null if the item was not found.
     *
     * @param localRoot The root of the current subtree
     * @param item The item to be inserted
     * @return The modified local root that does not contain the item
     */
    private Node<E> delete(Node<E> localRoot, E item) {
        if (localRoot == null) {
            // item is not in the tree.
            deleteReturn = null;
            return null;
        }

        // Search for item to delete.
        int compResult = item.compareTo(localRoot.data);
        if (compResult < 0) {
            // item is smaller than localRoot.data.
            localRoot.left = delete(localRoot.left, item);
            return localRoot;
        }
        else if (compResult > 0) {
            // item is larger than localRoot.data.
            localRoot.right = delete(localRoot.right, item);
            return localRoot;
        }
        else {
            // item is at local root.
            deleteReturn = localRoot.data;
            if (localRoot.left == null) {
                // If there is no left child. return right child (which can also be null).
                return localRoot.right;
            }
            else if (localRoot.right == null) {
                // If there is no right child, return left child.
                return localRoot.left;
            }
            else {
                // Node being deleted has 2 children, replace the data with inorder predecessor.
                if (localRoot.left.right == null) {
                    // The left child has no right child. Replace the data with the data in the left child.
                    localRoot.data = localRoot.left.data;
                    // Replace the left child with its left child.
                    localRoot.left = localRoot.left.left;
                    return localRoot;
                }
                else {
                    // Search for the inorder predecessor and replace the deleted note's data with it.
                    localRoot.data = findLargestChild(localRoot.left);
                    return localRoot;
                }
            }
        }
    }

    /**
     * Find the node that is the inorder predecessor and replace it with its left child (if any).
     * post: The inorder predecessor is removed from the tree.
     *
     * @param parent The parent of possible inorder predecessor
     * @return The data in the inorder predecessor
     */
    private E findLargestChild(Node<E> parent) {
        // If the right child has no right child, it is the inorder predecessor.
        if (parent.right.right == null) {
            E returnValue = parent.right.data;
            parent.right = parent.right.left;
            return returnValue;
        }
        else {
            return findLargestChild(parent.right);
        }
    }

    /**
     * Generates a String representing an inorder traversal in which each local root is indented a distance
     * proportional to its depth.
     *
     * @return a String representation of the tree
     */
    /*
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        inOrderTraverse(root, 1, sb);
        return sb.toString();
    } */

    /**
     * Performs an inrder traversal of the subtree whose root is node, appends the representation to the
     * StringBuilder, and increments the value of depth (the current tree level).
     *
     * @param node The local root
     * @param depth The depth
     * @param sb The string buffer to save the output
     */
    private void inOrderTraverse(Node<E> node, int depth, StringBuilder sb) {
        for (int i = 1; i < depth; i ++) {
            sb.append(" ");
        }
        if (node == null) {
            sb.append("null\n");
        }
        else {
            inOrderTraverse(node.left, depth + 1, sb); // Traverse left
            sb.append(node.toString() + "\n"); // Visit root
            inOrderTraverse(node.right, depth + 1, sb); // Traverse right

        }
    }

} // End of class BinarySearchTree