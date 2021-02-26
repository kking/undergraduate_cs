package edu.miracosta.cs113;

/**
 * AVLTree : an implementation of a binary search tree, containing properties for which the structure remains
 * balanced following any number of inserted elements.
 *
 * Material adapted from Koffman and Wolfgang's Data Structures: Abstraction and Design Using Java (2nd ed.).
 *
 * @author King
 * @version 1.0
 */
public class AVLTree<E extends Comparable<E>> extends BinarySearchTreeWithRotate<E> {
    /** Flag to indicate that height of tree has increased. */
    private boolean increase;

    /**
     * Constructs an empty binary search tree, where the root is set to null.
     */
    public AVLTree() {
        super();
    }

    /**
     * Add starter method.
     * pre: the item to insert implements the Comparable interface.
     *
     * @param item The item to be inserted
     * @return true if item is inserted; false if it already exists in the tree
     * @throws ClassCastException if item is not Comparable
     */
    @Override
    public boolean add(E item) {
        increase = false;
        root = add((AVLNode<E>) root, item);
        return addReturn;
    }

    /**
     * Recursive add method. Inserts the given object into the tree.
     * post: addReturn is set to true if the item is inserted, false if the item is already in the tree,
     *
     * @param localRoot The local root of the subtree
     * @param item The object to be inserted
     * @return The new local root of the subtree with the item inserted
     */
    private AVLNode<E> add (AVLNode<E> localRoot, E item) {
        if (localRoot == null) {
            // Return item to be inserted.
            addReturn = true;
            increase = true;
            return new AVLNode<E>(item);
        }
        if (item.compareTo(localRoot.data) == 0) {
            // Item already exists in the tree.
            increase = false;
            addReturn = false;
            return localRoot;
        }
        else if (item.compareTo(localRoot.data) < 0) {
            // item is less than the data field of the current node;
            // Recursively insert item as a left subtree.
            localRoot.left = add((AVLNode<E>) localRoot.left, item);

            // Upon return from recursive call -
            // If increase is true, then the height of the left subtree has increased;
            // decrement the balance by calling decrementBalance.
            if (increase) {
                decrementBalance(localRoot);
                if (localRoot.balance == AVLNode.BALANCED) {
                    increase = false;
                }
                if (localRoot.balance < AVLNode.LEFT_HEAVY) {
                    increase = false;
                    return rebalanceLeft(localRoot);
                }
            }
            return localRoot; // Rebalance not needed.
        }
        else {
            // Item is greater than the data field of the current node.
            // Insertion process is symmetrical to that of the previous conditional block.
            localRoot.right = add((AVLNode<E>) localRoot.right, item);

            if (increase) {
                incrementBalance(localRoot);
                // if (localRoot.balance == AVLNode.BALANCED) increase = false;
                if (localRoot.balance == AVLNode.BALANCED) {
                    increase = false;
                }
                if (localRoot.balance > AVLNode.RIGHT_HEAVY) {
                    increase = false;
                    return rebalanceRight(localRoot);
                }
            }
            return localRoot;
        }
    }

    /**
     * Method to rebalance left.
     * pre: localRoot is the root of an AVL subtree that is critically left-heavy.
     * post: Balance is restored in the subtree.
     *
     * @param localRoot Root of the AVL subtree that needs rebalancing
     * @return a new localRoot
     */
    private AVLNode<E> rebalanceLeft(AVLNode<E> localRoot) {
        // Obtain references to the left child.
        AVLNode<E> leftChild = (AVLNode<E>) localRoot.left;

        if (leftChild.balance > AVLNode.BALANCED) {
            // Left subtree is left-right heavy, rotate left around subtree root.

            // Obtain reference to left-right child.
            AVLNode<E> leftRightChild = (AVLNode<E>) leftChild.right;

            // Adjust the balances to be their new values after rotations occur.
            if (leftRightChild.balance < AVLNode.BALANCED) {
                // Left child has right-left imbalance
                leftChild.balance = AVLNode.BALANCED;
                leftRightChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.RIGHT_HEAVY;
            }
            else {
                leftChild.balance = AVLNode.LEFT_HEAVY;
                leftRightChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.BALANCED;
            }
            // Perform left rotation around the child.
            localRoot.left = rotateLeft(leftChild);
        }
        else if (leftChild.balance < AVLNode.BALANCED){
            // Left-left case - leftChild (the new root) and the root (new right child)
            // will both be balanced after the rotation right.
            leftChild.balance = AVLNode.BALANCED;
            localRoot.balance = AVLNode.BALANCED;
        }
        // Rotate right around the parent.
        return (AVLNode<E>) rotateRight(localRoot);

        /* Does not update the left child's balance when a right - left imbalance occurs.
         * This would also be the case for left - right imbalances with a rebalanceRight
         * implementation based on that rebalanceLeft. An additional conditional block is
         * required when checking for left - right- right or left - right - left imbalances. */
    }

    private AVLNode<E> rebalanceRight(AVLNode<E> localRoot) {
        // Obtain reference to right child
        AVLNode<E> rightChild = (AVLNode<E>) localRoot.right;

        if (rightChild.balance < AVLNode.BALANCED) {
            // Right-left case
            AVLNode<E> rightLeftChild = (AVLNode<E>) rightChild.left;

            if (rightLeftChild.balance < AVLNode.BALANCED) {
                rightChild.balance = AVLNode.BALANCED;
                rightLeftChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.RIGHT_HEAVY;
            }
            else {
                rightChild.balance = AVLNode.LEFT_HEAVY;
                rightLeftChild.balance = AVLNode.BALANCED;
                localRoot.balance = AVLNode.BALANCED;
            }
            // Perform right rotation around the child.
            localRoot.right = rotateRight(rightChild);
        }
        else if (rightChild.balance > AVLNode.BALANCED) {
            // Right-right case
            rightChild.balance = AVLNode.BALANCED;
            localRoot.balance = AVLNode.BALANCED;
        }
        // Rotate left around the parent.
        return (AVLNode<E>) rotateLeft(localRoot);
    }

    /**
     * Method called following an insertion into a node's left subtree in order to decrement the
     * balance of said node.
     *
     * @param node The current node in this tree
     */
    private void decrementBalance(AVLNode<E> node) {
        // Decrement the balance.
        node.balance --;
        if (node.balance == AVLNode.BALANCED) {
            // If now balanced, overall height has not increased.
            increase = false;
        }
    }

    private void incrementBalance(AVLNode<E> node) {
        // Increment the balance.
        node.balance ++;
        if (node.balance == AVLNode.BALANCED) {
            // If now balanced, overall height has not increased.
            increase = false;
        }
    }

    /**
     * Delete method (stubbed).
     *
     * @param target The item to be deleted from the tree
     * @return null
     */
    @Override
    public E delete(E target) {
        return null;
    }


    /**
     * AVLNode : class to represent an AVL Node. It extends the BinaryTree.Node by adding the balance data field.
     */
    private static class AVLNode<E> extends Node<E> {
        /** Constant indicating a left-heavy tree. */
        public static final int LEFT_HEAVY = -1;
        /** Constant indicating a balanced tree. */
        public static final int BALANCED = 0;
        /** Constant indicating a right-heavy tree. */
        public static final int RIGHT_HEAVY = 1;
        /** Difference between right subtree height and left subtree height (right - left). */
        private int balance;

        /**
         * Constructs a node with the given item as the data field.
         *
         * @param item The data field
         */
        public AVLNode(E item) {
            super(item);
            balance = BALANCED;
        }

        /**
         * Returns a string representation of this object, with the valance value appended to its contents.
         *
         * @return A String representing this node.
         */
        @Override
        public String toString() {
            return super.toString() + "(" + balance + ")";
        }

    } // End of class AVLNode

} // End of class AVLTree
