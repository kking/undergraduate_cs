package edu.miracosta.cs113;

import java.util.Random;
import java.util.Scanner;

/**
 * AVLTreeDriver : Demonstration program for an implementation of the AVLTree class, a specialized binary search
 * tree containing self-balancing properties in response to every insertion of an element.
 *
 * @author King
 * @version 1.0
 */
public class AVLTreeDriver {

    /** Minimum number of elements to be added to both trees. */
    public static final int MIN_ELEMENTS = 11;
    /** Maximum number of elements to be added to both trees. */
    public static final int MAX_ELEMENTS = 15;
    /** Maximum value for any randomly generated integer to populate a tree. */
    public static final int MAX_VALUE = 99;

    public static Scanner KEYBOARD = new Scanner(System.in);
    /**
     * Main method for demonstrating the AVLTree class implementation.
     *
     * ALGORITHM:
     *      1. Create a collection of > 20 randomly generated numbers.
     *      2. Insert the above set of numbers in a binary search tree which would be unbalanced.
     *      3. Verify that each tree is correct through an inorder traversal.
     *      4. Display the format of each tree that was built to compare their heights.
     *
     * @param args not used in the driver program
     */
    public static void main(String[] args) {

        AVLTree avlTree;
        BinarySearchTree unbalancedTree;
        boolean runProgram = true;

        while (runProgram) {

            avlTree = new AVLTree<Integer>();
            unbalancedTree = new BinarySearchTree<Integer>();

            // Insert the same collection of > 20 randomly generated numbers into both trees.
            populateTrees(avlTree, unbalancedTree);

            // Verify each tree is correct through inorder traversal
            // Display format of each tree that was built, compare heights
            // TODO: format based on inorder traversal, compare heights
            displayTreeFormats(avlTree, unbalancedTree);

            runProgram = runAgain("Run again?");

        } // End of while loop runProgram

        KEYBOARD.close();

    } // End of main method

    /**
     * Inserts a collection of > 20 randomly generated numbers into an instance of a self-balancing binary search
     * tree. The same collection is inserted into an unbalanced binary search tree.
     *
     * @param avlTree An instance of the AVL tree implementation
     * @param bst An instance of the binary search tree implementation without rotation
     */
    @SuppressWarnings("unchecked")
    public static void populateTrees(AVLTree avlTree, BinarySearchTree bst) {
        Random intGenerator = new Random();

        // Determines number of elements to add to collection.
        int numberOfElements = intGenerator.nextInt(MAX_ELEMENTS - MIN_ELEMENTS + 1) + MIN_ELEMENTS;

        System.out.println("Adding " + numberOfElements + " elements to both trees ..."); // may be less due to duplicate values

        for (int i = 0; i < numberOfElements; i ++) {
            int currentNumber = intGenerator.nextInt(MAX_VALUE);
            avlTree.add(currentNumber);
            bst.add(currentNumber);
        }
    }

    /**
     * Displays the format of each tree that was built for comparion between their heights.
     *
     * @param avlTree An instance of the AVL tree implementation
     * @param bst An instance of the binary search tree implementation without rotation
     */
    public static void displayTreeFormats(AVLTree avlTree, BinarySearchTree bst) {
        // toString method of BinarySearchTree and its descendant utilizes an inorder traversal of the given trees.
        System.out.println("Unbalanced binary search tree: \n" + bst);
        System.out.println("AVL tree: \n" + avlTree);

    }

    /**
     * Prompts the user to select an option which determines the reiteration of the main method's while loop.
     *
     * @param message A custom message to be displayed with the prompt "Run again? (y/n)"
     * @return true if the user responds 'y', false if 'n'
     */
    public static boolean runAgain(String message) {
        boolean validInput = false; // Sets true when a valid input is received
        boolean result = false;

        while (! validInput) {
            System.out.println(message + " (y/n).");
            switch (KEYBOARD.nextLine().charAt(0)) {
                case 'y':
                case 'Y':
                    result = true;
                case 'n':
                case 'N':
                    validInput = true;
                    break;
                default:
                    System.out.println("Invalid input.");
                    break;
            }
        }

        return result;
    }

} // End of AVLTreeDriver