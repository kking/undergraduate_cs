package edu.miracosta.cs113;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * MorseCodeTreeDriver : Driver menu program demonstrating the building of a MorseCodeTree which allows the user to
 * translate morse code values received from a text file or console input.
 *
 * @author King
 * @version 1.0
 */
public class MorseCodeTreeDriver {

    public static Scanner keyboard = new Scanner(System.in);

    public static final String[] SINGLE_LETTERS = {"*-", "-***", "-*-*",   // a, b, c
                                                    "-**", "*", "**-*",    // d, e, f
                                                    "--*", "****", "**",   // g, h, i
                                                    "*---", "-*-", "*-**", // j, k, l
                                                    "--", "-*", "---",     // m, n, o
                                                    "*--*", "--*-", "*-*", // p, q, r
                                                    "***", "-", "**-",     // s, t, u
                                                    "***-", "*--", "-**-", // v, w, x
                                                    "-*--", "--**"};       // y, z

    /**
     * Driver menu program builds a MorseCodeTree and asks the user if they would want to:
     * 1. Test output for all morse code letters with their respective translated alphabet letters
     * 2. Enter an input text file name containing morse code to decode and output the translated text to the console
     * 3. Enter a line of morse code to decode morse code and output the translated test through the console
     * 4. Exit the program
     *
     * @param args not used in driver method
     */
    public static void main(String[] args) {

        String menu = "<1> Test output for decoding all morse code letters \n" +
                        "<2> Decode morse code from a text file \n" +
                        "<3> Decode morse code from console input \n" +
                        "<4> Exit program \n";
        boolean runProgram = true;

        MorseCodeTree treeTest = new MorseCodeTree();

        while (runProgram) {
            System.out.println(menu);
            try {
                switch (keyboard.nextInt()) {
                    case 1:
                        System.out.println(testOutput(treeTest));
                        break;
                    case 2:
                        System.out.println(decodeTextFile(treeTest));
                        break;
                    case 3:
                        System.out.println(decodeConsoleInput(treeTest));
                        break;
                    case 4:
                        keyboard.close();
                        runProgram = false;
                        break;
                    default:
                        System.out.println("Invalid menu input. Try again. \n");
                        break;
                }
            }
            catch (InputMismatchException ime) {
                System.out.println("Invalid menu input. Try again. \n");
                keyboard.nextLine();
            }
            catch (FileNotFoundException fnfe) {
                System.out.println(fnfe.getMessage() + "\n");
            }

        } // End of while loop

    } // End of main method

    /**
     * Tests output for decoding all morse code letters in alphabetical order using the given MorseCodeTree.
     *
     * @param mct The MorseCodeTree object
     * @return a String listing each letter followed by its morse code value in alphabetical order
     */
    public static String testOutput(MorseCodeTree mct) {
        StringBuilder sb = new StringBuilder();
        try {
            //
            for (String morseCode : SINGLE_LETTERS) {
                sb.append(mct.translateFromMorseCode(morseCode)); // Append translated letter
                sb.append(" ").append(morseCode).append("\n"); // Append original morse code value, start new line
            }
            return sb.toString(); // Return list of each letter followed by its morse code value
        }
        catch (MorseCodeException mce) {
            return mce.getMessage(); // Unexpected error has occurred - return MorseCodeException message
        }
    }

    /**
     * Prompts the user to enter an existing text file containing only morse code letter values, using '*' to represent
     * dots and '-' for dashes, delimited from each other by spaces. The file's data will be processed through the
     * MorseCodeTree's translateFromMorseCode method to return its decoded message.
     *
     * @param mct The MorseCodeTree object
     * @return a String representing the translation of morse code values received from a text file
     * @throws FileNotFoundException if the given text file does not exist
     */
    public static String decodeTextFile(MorseCodeTree mct) throws FileNotFoundException {
        // Receiving text file path specified by the user
        System.out.println("Enter file name: ");
        keyboard.nextLine();
        File morseTextFile = new File(keyboard.nextLine());
        if (! morseTextFile.exists()) {
            throw new FileNotFoundException(morseTextFile + " not found.");
        }

        Scanner scan = new Scanner(morseTextFile); // Scanner for reading given text file
        StringBuilder translatedText = new StringBuilder(); // StringBuilder appends values for each translated token
        String output; // May be set to the result of above StringBuilder, or a MorseCodeException message

        try {
            while (scan.hasNextLine()) {
                // Appending translated result of the current line of morse code values
                translatedText.append(mct.translateFromMorseCode(scan.nextLine())).append("\n");
            }
            output = translatedText.toString();
        }
        catch (MorseCodeException mce) {
            output = mce.getMessage();
        }

        scan.close();
        return output;
    }

    /**
     * Prompts the user to enter morse code values to be translated and returned through the console. Using rhw
     * given MorseCodeTree's translateFromMorseCode method, input received from the console must represent morse
     * code letters (using dots '*' and dashes '-') delimited from each other by spaces in order to be properly
     * decoded.
     *
     * @param mct The MorseCodeTree object
     * @return a String representing the translation of morse code values received from the console
     */
    public static String decodeConsoleInput(MorseCodeTree mct) {
        keyboard.nextLine();
        System.out.println("Enter a series of morse code values (dot = *, dash = -), " +
                            "representing letters only, delimited from each other by spaces: ");

        String input = keyboard.nextLine();
        try {
            return mct.translateFromMorseCode(input) + "\n"; // Returns translation of given morse code
        }
        catch (MorseCodeException mce) {
            return mce.getMessage() + "\n"; // Returns error message pertaining to erroneous input
        }
    }

} // End of class MorseCodeTreeDriver