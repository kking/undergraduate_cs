import java.util.HashMap;

/**
 * Code : Translates Hack assembly language mnemonics into binary codes.
 *
 * Model specifications received from CS220 Homework #6 - Assembler. Course material adapted from nand2tetris.org
 * and the book "The Elements of Computing Systems" by Nisan and Schocken, MIT Press.
 *
 * @author King
 */
public class Code {
	/** Map containing all valid symbolic and binary comp code pairs. */
	private HashMap<String, String> compCodes;
	/** Map containing all valid symbolic and binary dest code pairs. */
	private HashMap<String, String> destCodes;
	/** Msp containing all valid symbolic and binary jump code pairs. */
	private HashMap<String, String> jumpCodes;
	
	/** Symbolic comp codes to be added to compCodes. */
	private static final String[] COMP_SYMBOLIC = {"0", "1", "-1", "D", "A", "!D", "!A", "-D", "-A",
									"D+1", "1+D",
									"A+1", "1+A",
									"D-1",
									"A-1",
									"D+A", "A+D",
									"D-A",
									"A-D",
									"D&A", "A&D",
									"D|A", "A|D",
									"M",
									"!M",
									"-M",
									"M+1", "1+M",
									"M-1",
									"D+M", "M+D",
									"D-M",
									"M-D",
									"D&M", "M&D",
									"D|M", "M|D"};
	/** Binary comp codes parallel to the list of symbolic comp codes. */
	private static final String[] COMP_BINARY = {"0101010", "0111111", "0111010", "0001100", "0110000", "0001101", "0110001",
									"0001111", "0110011",
									"0011111", "0011111",
									"0110111", "0110111",
									"0001110",
									"0110010",
									"0000010", "0000010",
									"0010011",
									"0000111",
									"0000000", "0000000",
									"0010101", "0010101",
									"1110000",
									"1110001",
									"1110011",
									"1110111", "1110111",
									"1110010",
									"1000010", "1000010",
									"1010011",
									"1000111",
									"1000000", "1000000",
									"1010101", "1010101"};
										
	/** Symbolic dest codes to be added to destCodes. */
	private static final String[] DEST_SYMBOLIC = {"null", "M", "D",
									"MD", "DM",
									"A",
									"AM", "MA",
									"AD", "DA",
									"AMD", "ADM", "MAD", "MDA", "DAM", "DMA"};
	/** Binary dest codes parallel to the list of symbolic dest codes. */
	private static final String[] DEST_BINARY = {"000", "001", "010",
									"011", "011",
									"100",
									"101", "101",
									"110", "110",
									"111", "111", "111", "111", "111", "111"};
	
	/** Symbolic jump codes to be added to jumpCodes. */
	private static final String[] JUMP_SYMBOLIC = {"null", "JGT", "JEQ", "JGE",
									"JLT", "JNE", "JLE", "JMP"};
	/** Binary jump codes parallel to the list of symbolic jump codes. */
	private static final String[] JUMP_BINARY = {"000", "001", "010", "011",
									"100", "101", "110", "111"};

	/** A String representing null. */
	private static final String NULL_STRING = "null";
	
	/**
	 * Initializes hashmaps with binary codes for easy lookup.
	 *
	 * Precondition: Comp codes = 7 bits (includes a), dest/jump codes = 3 bits
	 * Postcondition: All hashmaps have lookups for valid codes
	 */
	public Code() {
		compCodes = new HashMap<String, String>();
		destCodes = new HashMap<String, String>();
		jumpCodes = new HashMap<String, String>();
		
		for (int i = 0; i < COMP_SYMBOLIC.length; i++) {
			compCodes.put(COMP_SYMBOLIC[i], COMP_BINARY[i]);
		}
		
		for (int i = 0; i < DEST_SYMBOLIC.length; i++) {
			destCodes.put(DEST_SYMBOLIC[i], DEST_BINARY[i]);
		}
		
		for (int i = 0; i < JUMP_SYMBOLIC.length; i++) {
			jumpCodes.put(JUMP_SYMBOLIC[i], JUMP_BINARY[i]);
		}
	}
	
	/**
	 * Converts the String of bits (7) for the given mnemonic.
	 *
	 * Precondition: Hashmaps are built with valid values
	 * Postcondition: Returns String of bits if valid, else returns "null"
	 *
	 * @param mnemonic
	 * @return
	 */
	public String getComp(String mnemonic) {
		// Returns the value to which the specified key is mapped,
		// or defaultValue if this map contains no mapping for the key.
		return compCodes.getOrDefault(mnemonic, NULL_STRING);
	}
	
	/**
	 * Converts the String of bits (3) for the given mnemonic.
	 *
	 * Precondition: Hashmaps are built with valid values
	 * Postcondition: Returns String of bits if valid, else returns "null"
	 *
	 * @param mnemonic
	 * @return 
	 */
	public String getDest(String mnemonic) {
		return destCodes.getOrDefault(mnemonic, NULL_STRING);
	}
	
	/**
	 * Converts the String of bits (3) for the given mnemonic.
	 *
	 * Precondition: Hashmaps are built with valid values
	 * Postcondition: Returns String of bits if valid, else returns "null"
	 *
	 * @param mnemonic
	 * @return 
	 */
	public String getJump(String mnemonic) {
		return jumpCodes.getOrDefault(mnemonic, NULL_STRING);
	}
	
	/**
	 * Converts a decimal (base 10) integer to 15-bit binary (base 2).
	 *
	 * Precondition: given decimal number is unsigned and within range to represent a 15-bit binary value
	 * Postcondition: returns a 15-bit binary representation of the given decimal value
	 *
	 * @param toConvert a decimal number
	 * @return the binary conversion of toConvert
	 */
	public static String decimalToBinary(int toConvert) {
		return decimalToBinary(toConvert, "");
	}
	
	/**
	 * Recursive solution to convert a decimal integer to 15-bit binary.
	 *
	 * @param decimal the original decimal value
	 * @param binary a String which builds the decimal value's binary conversion
	 * @return a String representation of the converted binary value
	 */
	private static String decimalToBinary(int decimal, String binary) {
		if (binary.length() == 15) {
			// Return 15-bit binary conversion from original decimal value
			return binary;
		}
		else {
			// Append remainder to front of binary String
			return decimalToBinary((decimal/2), (decimal%2) + binary);
		}
	}
	
} // End of class Code
