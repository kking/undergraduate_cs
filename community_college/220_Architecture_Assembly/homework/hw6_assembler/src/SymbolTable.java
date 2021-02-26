import java.util.HashMap;

/**
 * SymbolTable : A symbol table that keeps a correspondence between symbolic labels and numeric addresses.
 *
 * Model specifications received from CS220 Homework #6 - Assembler. Course material adapted from nand2tetris.org
 * and the book "The Elements of Computing Systems" by Nisan and Schocken, MIT Press.
 *
 * @author King
 */
public class SymbolTable {
	/** All valid characters for user-defined symbols with the exception of '0'-'9'. */
	private static final String INITIAL_VALID_CHARS = "_.$:" +
											"abcdefghijklmnopqrstuvwxyz" +
											"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	/** All valid characters for user-defined symbols. */
	private static final String ALL_VALID_CHARS = "0123456789" + INITIAL_VALID_CHARS;
	/** Map to contain a symbol and its corresponding address in RAM or ROM. */
	private HashMap<String, Integer> symbolTable;

	/**
	 * Initializes hashmap with predefined symbols.
	 *
	 * Precondition: Follows symbols/values from book/appendix
	 * Postconditon: All hashmap values have valid address integer
	 */
	public SymbolTable() {
		symbolTable = new HashMap<String, Integer>();
		
		// Symbols R0, ..., R15 refer to RAM addresses 0, ..., 15
		symbolTable.put("R0", 0);
		symbolTable.put("R1", 1);
		symbolTable.put("R2", 2);
		symbolTable.put("R3", 3);
		symbolTable.put("R4", 4);
		symbolTable.put("R5", 5);
		symbolTable.put("R6", 6);
		symbolTable.put("R7", 7);
		symbolTable.put("R8", 8);
		symbolTable.put("R9", 9);
		symbolTable.put("R10", 10);
		symbolTable.put("R11", 11);
		symbolTable.put("R12", 12);
		symbolTable.put("R13", 13);
		symbolTable.put("R14", 14);
		symbolTable.put("R15", 15);

		// VM control pointers
		symbolTable.put("SP", 0);
		symbolTable.put("LCL", 1);
		symbolTable.put("ARG", 2);
		symbolTable.put("THIS", 3);
		symbolTable.put("THAT", 4);

		// I/O pointers SCREEN and KBD
		symbolTable.put("SCREEN", 16384);
		symbolTable.put("KBD", 24576);
	}
	
	/**
	 * Determines if the given symbol is comprised of only valid characters ('A'-'Z', 'a'-'z', '0-9', '_', '.', '$',
	 * ':') and does not begin with a digit.
	 *
	 * @param symbol a user-defined variable or label name
	 * @return true if symbol is comprised only of valid characters and does not begin with a digit, false otherwise
	 */
	private static boolean isValidName(String symbol) {
		// If symbol begins with a digit
		if (symbol.length() < 1) {
			return false;
		}
		if (INITIAL_VALID_CHARS.indexOf(symbol.charAt(0)) == -1) {
			return false;
		}
		else {
			// Assess each character for possible invalid characters
			for (int i = 0; i < symbol.length(); i++) {
				if (ALL_VALID_CHARS.indexOf(symbol.charAt(i)) == -1) {
					return false;
				}
			}
			// Symbol is valid
			return true;
		}
	}	
		
	/**
	 * Determines whether the hashmap contains the given symbol or not.
	 *
	 * Precondition: table has been initialized
	 * Postcondition: returns boolean if arg is in table or not
	 *
	 * @param symbol a user-defined variable or label name
	 * @return true if the symbol exists in this SymbolTable, false otherwise
	 */
	public boolean contains(String symbol) {
		return symbolTable.containsKey(symbol.toUpperCase());
	}
	
	/**
	 * Adds new pair of symbol/address to hashmap.
	 *
	 * Precondition: symbol/address pair is not in hashmap
	 * Postcondition: adds pair, returns true if added, false if illegal name
	 *
	 * @param symbol a user-defined variable or label name
	 * @param address a decimal value representing an address in RAM or ROM
	 * @return true if added, false if symbol contains illegal characters
	 */
	public boolean addEntry(String symbol, int address) {
		// Check if map already contains the given symbol.
		if (contains(symbol) || !isValidName(symbol)) {
			return false;
		}
		symbolTable.put(symbol.toUpperCase(), address);
		return true;
	}
	
	/**
	 * Obtains address in hashmap of given symbol.
	 *
	 * Precondition: symbol is in hashmap
	 * Postcondition: returns address associated with symbol in hashmap
	 *
	 * @param symbol a user-defined variable or label name
	 * @return a decimal value representing an address in RAM or ROM, -1 if the symbol does not exist in this map
	 */
	public int getAddress(String symbol) {
		if (!contains(symbol)) {
			return -1;
		}
		return symbolTable.get(symbol.toUpperCase());
	}
	
} // End of class SymbolTable