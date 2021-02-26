package edu.miracosta.cs113;

import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 * MorseCodeTreeTest : Tester class for MorseCodeTree, specifically for its translateFromMorseCode method and
 * related exceptional input cases.
 *
 * @author King
 * @version 1.0
 */
public class MorseCodeTreeTest {

    public static final String[] SINGLES_CODE = {"*-", "-***", "-*-*",     // a, b, c
                                                    "-**", "*", "**-*",    // d, e, f
                                                    "--*", "****", "**",   // g, h, i
                                                    "*---", "-*-", "*-**", // j, k, l
                                                    "--", "-*", "---",     // m, n, o
                                                    "*--*", "--*-", "*-*", // p, q, r
                                                    "***", "-", "**-",     // s, t, u
                                                    "***-", "*--", "-**-", // v, w, x
                                                    "-*--", "--**"};       // y, z

    public static final String[] SINGLES_DECODED = {"a", "b", "c", "d", "e", "f",
                                                    "g", "h", "i", "j", "k", "l",
                                                    "m", "n", "o", "p", "q", "r",
                                                    "s", "t", "u", "v", "w", "x",
                                                    "y", "z"};

    public static final String[] MULTIPLES_CODE = {"-*- ** -* --*",
                                                    "**** * *-** *-** --- *-- --- *-* *-** -**",
                                                    "*- --* --- --- -** * -**- *- -- *--* *-** *",
                                                    "-*-* *** --- -* * - **** ** *-* - * * -*",
                                                    "- **** -**- -*-* *-* -*-- *--* - ** ** -** --- - -*-* --- --",
                                                    "**** *- ***- * *- *-** --- ***- * *-** -*-- -** *- -*--"};

    public static final String[] MULTIPLES_DECODED = {"king",
                                                        "helloworld",
                                                        "agoodexample",
                                                        "csonethirteen",
                                                        "thxcryptiidotcom",
                                                        "havealovelyday"};

    public static final String[] ERROR_CODE = {"***** ----- -*-*-", // No invalid characters- but tokens are too long
                                                "*- -*** -**---",   // to represent any letter value.
                                                "-.-. ... -.. .--",
                                                "*- invalid characters",
                                                "throws a MorseCodeException"};

    MorseCodeTree mct;

    /**
     * Instantiates the MorseCodeTree object prior to every test.
     */
    @Before
    public void setUp() {
        mct = new MorseCodeTree();
    }

    /**
     * Helper method compares an array of morse code entries with an array of its corresponding English letter
     * translation.
     * Assumes that the two arrays are of equal length and the elements of morseCode match those of
     * expectedDecodedValue after passing it through the MorseCodeTree method translateFromMorseCode.
     *
     * @param morseCode The array of morse code values, using '*' for dots and '-' for dashes and is delimited
     *                  from each letter with a space.
     * @param expectedDecodedValue The array of English letter values expected after translating the values in
     *                             morseCode at the same indexes.
     */
    public void compareDecodedValues(String[] morseCode, String[] expectedDecodedValue) {
        try {
            for (int i = 0; i < morseCode.length; i++) {
                String actualDecodedValue = mct.translateFromMorseCode(morseCode[i]);
                assertEquals("Failure at array index " + i, expectedDecodedValue[i], actualDecodedValue);
            }
        }
        catch (MorseCodeException mce) {
            fail("Test failed - MorseCodeException was thrown.");
        }
    }

    /**
     * Tests the decoding for every morse code value which represents a single letter from A-Z using '*' for dots
     * and '-' for dashes.
     */
    @Test
    public void singleLettersTest() {
        compareDecodedValues(SINGLES_CODE, SINGLES_DECODED);
    }

    /**
     * Tests for entries containing a series of morse code values, each representing a single letter value with
     * dots ('*') and dashes ('-') and delimited from each other using spaces.
     * For example, the entry "*- -*** -*-*" will return "abc" if the MorseCodeTree has been built properly.
     */
    @Test
    public void multipleLettersTest() {
        compareDecodedValues(MULTIPLES_CODE, MULTIPLES_DECODED);
    }

    /**
     * Tests for cases in which a MorseCodeTreeException is thrown, namely through errors in the input of morse code
     * tokens which are intended to represent a single letter value.
     * Such errors include containing invalid characters (anything that isn't '*' or '-') or having a length which
     * exceeds the height of the MorseCodeTree - 1 (causing the traversal to exceed the bounds of the leaf nodes).
     */
    @Test
    public void testErrors() {
        for (String errorCode : ERROR_CODE) {
            try {
                mct.translateFromMorseCode(errorCode);
                fail("Test failed - " + errorCode + " must prompt a MorseCodeException to be thrown.");
            }
            catch (MorseCodeException mce) {
                // Exception thrown from translateFromMorseCode as intended.
                System.out.println(mce.getMessage());
            }
        }
    }

} // End of class MorseCodeTreeTest