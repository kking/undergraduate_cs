package edu.miracosta.cs113;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * MorseCodeTree : A BinaryTree, with  Nodes of type Character to represent each letter of the English alphabet,
 * whose means of traversal may be used to decode morse code.
 *
 * @author King
 * @version 1.0
 */
public class MorseCodeTree extends BinaryTree<Character> {

    /** Text file name which contains each letter of the English alphabet followed by its morse code translation. */
    private static final String MORSE_CODE_FILE_NAME = "MorseCode.txt";

    /**
     * Default constructor creates a root node at level 1 which stores no letter. The tree is then built through
     * the helper method readMorseCodeTree based on a text file containing morse code values representing each
     * letter of the English alphabet.
     */
    public MorseCodeTree() {
        super(new Node<Character>(' '));
        readMorseCodeTree();
    }

    /**
     * Non-recursive helper method constructs a MorseCodeTree by reading the text file whose path is defined by the
     * above constant.
     *
     * This file has each line consisting of a letter followed by its code value (i.e., b ***). With this expectation,
     * each line is read and processed through the method's equivalent recursive function to build each node of the
     * MorseCodeTree.
     *
     * @return A BinaryTree of type Character which contains nodes representing each letter of the English alphabet
     */
    private BinaryTree<Character> readMorseCodeTree() {
        Scanner scan = null;
        try {
            File morseCodeText = new File(MORSE_CODE_FILE_NAME);
            scan = new Scanner(morseCodeText);
        }
        catch (FileNotFoundException fnfe) {
            System.out.println("File '" + MORSE_CODE_FILE_NAME + "' not found.");
            System.exit(1);
        }

        while (scan.hasNextLine()) {
            String line = scan.nextLine();
            readMorseCodeTree(root, line.substring(2), line.charAt(0));
        }

        scan.close();

        return new BinaryTree<Character>(root);
    }

    /**
     * Recursive helper method for constructing the MorseCodeTree. With the expectation that each previous node was
     * created in the order by which its morse code value directs its traversals throughout the tree, each letter is
     * stored in a position based on '*'s branching left and '-'s branching right. Therefore, it is important that
     * the given text file has its letters ordered by tree level, where the lengths of the morse code values are equal
     * to the number of traversals required to arrive to the given letter.
     *
     * @param localRoot The current existing node of the tree
     * @param tempCode The code as read as a substring from index 1 through each recursive call
     * @param letter The letter represented by the initial morse code value
     */
    private void readMorseCodeTree(Node<Character> localRoot, String tempCode, char letter) {
        if (tempCode.length() == 1) {
            // Final character determines the branch at which the current node is to be added
            if (tempCode.charAt(0) == '*') {
                localRoot.left = new Node<Character>(letter);
            }
            else if (tempCode.charAt(0) == '-') {
                localRoot.right = new Node<Character>(letter);
            }
        }
        else {
            // Continue traversal
            if (tempCode.charAt(0) == '*') {
                readMorseCodeTree(localRoot.left, tempCode.substring(1), letter);
            }
            else if (tempCode.charAt(0) == '-') {
                readMorseCodeTree(localRoot.right, tempCode.substring(1), letter);
            }
        }
    }

    /**
     * Non-recursive wrapper method for translating a String comprised of morse code values through traversals
     * in the MorseCodeTree.
     *
     * The given input is expected to contain morse code values, with '*' for dots and '-' for dashes, representing
     * only letters in the English alphabet. A StringBuilder appends the single letters which result from passing each
     * token through the method's recursive function, eventually returning the decoded message.
     *
     * @param input The given input representing letters in morse code
     * @return a String representing the decoded values from input
     * @throws MorseCodeException if a given token's length exceeds that of the tree's number of possible traversals,
     *         or if the given token contains a character that is neither '*' nor '-'
     */
    public String translateFromMorseCode(String input) throws MorseCodeException {
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(input);

        // Building String by individually translated morse code values
        while (st.hasMoreTokens()) {
            translateFromMorseCode(root, sb, st.nextToken());
        }

        return sb.toString();
    }

    /**
     * Recursive helper method for translating a String comprised of morse code values through traversals in the
     * MorseCodeTree.
     *
     * The given input is expected to contain morse code values, with '*' for dots and '-' for dashes, representing
     * only letters in the English alphabet. Each morse code value is delimited by a space.
     *
     * The MorseCodeTree is constructed in such a way that dots branch left and dashes branch right, so traversals are
     * performed according to the given morse code value until the last character directs the traversal to the
     * designated letter value. This letter value is then appended to the given StringBuilder.
     *
     * @param localRoot The current root in the MorseCodeTree which stores a character from the English alphabet
     * @param sb A StringBuilder object which stores each letter of the morse code translation
     * @param input The given input representing letters in morse code
     * @throws MorseCodeException if the traversal attempts to continue through a leaf node, or if a character that
     *         is not '*' or '-' is found.
     */
    private void translateFromMorseCode(Node<Character> localRoot, StringBuilder sb, String input) throws MorseCodeException {
        if (localRoot.left == null && localRoot.right == null) {
            // Error - traversal attempts to continue through a leaf node
            throw new MorseCodeException("Invalid token length.");
        }
        else if (input.length() == 1) {
            // Final character determines the node at which the decoded letter is found
            if (input.charAt(0) == '*') {
                sb.append(localRoot.left.data);
            }
            else if (input.charAt(0) == '-') {
                sb.append(localRoot.right.data);
            }
            else {
                throw new MorseCodeException("Invalid character: " + input.charAt(0));
            }
        }
        else {
            // Continue traversal
            if (input.charAt(0) == '*') {
                translateFromMorseCode(localRoot.left, sb, input.substring(1));
            }
            else if (input.charAt(0) == '-') {
                translateFromMorseCode(localRoot.right, sb, input.substring(1));
            }
            else {
                throw new MorseCodeException("Invalid character: " + input.charAt(0));
            }
        }
    }

} // End of class MorseCodeTree