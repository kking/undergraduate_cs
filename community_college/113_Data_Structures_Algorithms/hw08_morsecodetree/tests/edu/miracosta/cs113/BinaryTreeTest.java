package edu.miracosta.cs113;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

import java.util.Scanner;

/**
 * BinaryTreeTest : Tester class for generic BinaryTree class implementation.
 *
 * @author King
 * @version 1.0
 */
public class BinaryTreeTest {

    public static final String[] STRING_DATA = {"all one branch",
                                                "alpha", "bravo", "charlie",
                                                "this", "is", "a", "test"};
    public static final String[] EXPECTED_DATA = {"all\n one\n  branch\n   null\n   null\n  null\n null\n",
                                                    "charlie\n alpha\n  null\n  null\n bravo\n  null\n  null\n",
                                                    "ok"};

    public BinaryTree<String> leftTree, fullTree, completeTree;

    @Test
    public void testAllLeftTree() {
        leftTree = BinaryTree.readBinaryTree(new Scanner(STRING_DATA[0]));
        assertEquals(EXPECTED_DATA[0], leftTree.toString());
    }

    @Test
    public void testFullTree() {
        BinaryTree<String> left = new BinaryTree<String>(STRING_DATA[1], new BinaryTree<String>(), new BinaryTree<String>());
        BinaryTree<String> right = new BinaryTree<String>(STRING_DATA[2], new BinaryTree<String>(), new BinaryTree<String>());

        fullTree = new BinaryTree<String>(STRING_DATA[3], left, right);

        assertEquals(EXPECTED_DATA[1], fullTree.toString());
    }

    @Test
    public void testCompleteTree() {
        BinaryTree<String> left = new BinaryTree<String>(STRING_DATA[4], new BinaryTree<String>(new BinaryTree<String>(STRING_DATA[5], null, null)), new BinaryTree<String>());
        BinaryTree<String> right = new BinaryTree<String>(STRING_DATA[6], new BinaryTree<String>(), new BinaryTree<String>());

        completeTree = new BinaryTree<String>(STRING_DATA[7], left, right);

        assertEquals(EXPECTED_DATA[2], completeTree.toString());
    }

} // End of class BinaryTreeTest