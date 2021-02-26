package edu.miracosta.cs113;

import java.util.Scanner;

/**
 * HuffmanTreeDriver : Demonstration method for the HuffmanTree class implementation.
 *
 * ALGORITHM :
 *
 * 1. Take a URL and output text file name to create the original file by which the Huffman tree will be created
 * 2. Use the Huffman tree with the original file's website text to create an encoded file
 * 3. Use the Huffman tree with the encoded file to create a decoded file
 * 4. Output the number of bits for each file, using 16 bits per character for both the encoded and decoded files.
 *    Note that the original and decoded files should have the same number of bits.
 * 5. Output the percentage of compression, which is the quotient of the number of bits in the original file and
 *    the number of bits in the encoded file.
 *
 * @author King
 * @version 1.0
 */
public class HuffmanTreeDriver {

    public static String[] FILE_NAMES = {"original.txt", "encoded.txt", "decoded.txt"};
    public static Scanner KEYBOARD = new Scanner(System.in);

    /**
     * Driver program demonstrates HuffmanTree implementation.
     *
     * @param args not used in driver method
     */
    public static void main(String[] args) {

        HuffmanTree huffTree = null;
        boolean runProgram = true;

        while (runProgram) {
            System.out.println("Enter url: ");
            huffTree = createTreeFiles(KEYBOARD.nextLine(), FILE_NAMES[0], FILE_NAMES[1], FILE_NAMES[2]);

            printFileSizes(FILE_NAMES[0], FILE_NAMES[1], FILE_NAMES[2]);

            runProgram = runAgain("\n");

        } // End of while loop runProgram

        KEYBOARD.close();

    } // End of main method

    /**
     * Receives url to export the given page's text into a file. If the address is valid, then a Huffman tree is
     * constructed based on the html content of the web page. Three files are generated: the original text file containing
     * only characters permitted by the TextFileGenerator class, the encoding of said text file into Huffman binary, and
     * the decoding of that file utilizing the same Huffman tree.
     *
     * @param url The url whose html content is to be extracted for encoding and decoding through the Huffman tree
     * @param originalFilename The desired file name for the original text file
     * @param encodedFilename The desired file name for the encoded text file
     * @param decodedFilename The desired file name for the decoded text file
     */
    public static HuffmanTree createTreeFiles(String url, String originalFilename, String encodedFilename, String decodedFilename) {
        return new HuffmanTree(url, originalFilename, encodedFilename, decodedFilename);
    }

    /**
     * Prints the number of bits for the original, encoded, and decoded text files, using 16 bits per character for the
     * original and decoded files. Verify that the original and decoded files should have the same number of its. The
     * percentage of compression (bits in original file / bits in encoded file) is also output to the console.
     *
     * pre: each of the following files must exist as a result of an instance of HuffmanTree.
     *
     * @param originalFilename The file name associated with an existing original text file
     * @param encodedFilename The file name for an existing Huffman encoded file
     * @param decodedFilename The file name for an existing file representing the decoding of the same Huffman tree code
     */
    public static void printFileSizes(String originalFilename, String encodedFilename, String decodedFilename) {
        int originalBits, encodedBits, decodedBits;
        double percentageOfCompression;

        // for encoded count the number of 0's and 1's for the number of bits
    }

    /**
     * Prompts the user to select an option which reflects the re-iteration of the main method's while loop.
     *
     * @param message A custom message prior to the "Run again? {y/n)" prompt
     * @return True if the user responds with 'y', false if 'n'
     */
    public static boolean runAgain(String message) {
        boolean validInput = false; // Sets to true when a valid input is received
        boolean result = false;

        while (! validInput) {
            System.out.println(message + "Run again? (y/n)");
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

    // TODO: proper funerary practices for this HW09

} // End of class HuffmanTreeDriver