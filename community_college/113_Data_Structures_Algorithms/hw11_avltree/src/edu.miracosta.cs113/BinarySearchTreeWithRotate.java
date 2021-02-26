package edu.miracosta.cs113;

/**
 * BinarySearchTreeWithRotate : Class that extends BinarySearchTree by adding the rotate operations. Rotation will
 * change the balance of a search tree while preserving the search tree property. Used as a common base class for
 * self-balancing trees.
 *
 * @author Elliot B. Koffman, Paul A. T. Wolfgang
 * @author Data Structures: Abstraction and Design Using Java (2nd ed.), pp. 476
 */
public class BinarySearchTreeWithRotate<E extends Comparable<E>> extends BinarySearchTree<E> {

    /**
     * Constructs an empty binary search tree, where the root is set to null.
     */
    public BinarySearchTreeWithRotate() {
        super();
    }

    /**
     * Constructs a binary search tree with the given node as the root.
     *
     * @param root node representing the root of the subtree
     */
    protected BinarySearchTreeWithRotate(Node<E> root) {
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
    public BinarySearchTreeWithRotate(E data, BinaryTree<E> leftTree, BinaryTree<E> rightTree) {
        super(data, leftTree, rightTree);
    }

    /**
     * Method to perform a right rotation.
     *
     * pre: root is the root of a binary search tree.
     * post: root.right is the root of a binary search tree;
     *       root.right.right is raised one level;
     *       root.right.left does not change levels;
     *       root.left  is lowered one level;
     *       the new root is returned.
     *
     * @param root The root of the binary tree to be rotated
     * @return The new root of the rotated tree
     */
    protected Node<E> rotateRight(Node<E> root) {
        Node<E> temp = root.left;
        root.left = temp.right;
        temp.right = root;
        // root = temp;
        return temp;
    }

    /**
     * Method to perform a left rotation.
     *
     * pre: root is a root of the binary search tree.
     * post:
     *
     * @param root The root of the binary tree to be rotated
     * @return The new root of the rotated tree
     */
    protected Node<E> rotateLeft(Node<E> root) {
        Node<E> temp = root.right;
        root.right = temp.left;
        temp.left = root;
        // root = temp;
        return temp;
    }

} // End of class BinarySearchTreeWithRotate