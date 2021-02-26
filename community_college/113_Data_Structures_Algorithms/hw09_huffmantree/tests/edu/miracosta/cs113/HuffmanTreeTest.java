package edu.miracosta.cs113;

import org.junit.Test;

/**
 * HuffmanTreeTest : Tester class for the HuffmanTree class implementation.
 *
 * @author King
 * @version 1.0
 */
public class HuffmanTreeTest {

    public static final String[] URL = {"http://michaelwflaherty.com/files/index.html"};
    public static final String ORIGINAL_FILENAME = "test";
    public static final String ENCODED_FILENAME = "testEncoded";
    public static final String DECODED_FILENAME = "testDecoded";

    HuffmanTree huffTree;

    /**
     * Creates a HuffmanTree based on the given url. Verify that the Huffman tree implementation properly creates
     * files which receives the html content of a page, compresses said content into Huffman code, and decodes the
     * encoding using the same Huffman tree.
     *
     * 1. A text file containing the original page's text is created.
     * 2. The printCode method creates a new file based on the HuffmanTree's encoding of the original file's text.
     * 3. The decode method is called to create a new file which decodes the encoded file's binary representation
     *    of the original text.
     * 4. The HuffmanTree is printed to the console.
     */
    @Test
    public void testHuffmanTreeBuild() {
        huffTree = new HuffmanTree(URL[0], ORIGINAL_FILENAME);
        huffTree.encode(ORIGINAL_FILENAME, ENCODED_FILENAME);
        huffTree.decode(ENCODED_FILENAME, DECODED_FILENAME);

        System.out.println(huffTree);
    }

} // End of class HuffmanTreeTest