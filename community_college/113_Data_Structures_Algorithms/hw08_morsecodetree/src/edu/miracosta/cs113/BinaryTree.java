package edu.miracosta.cs113;

import java.io.Serializable;
import java.util.Scanner;

/**
 * BinaryTree : Class for a binary tree that stores objects of type E.
 *
 * @author Elliot B. Koffman, Paul A. T. Wolfgang
 * @author Data Structures: Abstraction and Design Using Java (2nd ed.)
 */
public class BinaryTree<E> implements Serializable {

    /** Reference to the root of the tree */
    protected Node<E> root;

    /**
     * Constructs an empty binary tree, where the root is set to null.
     */
    public BinaryTree() {
        root = null;
    }

    /**
     * Constructs a binary tree with the given node as the root.
     * @param root node representing the root of the sub/tree
     */
    protected BinaryTree(Node<E> root) {
        this.root = root;
    }

    /**
     * Constructs a new binary tree with data in its root leftTree as its left subtree and rightTree as its right
     * subtree.
     *
     * @param data the data Object representing the root of this tree
     * @param leftTree the left subtree
     * @param rightTree the right subtree
     */
    public BinaryTree(E data, BinaryTree<E> leftTree, BinaryTree<E> rightTree) {
        root = new Node<E>(data);
        if (leftTree != null) {
            root.left = leftTree.root;
        }
        else {
            root.left = null;
        }
        if (rightTree != null) {
            root.right = rightTree.root;
        }
        else {
            root.right = null;
        }
    }

    /**
     * Returns the left subtree.
     *
     * @return The left subtree, or null if either the root or the left subtree is null
     */
    public BinaryTree<E> getLeftSubtree() {
        if (root != null && root.left != null) {
            return new BinaryTree<E>(root.left);
        }
        else {
            return null;
        }
    }

    /**
     * Returns the right subtree.
     *
     * @return The right subtree, or null if either the root or the right subtree is null
     */
    public BinaryTree<E> getRightSubtree() {
        if (root != null && root.right != null) {
            return new BinaryTree<E>(root.right);
        }
        else {
            return null;
        }
    }

    /**
     * Returns the data stored in the root node.
     *
     * @return The data in the current root
     */
    public E getData() {
        return root.data;
    }

    /**
     * Determines whether this tree is a leaf node.
     *
     * @return true if the root has no children
     */
    public boolean isLeaf() {
        return (root.left == null && root.right == null);
    }

    /**
     * Generates a String representing a preorder traversal in which each local root is indented a distance
     * proportional to its depth.
     *
     * @return a String representation of the tree
     */
    public String toString() {
        StringBuilder sb = new StringBuilder();
        preOrderTraverse(root, 1, sb);
        return sb.toString();
    }

    /**
     * Performs a preorder traversal of the subtree whose root is node, appends the representation to the
     * StringBuilder, and increments the value of depth (the current tree level).
     *
     * @param node The local root
     * @param depth The depth
     * @param sb The string buffer to save the output
     */
    private void preOrderTraverse(Node<E> node, int depth, StringBuilder sb) {
        for (int i = 1; i < depth; i ++) {
            sb.append(" ");
        }
        if (node == null) {
            sb.append("null\n");
        }
        else {
            sb.append(node.toString() + "\n");
            preOrderTraverse(node.left, depth + 1, sb);
            preOrderTraverse(node.right, depth + 1, sb);
        }
    }

    /**
     * Constructs a binary tree by reading its data using Scanner scan.
     * pre: The input consists of a preorder traversal of the binary tree. The line "null" indicates a null tree.
     *
     * @param scan The Scanner attached to the input file.
     * @return The binary tree
     */
    public static BinaryTree<String> readBinaryTree(Scanner scan) {
        // Read a line and trim leading and trailing spaces.
        if (!scan.hasNext()) {
            return null;
        }
        else {
            String data = scan.next();
            BinaryTree<String> leftTree = readBinaryTree(scan);
            BinaryTree<String> rightTree = readBinaryTree(scan);
            return new BinaryTree<String>(data, leftTree, rightTree);
        }
    }

    /**
     * Protected static inner class to encapsulate a tree node. Accessible in the subclasses of BinaryTree.
     */
    protected static class Node<E> implements Serializable {
        /** The information stored in this node. */
        protected E data;
        /** Reference to the left child/subtree. */
        protected Node<E> left;
        /** Reference to the right child/subtree. */
        protected Node<E> right;

        /**
         * Constructs a leaf node with given data.
         *
         * @param data The data to store in this node
         */
        public Node(E data) {
            this.data = data;
            left = null;
            right = null;
        }

        /**
         * Returns a String representation of the node.
         *
         * @return A String representation of the data fields
         */
        public String toString() {
            return data.toString();
        }

    } // End of class Node

} // End of class BinaryTree