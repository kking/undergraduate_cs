import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

/**
 * Parser : Encapsulates access to the input code. Reads an assembly language command, parses it, and provides
 * convenient access to the command's components (fields and symbols). In addition, removes all white space and
 * comments.
 *
 * Model specifications received from CS220 Homework #6 - Assembler. Course material adapted from nand2tetris.org
 * and the book "The Elements of Computing Systems" by Nisan and Schocken, MIT Press.
 *
 * @author King
 */
public class Parser {
	/** Label for a non-command (empty String/comment line). */
	private static final char NO_COMMAND = 'N';
	/** Label for an A-instruction. */
	private static final char A_COMMAND = 'A';
	/** Label for a C-instruction. */
	private static final char C_COMMAND = 'C';
	/** Label for a... label referring to the next A- or C-command in ROM. */
	private static final char L_COMMAND = 'L';
	/** A String representing null. */
	private static final String NULL_STRING = "null";
	
	/** Scanner to read and interpret a given .asm file. */
	private Scanner inputFile = null;
	/** The current line number for reading a given .asm file (debugging). */
	private int lineNumber;
	/** The current ASM line read before cleaning and parsing. */
	private String rawLine;
	
	/** The current ASM line after removing comments and white space.*/
	private String cleanLine;
	/** The current ASM line's command type; 'A', 'C', 'L', or 'N'. */
	private char commandType;
	/** The current ASM line's variable or label name parsed as an A- or L-command.*/
	private String symbol;
	/** The current ASM line's comp mnemonic parsed as a C-instruction. */
	private String compMnemonic;
	/** The current ASM line's dest mnemonic parsed as a C-instruction. */
	private String destMnemonic;
	/** The current ASM line's jump mnemonic parsed as a C-instruction. */
	private String jumpMnemonic;
	
	// region - drivers
	
	/**
	 * Opens input file/stream and prepares to parse.
	 *
	 * Precondition: Provided file is an ASM file
	 * Postcondition: If the file can't be opened, ends program w/ error message
	 *
	 * @param inFileName the name of an existing .asm file
	 */
	public Parser(String inFileName) {
		try {
			String fileExtensionName = inFileName.substring(inFileName.lastIndexOf('.'));
			
			// Obtain asm file.
			if (!fileExtensionName.equalsIgnoreCase(".asm")) {
				throw new FileNotFoundException();
			}
			// Begin Scanner where the first line to be read is 0.
			inputFile = new Scanner(new File(inFileName));
			lineNumber = 0;
		}
		catch (FileNotFoundException fnfe) {
			System.err.println("Parser.java - ASM file not opened. \nProvided file name: " + inFileName);
			System.exit(1);
		}
	}
	
	/**
	 * Determines if more commands left, closes stream if not
	 *
	 * Precondition: File stream is open
	 * Postcondition: Returns true if more commands, else closes stream
	 *
	 * @return true if more lines follow the current line, false otherwise
	 */
	public boolean hasMoreCommands() {
		if (inputFile.hasNextLine()) {
			return true;
		}
		else {
			inputFile.close();
			return false;
		}
	}
	
	/**
	 * Reads next line from file and parses it into instance variables.
	 *
	 * Precondition: File stream is open, called only if hasMoreCommands()
	 * Postcondition: Current instruction parts put into instance variables
	 */
	public void advance() {
		if (hasMoreCommands()) {
			cleanLine(inputFile.nextLine());
			parse();
			lineNumber++;
		}
	}
	
	// endregion - drivers
	// region    - parsing helpers
	
	/**
	 * Cleans the current line by removing comments and whitespace.
	 *
	 * Precondition: a line has been read from the file through a call to advance()
	 * Postcondition: the line is cleaned and the raw and clean line is set to the corresponding instance variables
	 *
	 * @param raw the current line being processed from the file
	 */
	private void cleanLine(String raw) {
		String clean = raw;
		
		// remove comment
		int commentIndex = clean.indexOf("//");
		if (commentIndex > -1) {
			clean = clean.substring(0, commentIndex);
		}
			
		// remove whitespace
		clean = clean.replaceAll(" ", "");
		clean = clean.replaceAll("\t", "");

		cleanLine = clean;
		rawLine = raw;
	}
	
	/**
	 * Determines if the current ASM line is an A-command, C-command, label or non-command.
	 *
	 * Precondition: advance() and cleanLine is defined
	 * Postcondition: commandType is set to 'A', 'C', 'L', or 'N'
	 *
	 * @param clean the current line prepared for parsing
	 */
	private void parseCommandType(String clean) {
		// If clean is an empty string, it is not an instruction or label.
		if (clean.isEmpty()) {
			commandType = NO_COMMAND;
		}
		// Otherwise, determine if clean is an A- or C-instruction, or label.
		else {
			if (clean.startsWith("@")) {
				// A-command; @value
				commandType = A_COMMAND;
			}
			else if (clean.startsWith("(")) {
				// label; (symbol)
				commandType = L_COMMAND;
			}
			else {
				// C-command; dest=comp;jump
				commandType = C_COMMAND;
			}
		}	
	}
	
	/**
	 * Helper method parses line depending on instruction type.
	 *
	 * Precondition: advance() called so cleanLine has value
	 * Postcondition: appropriate instance variables of instruction are defined
	 */
	private void parse() {
		// Reset parts' values
		compMnemonic = NULL_STRING;
		destMnemonic = NULL_STRING;
		jumpMnemonic = NULL_STRING;
		symbol = NULL_STRING;

		// Determine command type for parsing
		parseCommandType(cleanLine);

		if (commandType == C_COMMAND) {
			parseComp();
			parseDest();
			parseJump();
		}
		else if (commandType == A_COMMAND || commandType == L_COMMAND) {
			parseSymbol();
		}
	}

	/**
	 * Parses symbol for A- or L- commands.
	 *
	 * Precondition: advance() called so cleanLine has value, call for A- and L-commands only
	 * Postcondition: symbol has appropriate value from instruction assigned
	 */
	private void parseSymbol() {
		if (commandType == A_COMMAND) {
			// @symbol
			symbol = cleanLine.substring(1);
		}
		else if (commandType == L_COMMAND) {
			// (symbol)
			symbol = cleanLine.substring(1, cleanLine.length() - 1);
		}
	}
	
	/**
	 * Helper method parses line to get comp of C-instruction.
	 *
	 * Precondition: advance() called so cleanLine has value, call for C-instructions only
	 * Postcondition: compMnemonic set to appropriate value from instruction
	 */
	private void parseComp() {
		int equalsIndex = cleanLine.indexOf("="), semicolonIndex = cleanLine.indexOf(";");

		if (equalsIndex > 0 && semicolonIndex > 0) {
			// dest=comp;jump
			compMnemonic = cleanLine.substring(equalsIndex + 1, semicolonIndex);
		}
		else if (equalsIndex > 0) {
			// dest=comp
			compMnemonic = cleanLine.substring(equalsIndex + 1);
		}
		else if (semicolonIndex > 0) {
			// comp;jump
			compMnemonic = cleanLine.substring(0, semicolonIndex);
		}
	}

	/**
	 * Helper method parses line to get dest of C-instruction.
	 *
	 * Precondition: advance() called so cleanLine has value, call for C-instructions only
	 * Postcondition: destMnemonic set to appropriate value from instruction
	 */
	private void parseDest() {
		int equalsIndex = cleanLine.indexOf("=");

		if (equalsIndex > 0) {
			destMnemonic = cleanLine.substring(0, equalsIndex);
		}
	}

	/**
	 * Helper method parses line to get jump of C-instruction.
	 *
	 * Precondition: advance() called so cleanLine has value, call for C-instructions only
	 * Postcondition: jumpMnemonic set to appropriate value from instruction
	 */
	private void parseJump() {
		int semicolonIndex = cleanLine.indexOf(";");

		if (semicolonIndex > 0) {
			jumpMnemonic = cleanLine.substring(semicolonIndex + 1);
		}
	}
	
	// endregion - parsing helpers
	// region    - getters for Code
	
	/**
	 * Getter for command type.
	 *
	 * Precondition: cleanLine has been parsed (advance was called)
	 * Postcondition: returns char for command type ('N'/'A'/'C'/'L')
	 *
	 * @return the command type of the current instruction
	 */
	public char getCommandType() {
		return commandType;
	}
	
	/**
	 * Getter for symbol name.
	 *
	 * Precondition: cleanLine has been parsed (advance was called), call for labels only
	 * Postcondition: returns String for symbol name
	 *
	 * @return the symbol of the current A- or L-instruction
	 */
	public String getSymbol() {
		return ((getCommandType() == L_COMMAND || getCommandType() == A_COMMAND) ? symbol : NULL_STRING);
	}
	
	/**
	 * Getter for comp part of C-instruction.
	 *
	 * Precondition: cleanLine has been parsed (advance was called), call for C-instructions only
	 * Postcondition: returns mnemonic (ASM symbol) for comp part
	 *
	 * @return the comp mnemonic for the current C-instruction
	 */
	public String getComp() {
		return ((getCommandType() == C_COMMAND) ? compMnemonic : NULL_STRING);
	}

	/**
	 * Getter for dest part of C-instruction.
	 *
	 * Precondition: cleanLine has been parsed (advance was called), call for C-instructions only
	 * Postcondition: returns mnemonic (ASM symbol) for dest part
	 *
	 * @return the dest mnemonic for the current C-instruction
	 */
	public String getDest() {
		return ((getCommandType() == C_COMMAND) ? destMnemonic : NULL_STRING);
	}

	/**
	 * Getter for jump part of C-instruction.
	 *
	 * Precondition: cleanLine has been parsed (advance was called), call for C-instructions only
	 * Postcondition: returns mnemonic (ASM symbol) for jump part
	 *
	 * @return the jump mnemonic for the current C-instruction
	 */
	public String getJump() {
		return ((getCommandType() == C_COMMAND) ? jumpMnemonic : NULL_STRING);
	}
	
	// endregion - getters for Code
	// region    - debugging getters
	
	/**
	 * Getter for String version of command type.
	 *
	 * Precondition: advance() and parse() have been called
	 * Postcondition: returns String version of command type
	 *
	 * @return a String representation of the current command type
	 */
	public String getCommandTypeString() {
		return Character.toString(commandType);
	}
	
	/**
	 * Getter for rawLine from file.
	 *
	 * Precondition: advance() was called to put value from file into rawLine
	 * Postcondition: returns String of current original line from file
	 *
	 * @return the current raw line received from advance()
	 */
	public String getRawLine() {
		return rawLine;
	}
	
	/**
	 * Getter for cleanLine from file.
	 *
	 * Precondition: advance() and cleanLine() were called
	 * Postcondition: returns String of current clean instruction from file
	 *
	 * @return the current line received from advance() and cleanLine()
	 */
	public String getCleanLine() {
		return cleanLine;
	}
	
	/**
	 * Getter for lineNumber.
	 *
	 * @return the current line number being processed from file
	 */
	public int getLineNumber() {
		return lineNumber;
	}
	
	// endregion - debugging getters
	
} // End of class Parser
