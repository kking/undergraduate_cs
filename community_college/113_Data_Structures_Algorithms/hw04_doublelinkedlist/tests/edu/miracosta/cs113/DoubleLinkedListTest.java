package edu.miracosta.cs113;

import org.junit.Before;
import org.junit.Test;

import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Iterator;

import java.util.NoSuchElementException;

import static org.junit.Assert.*;

public class DoubleLinkedListTest {

    private static final String[] STRING_VALUES = {"first", "second", "third", "fourth" , "fifth"};
    private static final int[] INT_VALUES = {100, 200, 300, 400, 500};
    private static final char[] CHAR_VALUES = {'A', 'B', 'C', 'D', 'E'};
    private static final double[] DOUBLE_VALUES = {1.1, 2.2, 3.3, 4.4, 5.5};

    private static final String TO_STRING_EMPTY = "[]";
    private static final String[] TO_STRING_ADD1 = { "[first]",
                                                    "[100]",
                                                    "[A]",
                                                    "[1.1]"};
    private static final String[] TO_STRING_ADD3 = { "[first, second, third]",
                                                    "[100, 200, 300]",
                                                    "[A, B, C]",
                                                    "[1.1, 2.2, 3.3]"};

    private static final String STRING_INSERT_VAL = "w00t";
    private static final int INT_INSERT_VAL = 555;
    private static final char CHAR_INSERT_VAL = 'X';
    private static final double DOUBLE_INSERT_VAL = -3.14;

    private static final int STRING_INSERT_INDEX = 0, INT_INSERT_INDEX = 1, CHAR_INSERT_INDEX = 2, DOUBLE_INSERT_INDEX = 3;
    private static final String[] TO_STRING_INSERT = { "[w00t, first, second, third]",
                                                    "[100, 555, 200, 300]",
                                                    "[A, B, X, C]",
                                                    "[1.1, 2.2, 3.3, -3.14]"};

    private List<String> stringList;
    private List<Integer> intList;
    private List<Character> charList;
    private List<Double> doubleList;

    private ListIterator<String> stringIterator;
    private ListIterator<Integer> intIterator;
    private ListIterator<Character> charIterator;
    private ListIterator<Double> doubleIterator;

    /* HELPER METHODS */
    public void buildLists(int num) {
         for (int i = 0; i < num; i++) {
            stringList.add(STRING_VALUES[i]);
            intList.add(INT_VALUES[i]);
            charList.add(CHAR_VALUES[i]);
            doubleList.add(DOUBLE_VALUES[i]);
        }
    }

    /**
     * with the @Before tag, this method will called before EVERY SINGLE @Test method that runs
     */
    @Before
    public void setUp() {
        stringList = new DoubleLinkedList<String>();
        intList = new DoubleLinkedList<Integer>();
        charList = new DoubleLinkedList<Character>();
        doubleList = new DoubleLinkedList<Double>();
    }
    @Test
    public void testNewLinkedListBySize() {
        assertTrue("String list should start as empty", stringList.isEmpty());
        assertTrue("Integer list should start as empty", intList.isEmpty());
        assertTrue("Character list should start as empty", charList.isEmpty());
        assertTrue("Double list should start as empty", doubleList.isEmpty());
    }

    @Test
    public void testAddingOneBySize() {
        buildLists(1);

        assertEquals("String list should have size of 1", 1, stringList.size());
        assertEquals("Integer list should have size of 1", 1, intList.size());
        assertEquals("Character list should have size of 1", 1, charList.size());
        assertEquals("Double list should have size of 1", 1, doubleList.size());
    }

    @Test
    public void testAddingThreeBySize() {
        buildLists(3);

        assertEquals("String list should have size of 3", 3, stringList.size());
        assertEquals("Integer list should have size of 3", 3, intList.size());
        assertEquals("Character list should have size of 3", 3, charList.size());
        assertEquals("Double list should have size of 3", 3, doubleList.size());
    }

    @Test
    public void testNewLinkedListByToString() {
        assertEquals("String list expected toString doesn't match actual", TO_STRING_EMPTY, stringList.toString());
        assertEquals("Integer list expected toString doesn't match actual", TO_STRING_EMPTY, intList.toString());
        assertEquals("Character list expected toString doesn't match actual", TO_STRING_EMPTY, charList.toString());
        assertEquals("Double list expected toString doesn't match actual", TO_STRING_EMPTY, doubleList.toString());
    }

    @Test
    public void testAddingOneByToString() {
        buildLists(1);

        assertEquals("String list expected toString doesn't match actual", TO_STRING_ADD1[0], stringList.toString());
        assertEquals("Integer list expected toString doesn't match actual", TO_STRING_ADD1[1], intList.toString());
        assertEquals("Character list expected toString doesn't match actual", TO_STRING_ADD1[2], charList.toString());
        assertEquals("Double list expected toString doesn't match actual", TO_STRING_ADD1[3], doubleList.toString());
    }

    @Test
    public void testAddingThreeByToString() {
        buildLists(3);

        assertEquals("String list expected toString doesn't match actual", TO_STRING_ADD3[0], stringList.toString());
        assertEquals("Integer list expected toString doesn't match actual", TO_STRING_ADD3[1], intList.toString());
        assertEquals("Character list expected toString doesn't match actual", TO_STRING_ADD3[2], charList.toString());
        assertEquals("Double list expected toString doesn't match actual", TO_STRING_ADD3[3], doubleList.toString());
    }

    @Test
    public void testInsertingByToString() {
        buildLists(3);

        stringList.add(STRING_INSERT_INDEX,  STRING_INSERT_VAL);
        intList.add(INT_INSERT_INDEX,  INT_INSERT_VAL);
        charList.add(CHAR_INSERT_INDEX,  CHAR_INSERT_VAL);
        doubleList.add(DOUBLE_INSERT_INDEX,  DOUBLE_INSERT_VAL);

        assertEquals("String list expected toString doesn't match actual", TO_STRING_INSERT[0], stringList.toString());
        assertEquals("Integer list expected toString doesn't match actual", TO_STRING_INSERT[1], intList.toString());
        assertEquals("Character list expected toString doesn't match actual", TO_STRING_INSERT[2], charList.toString());
        assertEquals("Double list expected toString doesn't match actual", TO_STRING_INSERT[3], doubleList.toString());
    }

    @Test
    public void testClear() {
        buildLists(3);

        assertEquals("String list should have size of 3", 3, stringList.size());
        assertEquals("Integer list should have size of 3", 3, intList.size());
        assertEquals("Character list should have size of 3", 3, charList.size());
        assertEquals("Double list should have size of 3", 3, doubleList.size());

        stringList.clear();
        intList.clear();
        charList.clear();
        doubleList.clear();

        assertTrue("String list should be empty", stringList.isEmpty());
        assertTrue("Integer list should be empty", intList.isEmpty());
        assertTrue("Character list should be empty", charList.isEmpty());
        assertTrue("Double list should be empty", doubleList.isEmpty());
    }

    @Test
    public void testEquals() {
        buildLists(5);

        List<String> stringListJava = new LinkedList<String>();
        List<Integer> intListJava = new LinkedList<Integer>();
        List<Character> charListJava = new LinkedList<Character>();
        List<Double> doubleListJava = new LinkedList<Double>();

        for(int i = 0; i < 5; i++) {
            stringListJava.add(STRING_VALUES[i]);
            intListJava.add(INT_VALUES[i]);
            charListJava.add(CHAR_VALUES[i]);
            doubleListJava.add(DOUBLE_VALUES[i]);
        }

        assertEquals("Expected String list (java.util.LinkedList) and Actual String list (your implementation) don't match", stringListJava, stringList);
        assertEquals("Expected Integer list (java.util.LinkedList) and Actual Integer list (your implementation) don't match", intListJava, intList);
        assertEquals("Expected Character list (java.util.LinkedList) and Actual Character list (your implementation) don't match", charListJava, charList);
        assertEquals("Expected Double list (java.util.LinkedList) and Actual Double list (your implementation) don't match", doubleListJava, doubleList);
    }

    @Test
    public void testContains() {
        buildLists(5);

        assertFalse("Expected value NOT to be in String list, but your code claims it is", stringList.contains(STRING_INSERT_VAL));
        assertFalse("Expected value NOT to be in Integer list, but your code claims it is", intList.contains(INT_INSERT_VAL));
        assertFalse("Expected value NOT to be in Character list, but your code claims it is", charList.contains(CHAR_INSERT_VAL));
        assertFalse("Expected value NOT to be in Double list, but your code claims it is", doubleList.contains(DOUBLE_INSERT_VAL));

        stringList.add(STRING_INSERT_VAL);
        intList.add(INT_INSERT_VAL);
        charList.add(CHAR_INSERT_VAL);
        doubleList.add(DOUBLE_INSERT_VAL);

        assertTrue("Expected value to be in String list, but your code claims it is NOT", stringList.contains(STRING_INSERT_VAL));
        assertTrue("Expected value to be in Integer list, but your code claims it is NOT", intList.contains(INT_INSERT_VAL));
        assertTrue("Expected value to be in Character list, but your code claims it is NOT", charList.contains(CHAR_INSERT_VAL));
        assertTrue("Expected value to be in Double list, but your code claims it is NOT", doubleList.contains(DOUBLE_INSERT_VAL));
    }

    @Test
    public void testGet() {
        buildLists(5);

        assertEquals("Expected value in String list doesn't match get() from your list", STRING_VALUES[3], stringList.get(3));
        assertEquals("Expected value in Integer list doesn't match get() from your list", new Integer(INT_VALUES[3]), intList.get(3));
        assertEquals("Expected value in Character list doesn't match get() from your list", new Character(CHAR_VALUES[3]), charList.get(3));
        assertEquals("Expected value in Double list doesn't match get() from your list", new Double(DOUBLE_VALUES[3]), doubleList.get(3));
    }

    @Test
    public void testGetError() {
        try {
            stringList.get(0);
            fail("String list get() test should have thrown exception for out of bounds (empty list, index == 0)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }

        try {
            intList.get(1);
            fail("Integer list get() test should have thrown exception for out of bounds (empty list, index == 1)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }

        buildLists(5);

        try {
            charList.get(5);
            fail("Character list get() test should have thrown exception for out of bounds (index >= size)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }

        try {
            doubleList.get(-1);
            fail("Double list get() test should have thrown exception for out of bounds (index < 0)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }
    }

    @Test
    public void testIndexOf() {
        buildLists(4);

        assertEquals("Expected value in String list doesn't match indexOf() from your list", 0, stringList.indexOf(STRING_VALUES[0]));
        assertEquals("Expected value in Integer list doesn't match indexOf() from your list", 1, intList.indexOf(INT_VALUES[1]));
        assertEquals("Expected value in Character list doesn't match indexOf() from your list", 2, charList.indexOf(CHAR_VALUES[2]));
        assertEquals("Expected value in Double list doesn't match indexOf() from your list", 3, doubleList.indexOf(DOUBLE_VALUES[3]));
    }

    @Test
    public void testIndexOfRepeats() {
        buildLists(4);

        stringList.add(1, STRING_VALUES[0]);
        stringList.add(5, STRING_VALUES[0]);
        System.out.println("new string list = " + stringList); //leaving these here so you can see the repeated values, indexOf should return the FIRST value
        intList.add(2, INT_VALUES[1]);
        intList.add(5, INT_VALUES[1]);
        System.out.println("new int list = " + intList);
        charList.add(3, CHAR_VALUES[2]);
        charList.add(5, CHAR_VALUES[2]);
        System.out.println("new char list = " + charList);
        doubleList.add(4, DOUBLE_VALUES[3]);
        doubleList.add(5, DOUBLE_VALUES[3]);
        System.out.println("new double list = " + doubleList);

        assertEquals("Expected value in String list doesn't match indexOf() from your list", 0, stringList.indexOf(STRING_VALUES[0]));
        assertEquals("Expected value in Integer list doesn't match indexOf() from your list", 1, intList.indexOf(INT_VALUES[1]));
        assertEquals("Expected value in Character list doesn't match indexOf() from your list", 2, charList.indexOf(CHAR_VALUES[2]));
        assertEquals("Expected value in Double list doesn't match indexOf() from your list", 3, doubleList.indexOf(DOUBLE_VALUES[3]));
    }

    @Test
    public void testLastIndexOf() {
        buildLists(4);

        assertEquals("Expected value in String list doesn't match lastIndexOf() from your list", 0, stringList.lastIndexOf(STRING_VALUES[0]));
        assertEquals("Expected value in Integer list doesn't match lastIndexOf() from your list", 1, intList.lastIndexOf(INT_VALUES[1]));
        assertEquals("Expected value in Character list doesn't match lastIndexOf() from your list", 2, charList.lastIndexOf(CHAR_VALUES[2]));
        assertEquals("Expected value in Double list doesn't match lastIndexOf() from your list", 3, doubleList.lastIndexOf(DOUBLE_VALUES[3]));
    }

    @Test
    public void testLastIndexOfRepeats1() {
        buildLists(4);

        stringList.add(1, STRING_VALUES[0]);
        System.out.println("new string list = " + stringList); //leaving these here so you can see the repeated values, indexOf should return the FIRST value
        intList.add(2, INT_VALUES[1]);
        System.out.println("new int list = " + intList);
        charList.add(3, CHAR_VALUES[2]);
        System.out.println("new char list = " + charList);
        doubleList.add(4, DOUBLE_VALUES[3]);
        System.out.println("new double list = " + doubleList);

        assertEquals("Expected value in String list doesn't match lastIndexOf() from your list", 1, stringList.lastIndexOf(STRING_VALUES[0]));
        assertEquals("Expected value in Integer list doesn't match lastIndexOf() from your list", 2, intList.lastIndexOf(INT_VALUES[1]));
        assertEquals("Expected value in Character list doesn't match lastIndexOf() from your list", 3, charList.lastIndexOf(CHAR_VALUES[2]));
        assertEquals("Expected value in Double list doesn't match lastIndexOf() from your list", 4, doubleList.lastIndexOf(DOUBLE_VALUES[3]));
    }

    @Test
    public void testLastIndexOfRepeats2() {
        buildLists(4);

        stringList.add(4, STRING_VALUES[0]);
        System.out.println("new string list = " + stringList); //leaving these here so you can see the repeated values, indexOf should return the FIRST value
        intList.add(4, INT_VALUES[1]);
        System.out.println("new int list = " + intList);
        charList.add(4, CHAR_VALUES[2]);
        System.out.println("new char list = " + charList);
        doubleList.add(4, DOUBLE_VALUES[3]);
        System.out.println("new double list = " + doubleList);

        assertEquals("Expected value in String list doesn't match lastIndexOf() from your list", 4, stringList.lastIndexOf(STRING_VALUES[0]));
        assertEquals("Expected value in Integer list doesn't match lastIndexOf() from your list", 4, intList.lastIndexOf(INT_VALUES[1]));
        assertEquals("Expected value in Character list doesn't match lastIndexOf() from your list", 4, charList.lastIndexOf(CHAR_VALUES[2]));
        assertEquals("Expected value in Double list doesn't match lastIndexOf() from your list", 4, doubleList.lastIndexOf(DOUBLE_VALUES[3]));
    }

    @Test
    public void testErrorsIndexOfLastIndexOf() {
        buildLists(5);

        assertEquals("Expected value in String list doesn't match indexOf() from your list", -1, stringList.indexOf(STRING_INSERT_VAL));
        assertEquals("Expected value in Integer list doesn't match indexOf() from your list", -1, intList.indexOf(INT_INSERT_VAL));
        assertEquals("Expected value in Character list doesn't match indexOf() from your list", -1, charList.indexOf(CHAR_INSERT_VAL));
        assertEquals("Expected value in Double list doesn't match indexOf() from your list", -1, doubleList.indexOf(DOUBLE_INSERT_VAL));

        assertEquals("Expected value in String list doesn't match lastIndexOf() from your list", -1, stringList.lastIndexOf(STRING_INSERT_VAL));
        assertEquals("Expected value in Integer list doesn't match lastIndexOf() from your list", -1, intList.lastIndexOf(INT_INSERT_VAL));
        assertEquals("Expected value in Character list doesn't match lastIndexOf() from your list", -1, charList.lastIndexOf(CHAR_INSERT_VAL));
        assertEquals("Expected value in Double list doesn't match lastIndexOf() from your list", -1, doubleList.lastIndexOf(DOUBLE_INSERT_VAL));

    }

    @Test
    public void testRemoveByIndex() {
        buildLists(5);

        assertEquals("Remove from String list was not successful, removed wrong value", STRING_VALUES[0], stringList.remove(0));
        assertEquals("Remove from Integer list was not successful, removed wrong value", new Integer(INT_VALUES[1]), intList.remove(1));
        assertEquals("Remove from Character list was not successful, removed wrong value", new Character(CHAR_VALUES[2]), charList.remove(2));
        assertEquals("Remove from Double list was not successful, removed wrong value", new Double(DOUBLE_VALUES[3]), doubleList.remove(3));
    }

    @Test
    public void testRemoveByValue() {
        buildLists(3);

        stringList.add(STRING_INSERT_INDEX,  STRING_INSERT_VAL);
        intList.add(INT_INSERT_INDEX,  INT_INSERT_VAL);
        charList.add(CHAR_INSERT_INDEX,  CHAR_INSERT_VAL);
        doubleList.add(DOUBLE_INSERT_INDEX,  DOUBLE_INSERT_VAL);

        System.out.println("before remove, string list = " + stringList); //leaving these here so you can see the lists before remove
        System.out.println("before remove, int list = " + intList);
        System.out.println("before remove, char list = " + charList);
        System.out.println("before remove, double list = " + doubleList);

        assertEquals("String list expected toString doesn't match actual", TO_STRING_INSERT[0], stringList.toString());
        assertEquals("Integer list expected toString doesn't match actual", TO_STRING_INSERT[1], intList.toString());
        assertEquals("Character list expected toString doesn't match actual", TO_STRING_INSERT[2], charList.toString());
        assertEquals("Double list expected toString doesn't match actual", TO_STRING_INSERT[3], doubleList.toString());

        assertTrue("String list remove returned false when value is actually present in list", stringList.remove(STRING_INSERT_VAL));
        assertTrue("Integer list remove returned false when value is actually present in list", intList.remove(new Integer(INT_INSERT_VAL)));
        assertTrue("Character list remove returned false when value is actually present in list", charList.remove(new Character(CHAR_INSERT_VAL)));
        assertTrue("Double list remove returned false when value is actually present in list", doubleList.remove(DOUBLE_INSERT_VAL));

        System.out.println("\nafter remove, string list = " + stringList); //leaving these here so you can see the lists after remove
        System.out.println("after remove, int list = " + intList);
        System.out.println("after remove, char list = " + charList);
        System.out.println("after remove, double list = " + doubleList);

        assertEquals("String list expected toString doesn't match actual, incorrect value removed", TO_STRING_ADD3[0], stringList.toString());
        assertEquals("Integer list expected toString doesn't match actual, incorrect value removed", TO_STRING_ADD3[1], intList.toString());
        assertEquals("Character list expected toString doesn't match actual, incorrect value removed", TO_STRING_ADD3[2], charList.toString());
        assertEquals("Double list expected toString doesn't match actual, incorrect value removed", TO_STRING_ADD3[3], doubleList.toString());
    }

    @Test
    public void testRemoveErrors() {
        buildLists(3);

        //check for exceptions by remove(int)
        try {
            stringList.remove(3);
            fail("String list remove() test should have thrown exception for out of bounds (index >= size)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }

        try {
            intList.remove(-1);
            fail("Integer list remove() test should have thrown exception for out of bounds (index < 0)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }

        //check for false by remove(Object)
        assertFalse("Character list remove returned true when value is NOT present in list", charList.remove(new Character(CHAR_INSERT_VAL)));
        assertFalse("Double list remove returned true when value is NOT present in list", doubleList.remove(DOUBLE_INSERT_VAL));
    }

    @Test
    public void testSet() {
        buildLists(5);

        stringList.set(STRING_INSERT_INDEX,  STRING_INSERT_VAL);
        intList.set(INT_INSERT_INDEX,  INT_INSERT_VAL);
        charList.set(CHAR_INSERT_INDEX,  CHAR_INSERT_VAL);
        doubleList.set(DOUBLE_INSERT_INDEX,  DOUBLE_INSERT_VAL);

        assertEquals("Expected value in String list doesn't match get() from your list", STRING_INSERT_VAL, stringList.get(STRING_INSERT_INDEX));
        assertEquals("Expected value in Integer list doesn't match get() from your list", new Integer(INT_INSERT_VAL), intList.get(INT_INSERT_INDEX));
        assertEquals("Expected value in Character list doesn't match get() from your list", new Character(CHAR_INSERT_VAL), charList.get(CHAR_INSERT_INDEX));
        assertEquals("Expected value in Double list doesn't match get() from your list", new Double(DOUBLE_INSERT_VAL), doubleList.get(DOUBLE_INSERT_INDEX));
    }

    @Test
    public void testSetError() {
        try {
            stringList.set(0, STRING_INSERT_VAL);
            fail("String list get() test should have thrown exception for out of bounds (empty list, index == 0)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }

        try {
            intList.set(1,  INT_INSERT_VAL);
            fail("Integer list get() test should have thrown exception for out of bounds (empty list, index == 1)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }

        buildLists(5);

        try {
            charList.set(5,  CHAR_INSERT_VAL);
            fail("Character list get() test should have thrown exception for out of bounds (index >= size)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }

        try {
            doubleList.set(-1,  DOUBLE_INSERT_VAL);
            fail("Double list get() test should have thrown exception for out of bounds (index < 0)");
        } catch (IndexOutOfBoundsException ioobe) { /*Test Passed*/ }
    }

    /**
     * Unit tests for the ListIterator methods
     */

    @Test
    public void testIteratorConstructors() {
        // Tests for iterators created for an empty list or at an index out of bounds
        buildLists(5);

        try {
            stringIterator = stringList.listIterator(-1);
            fail("Test failed - Invalid index (< 0) must throw an IndexOutOfBoundsException.");
        }
        catch (IndexOutOfBoundsException ioobe) { /* Test passed */ }

        try {
            intIterator = intList.listIterator(6);
            fail("Test failed - Invalid index ( > size) must throw an IndexOutOfBoundsException.");
        }
        catch (IndexOutOfBoundsException ioobe) { /* Test passed */ }

        charIterator = charList.listIterator(); // Beginning of list
        doubleIterator = doubleList.listIterator(5); // End of list

        stringList.clear();
        stringIterator = stringList.listIterator(); // Empty list
    }

    @Test
    public void testIteratorRemove() {
        buildLists(5);

        stringIterator = stringList.listIterator(5);
        intIterator = intList.listIterator();
        charIterator = charList.listIterator(2);
        doubleIterator = doubleList.listIterator();

        System.out.println("String list before removal: " + stringList);
        stringIterator.previous();
        stringIterator.remove();
        System.out.println("String list after removal: " + stringList);
        assertFalse("Test failed - Element at end of list was not removed.", stringList.contains(STRING_VALUES[4]));

        System.out.println("Int list before removal: " + intList);
        intIterator.next();
        intIterator.remove();
        System.out.println("Int list after removal: " + intList);
        assertFalse("Test failed - Element at beginning of list was not removed.", intList.contains(INT_VALUES[0]));

        System.out.println("Char list before removal: " + charList);
        charIterator.next();
        charIterator.remove();
        System.out.println("Char list after removal: " + charList);
        assertFalse("Test failed - Element in middle of list was not removed.", charList.contains(CHAR_VALUES[2]));

        try {
            System.out.println("Double list before removal: " + doubleList);
            doubleIterator.remove();
            fail("Test failed - IllegalStateException expected without prior call to next or previous.");
        }
        catch (IllegalStateException ise) {
            System.out.println("Double list as unaffected by removal: " + doubleList);
        }

        System.out.println();
    }

    @Test
    public void testIteratorAdd() {
        stringList.add(STRING_VALUES[1]);
        stringList.add(STRING_VALUES[2]);
        stringIterator = stringList.listIterator();
        stringIterator.add(STRING_VALUES[0]);
        assertEquals("Test failed - Incorrect add to beginning of list.", TO_STRING_ADD3[0], stringList.toString());

        intList.add(INT_VALUES[0]);
        intList.add(INT_VALUES[1]);
        intIterator = intList.listIterator(2);
        intIterator.add(INT_VALUES[2]);
        assertEquals("Test failed - Incorrect add to end of list.", TO_STRING_ADD3[1], intList.toString());

        charList.add(CHAR_VALUES[0]);
        charList.add(CHAR_VALUES[2]);
        charIterator = charList.listIterator(1);
        charIterator.add(CHAR_VALUES[1]);
        assertEquals("Test failed - Incorrect add to middle of list.", TO_STRING_ADD3[2], charList.toString());

        // Empty list
        doubleIterator = doubleList.listIterator();
        doubleIterator.add(DOUBLE_VALUES[0]);
        assertEquals("Test failed - Incorrect add to empty list.", TO_STRING_ADD1[3], doubleList.toString());
    }

    @Test
    public void testIteratorSet() {
        buildLists(4);

        stringIterator = stringList.listIterator(4);
        intIterator = intList.listIterator();
        charIterator = charList.listIterator(2);
        doubleIterator = doubleList.listIterator();

        System.out.println("String list before set: " + stringList);
        stringIterator.previous();
        stringIterator.set(STRING_VALUES[4]);
        System.out.println("String list after set: " + stringList);
        assertEquals("Test failed - Unexpected value after setting last element.", STRING_VALUES[4], stringList.get(3));

        System.out.println("Int list before set: " + intList);
        intIterator.next();
        intIterator.set(INT_VALUES[4]);
        System.out.println("Int list after set: " + intList);
        assertEquals("Test failed - Unexpected value after setting first element.", new Integer(INT_VALUES[4]), intList.get(0));

        System.out.println("Char list before set: " + charList);
        charIterator.next();
        charIterator.set(CHAR_VALUES[4]);
        System.out.println("Char list after set: " + charList);
        assertEquals("Test failed - Unexpected value after setting third element.", new Character(CHAR_VALUES[4]), charList.get(2));

        try {
            System.out.println("Double list before set: " + doubleList);
            doubleIterator.set(DOUBLE_VALUES[4]);
            fail("Test failed - IllegalStateException expected without prior call to next or previous.");
        }
        catch (IllegalStateException ise) {
            System.out.println("Double list as unaffected by set: " + doubleList);
        }

        System.out.println();
    }

    @Test
    public void testIteratorHasNext() {
        buildLists(5);
        doubleList.clear();

        assertFalse("Test failed - Iterator at the end of the list, hasNext must return false.", stringList.listIterator(5).hasNext());
        assertTrue("Test failed - Iterator at the beginning of list, hasNext must return true.", intList.listIterator().hasNext());
        assertTrue("Test failed - Iterator at middle of the list; hasNext must return true.", charList.listIterator(2).hasNext());
        assertFalse("Test failed - Iterator for an empty list; hasNext must return false.", doubleList.listIterator().hasNext());
    }

    @Test
    public void testIteratorHasPrevious() {
        buildLists(5);
        doubleList.clear();

        assertFalse("Test failed - Iterator at the beginning of the list; hasPrevious must return false.", stringList.listIterator().hasPrevious());
        assertTrue("Test failed - Iterator at the end of the list; hasPrevious must return true.", intList.listIterator(5).hasPrevious());
        assertTrue("Test failed - Iterator at middle of the list; hasPrevious must return true.", charList.listIterator(2).hasPrevious());
        assertFalse("Test failed - Iterator for an empty list. ", doubleList.listIterator().hasPrevious());
    }

    @Test
    public void testIteratorNext() {
        buildLists(3);

        assertEquals("Test failed - the expected first element was not returned by next.", STRING_VALUES[0], stringList.listIterator().next());
        assertEquals("Test failed - the expected second element was not returned by next.", new Integer(INT_VALUES[1]), intList.listIterator(1).next());
        assertEquals("Test failed - the expected last element was not returned by next.", new Character(CHAR_VALUES[2]), charList.listIterator(2).next());

        try {
            charList.listIterator(3).next();
            fail("Test failed - Iterator at the end of the list should throw NoSuchElementException when calling next.");
        } catch (NoSuchElementException nsee) { /* Test passed */ }

        stringList.clear();

        try {
            stringList.listIterator().next();
            fail("Test failed - Iterator for an empty list throws NoSuchElementException.");
        } catch (NoSuchElementException nsee) { /* Test passed */ }
    }

    @Test
    public void testIteratorNextIndex() {
        buildLists(5);

        assertEquals("Test failed - Unexpected next index value at beginning of list.", 1, stringList.listIterator().nextIndex());
        assertEquals("Test failed - Unexpected next index value at the end of the list.", 5, intList.listIterator(4).nextIndex());
        assertEquals("Test failed - Unexpected next index value at middle of the list.", 3, charList.listIterator(2).nextIndex());
        assertEquals("Test failed - Iterator at the end of the list must return size as next index.", 5, doubleList.listIterator(5).nextIndex());
    }

    @Test
    public void testIteratorPrevious() {
        buildLists(3);

        assertEquals("Test failed - the expected last element was not returned by previous.", STRING_VALUES[2], stringList.listIterator(3).previous());
        assertEquals("Test failed - the expected first element was not returned by previous.", new Integer(INT_VALUES[0]), intList.listIterator(1).previous());
        assertEquals("Test failed - the expected second element was not returned by previous.", new Character(CHAR_VALUES[1]), charList.listIterator(2).previous());

        try {
            charList.listIterator().previous(); //
            fail("Test failed - Iterator must throw NoSuchElementException if at beginning of list.");
        }
        catch (NoSuchElementException nsee) { /* Test passed */ }

        stringList.clear();
        try {
            stringList.listIterator().previous();
            fail("Test failed - call to en empty list throws NoSuchElementException.");
        } catch (NoSuchElementException nsee) { /* Test passed */ }
    }

    @Test
    public void testIteratorPreviousIndex() {
        buildLists(5);

        assertEquals("Test failed - Unexpected previous index value at beginning of list.", -1, stringList.listIterator().previousIndex());
        assertEquals("Test failed - Unexpected previous index value at the end of the list.", 4, intList.listIterator(5).previousIndex());
        assertEquals("Test failed - Unexpected previous index value at middle of the list.", 1, charList.listIterator(2).previousIndex());
        // assertEquals("Test failed - Unexpected previous index value at middle of the list.", 2, doubleList.listIterator(3).previousIndex());
    }

} // End of class DoubleLinkedListTest