package edu.miracosta.cs113;

import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * HuffmanTree : An implementation of a Huffman tree, a binary tree that encodes characters present in a text
 * file based on their frequency of occurrence. Using fewer bits for more common characters, an encoded text
 * file using Huffman codes yields fewer bits than other methods of compression.
 *
 * Created with content adapted from Koffman and Wolfgang's Data Structures: Abstraction and Design Using Java.
 *
 * @author King
 * @version 1.0
 */
public class HuffmanTree implements Serializable {

    /** The total number of elements within the ASCII character set. */
    private static final int TOTAL_VALUES = 128;
    /** A reference to the completed Huffman tree. */
    private BinaryTree<HuffData> huffTree;

    /**
     * Constructor which receives the url by which the HuffmanTree will be constructed from its html content.
     * The encoded file will also be produced based on the build of the HuffmanTree, in addition to a file whose
     * content is the result of decoding the encoded file through the HuffmanTree.
     *
     * @param url The url whose html content is to be extracted for encoding and decoding through the Huffman tree
     * @param originalFilename The desired file name for the original text file
     * @param encodedFilename The desired file name for the encoded text file
     * @param decodedFilename The desired file name for the decoded text file
     */
    public HuffmanTree(String url, String originalFilename, String encodedFilename, String decodedFilename) {
        buildTree(url, originalFilename);
        encode(originalFilename, encodedFilename);
        decode(encodedFilename, decodedFilename);
    }

    /**
     * Constructor receives the url by which the HuffmanTree will be constructed from its html content.
     *
     * @param url The url whose html content is to be extracted for encoding and decoding through the Huffman tree
     * @param originalFilename The desired file name for the original text file
     */
    public HuffmanTree(String url, String originalFilename) {
        buildTree(url, originalFilename);
    }

    /**
     * Helper method for creating an array of HuffData values to be passed through buildTree(HuffData[]).
     *
     * Said array's indexes denote each of the 128 ASCII character values, with each element's data storing an
     * integer representing the weight (in frequency of occurrence) of the given character.
     *
     * Using the TextFileGenerator class method makeCleanFile, the html content of the given url is received
     * and its valid characters ('A'-'Z', 'a'-'z', '0'-'9'. '.', '!', '?', ' ', '\t', '\n') are output to a text
     * file with the given name.
     *
     * Single characters are then read as integer values representing their ASCII values. For each occurrence of
     * a given character, the array index which represents its value is incremented in weight.
     *
     * Lastly, an array of HuffData objects are created and its elements are defined from every character whose
     * weight is greater than 0.
     *
     * @param url The url whose html content is to be extracted for encoding and decoding through the Huffman tree
     * @param originalFilename The desired file name for the original text file
     */
    private void buildTree(String url, String originalFilename) {
        // Declare and initialize array for storing the weights of each character according to its ASCII value
        int[] tempWeights = new int[TOTAL_VALUES];
        for (int i = 0; i < tempWeights.length; i ++) {
            tempWeights[i] = 0;
        }

        try {
            // Read given url's html content and output its valid characters to the new original text file
            TextFileGenerator.makeCleanFile(url, originalFilename);

            // Passing the new text file of the original text through a BufferedReader
            File outputFile = new File(originalFilename);
            BufferedReader readIn = new BufferedReader(new FileReader(outputFile));

            // Reading single characters as int values from input stream until end of file sets nextChar = -1
            int nextChar = 0;
            while ((nextChar = readIn.read()) != -1) {
                tempWeights[nextChar] ++; // Increase weight of given character
            }

            readIn.close();
        }
        catch (IOException ioe) {
            System.out.println(ioe.getMessage());
            System.exit(1);
        }

        // Creating array of HuffData objects based on characters that have been found in the original text file
        HuffData[] symbols = new HuffData[TOTAL_VALUES];
        for (int i = 0; i < symbols.length; i ++) {
            if (tempWeights[i] > 0) {
                symbols[i] = new HuffData(tempWeights[i], (char)i);
            }
        }

        buildTree(symbols);
    }

    /**
     * Builds the Huffman tree using the given alphabet and weights by creating a priority queue for storing
     * BinaryTrees of type HuffData based on the CompareHuffmanTrees comparator.
     *
     * First, the priority queue is loaded with trees comprised of only leaf nodes containing HuffData objects.
     * The tree is then built iteratively until only one tree exists in the queue. Through each loop, the smallest
     * trees are removed from the queue, combined to create a new BinaryTree whose root node's weight is the sum of
     * the weights of its children, and inserted back into the priority queue.
     *
     * post: huffTree contains a reference to the Huffman tree.
     *
     * @param symbols An array of HuffData objects
     */
    private void buildTree(HuffData[] symbols) {
        Queue<BinaryTree<HuffData>> theQueue = new PriorityQueue<BinaryTree<HuffData>>(symbols.length, new CompareHuffmanTrees());

        // Load the queue with the leaves
        for (HuffData nextSymbol : symbols) {
            if (nextSymbol != null) {
                BinaryTree<HuffData> aBinaryTree = new BinaryTree<HuffData>(nextSymbol, null, null);
                theQueue.offer(aBinaryTree);
            }
        }

        // Build the tree
        while (theQueue.size() > 1) {
            BinaryTree<HuffData> left = theQueue.poll();
            BinaryTree<HuffData> right = theQueue.poll();

            double weightLeft = left.getData().weight;
            double weightRight = right.getData().weight;

            HuffData sum = new HuffData((weightLeft + weightRight), null);
            BinaryTree<HuffData> newTree = new BinaryTree<HuffData>(sum, left, right);
            theQueue.offer(newTree);
        }

        // The queue should now contain only one item - the full Huffman tree
        huffTree = theQueue.poll();
    }

    /**
     * Wrapper method for creating encoded file.
     *
     * pre: the file associated with originalFilename exists in context to the HuffmanTree build
     *
     * @param originalFilename The original file read from a web page
     * @param encodedFilename The desired name for the encoded file.
     */
    public void encode(String originalFilename, String encodedFilename) {
        String input = "";
        try {
            BufferedReader readIn = new BufferedReader(new FileReader(originalFilename));
            StringBuilder sb = new StringBuilder();

            String line = "";
            while ((line = readIn.readLine()) != null) {
                sb.append(line);
            }
            input = sb.toString();
            encode(input, "", new PrintStream(new File(encodedFilename)), huffTree);
        }
        catch (IOException ioe) {
            //
        }
    }

    /**
     * Reads the original input file by character, converting each into their Huffman code based on the tree built
     * from the original text file.
     *
     * @param input The original text file input
     * @param code The Huffman code to be written into the encoded file
     * @param out The PrintStream to write in the Huffman code
     * @param tree The current node in the Huffman tree
     */
    private void encode(String input, String code, PrintStream out, BinaryTree<HuffData> tree) {
        if (tree != null) {
            if (tree.getData().symbol != null) {
                if (tree.getData().symbol == input.charAt(0)) {
                    out.print(code);
                }
                if (input.length() > 1) {
                    encode(input.substring(1), code + "0", out, tree.getLeftSubtree());
                    encode(input.substring(1), code + "1", out, tree.getRightSubtree());
                }
            }
            else {
                encode(input, code + "0", out, tree.getLeftSubtree());
                encode(input, code + "1", out, tree.getRightSubtree());
            }
        }
    }

    /**
     * Helper method for creating a text file containing the compression of the original file as a result of
     * Huffman binary encoding.
     *
     * @param encodedFilename The desired file name for the encoded text file
     */
    public void printCode(String encodedFilename) {
        try {
            PrintStream out = new PrintStream(new File(encodedFilename));
            printCode(out, "", huffTree);
        }
        catch (FileNotFoundException fnfe) {
            System.out.println(fnfe.getMessage());
            System.exit(1);
        }
    }

    /**
     * Outputs the resulting code by performing a preorder traversal of the final tree.
     *
     * The given code is output when the traversal arrives to a leaf node (whose symbol != null). When
     * traversing left, a 0 is appended to said code, whereas traversing right appends a 1.
     *
     * @param out A PrintStream to which the output is written
     * @param code The code up to this node
     * @param tree The current node in the tree
     */
    private void printCode(PrintStream out, String code, BinaryTree<HuffData> tree) {
        HuffData theData = tree.getData();

        if (theData.symbol != null) {
            out.print(code);
        }
        else {
            printCode(out, code + "0", tree.getLeftSubtree());
            printCode(out, code + "1", tree.getRightSubtree());
        }
    }

    /**
     * Helper method for decoding the given encoded text file from Huffman binary to the characters it represents.
     *
     * pre: the file associated with encodedFilename must have been built after calling the printCode method
     *
     * @param encodedFilename The encoded file created by this Huffman tree
     * @param decodedFilename The desired file name for the decoded file
     */
    public void decode(String encodedFilename, String decodedFilename) {
        try {
            BufferedReader readIn = new BufferedReader(new FileReader(new File(encodedFilename)));
            PrintStream out = new PrintStream(new File(decodedFilename));

            String line = "";
            while ((line = readIn.readLine()) != null) {
                out.print(decode(line));
            }
        }
        catch (IOException ioe) {
            System.out.println(ioe.getMessage());
            System.exit(1);
        }
    }

    /**
     * Method to decode a message that is input as a string of digit characters '0' and '1'.
     *
     * @param codedMessage The input message as a String of zeroes and ones
     * @return The decoded message as a String
     */
    private String decode(String codedMessage) {
        StringBuilder result = new StringBuilder();
        BinaryTree<HuffData> currentTree = huffTree;

        for (int i = 0; i < codedMessage.length(); i ++) {
            if (codedMessage.charAt(i) == '1') {
                currentTree = currentTree.getRightSubtree();
            }
            else if (codedMessage.charAt(i) == '0') {
                currentTree = currentTree.getLeftSubtree();
            }

            if (currentTree.isLeaf()) {
                HuffData theData = currentTree.getData();
                result.append(theData.symbol);
                currentTree = huffTree; // Return to root of tne tree
            }
        }

        return result.toString();
    }

    /**
     * Returns a String representation of the Huffman tree.
     *
     * @return a String illustrating the Huffman tree, with leaf nodes representing the given HuffData's symbol value
     */
    public String toString() {
        return huffTree.toString();
    }

    /**
     * A Comparator for Huffman trees; nested class. To be used with the HuffmanTree's PriorityQueue, where the
     * compare method will be comparing two HuffmanTrees' weight values as stored in their respective root nodes.
     */
    public static class CompareHuffmanTrees implements Comparator<BinaryTree<HuffData>> {
        /**
         * Compares two objects.
         *
         * @param treeLeft The left-hand object
         * @param treeRight The right-hand object
         * @return -1 if left is less than right, 0 if left equals right, and +1 if left is greater than right
         */
        public int compare(BinaryTree<HuffData> treeLeft, BinaryTree<HuffData> treeRight) {
            double weightLeft = treeLeft.getData().weight;
            double weightRight = treeRight.getData().weight;
            return Double.compare(weightLeft, weightRight);
        }

    } // End of class CompareHuffmanTrees

    /**
     * Private inner class HuffData to contain an individual symbol which occurs in a given text file and its
     * number of occurrences in said file.
     */
    public static class HuffData implements Serializable {
        /** The weight or probability assigned to this HuffData. */
        private double weight;
        /** The alphabet symbol if this is a leaf. */
        private Character symbol;

        private HuffData(double weight, Character symbol) {
            this.weight = weight;
            this.symbol = symbol;
        }

        public String toString() {
            return "" + symbol;
        }

    } // End of class HuffData

} // End of class HuffmanTree