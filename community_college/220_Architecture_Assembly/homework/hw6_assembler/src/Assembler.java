import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Assembler : Driver that consolidates the functions of SymbolTable, Code, and Parser to produce a Hack file
 * translated from a given .asm file:
 *
 * SymbolTable - Tracks all symbols for ASM fills, including pre-defined symbols and user-defined labels/variables.
 * Code - Translates symbolic code (dest, comp, jump, decimal values) in ASM to HACK binary code.
 * Parser - Cleans each line, separates instructions into parts, and handles I/O of the given .asm file.
 *
 * Command-line testing and main starter code received from CS220 Homework #6 - Assembler. Course material adapted
 * from nand2tetris.org and the book "The Elements of Computing Systems" by Nisan and Schocken, MIT Press.
 *
 * @author King
 */
public class Assembler {
	/** Command labels for Parser. */
	private static final char A_COMMAND = 'A', C_COMMAND = 'C', L_COMMAND = 'L';
	/** Starting address for user-defined variables. */
	private static final int RAM_START = 16;
	/** Labels' SymbolTable addresses correspond to the next A- or C-instruction in ROM. */
	private static final int ROM_START = 0;

	/**
	 * Main method - Handles I/O for a given .asm to be translated into data for a corresponding .hack file. Helper
	 * methods firstPass and secondPass handle the parsing, translation, and writing of A- and C-instructions with
	 * instances of SymbolTable, Parser, and Code.
	 *
	 * ALGORITHM:
	 *   get input file name
	 *   create output file name and stream
	 *   create symbol table
	 *   do first pass to build symbol table (no output yet!)
	 *   do second pass to output translated ASM to HACK code
	 *   print out "done" message to user
	 *   lose output file stream
	 *
	 * @param args used in command line testing
	 */
	public static void main(String[] args) {
		String inputFileName, outputFileName;
		PrintWriter outputFile = null;
		SymbolTable symbolTable;

		// region - Receiving input/output files

		// Get input file name from command line or console input.
		if (args.length == 1) {
			System.out.println("command line arg = " + args[0]);
			inputFileName = args[0];
		}
		else {
			Scanner keyboard = new Scanner(System.in);

			System.out.println("Please enter assembly file name you would like to assemble.");
			System.out.println("Don't forget the .asm extension: ");
			inputFileName = keyboard.nextLine();

			keyboard.close();
		}

		outputFileName = inputFileName.substring(0,inputFileName.lastIndexOf('.')) + ".hack";

		try {
			outputFile = new PrintWriter(new FileOutputStream(outputFileName));
		}
		catch (FileNotFoundException fnfe) {
			System.err.println("Could not open output file " + outputFileName);
			System.err.println("Run program again, make sure you have write permissions, etc.");
			System.exit(0);
		}

		// endregion - Receiving input/output files

		symbolTable = new SymbolTable();

		// Execute first and second pass to populate the translated .hack file.
		firstPass(inputFileName, symbolTable);
		secondPass(inputFileName, symbolTable, outputFile);

		System.out.println("[" + inputFileName + "] has been translated into assembly in [" + outputFileName + "].");
		outputFile.close();

	} // End of main

	/**
	 * First pass - Parser obtains labels. sets their ROM address, and adds data pair to SymbolTable. For each label
	 * declaration (LABEL) that appears in the source code, the pair (LABEL, romAddress) is added to the SymbolTable,
	 * where the ROM address will only count by A- and C-commands.
	 *
	 * Precondition: inputFileName corresponds to an existing .asm file, and symbolTable has been initialized with
	 * pre-defined symbols.
	 * Postcondition: symbolTable is populated with both pre-defined symbols and user-defined labels.
	 *
	 * @param inputFileName the name of the .asm input file
	 * @param symbolTable a SymbolTable initialized with the HACK computer's pre-defined symbols
	 */
	private static void firstPass(String inputFileName, SymbolTable symbolTable) {
		Parser parser = new Parser(inputFileName);
		int romAddress = ROM_START; // from 0 to count each line of instruction memory

		// Read the given .asm file, parsing each line to receive labels.
		while (parser.hasMoreCommands()) {
			parser.advance();

			if (parser.getCommandType() == A_COMMAND || parser.getCommandType() == C_COMMAND) {
				// ROM will only increment by A- and C-commands.
				romAddress++;
			}
			if ((parser.getCommandType() == L_COMMAND) && (!symbolTable.contains(parser.getSymbol()))) {
				// Add new/declared label to SymbolTable, where the ROM corresponds to the next A- or C-command.
				symbolTable.addEntry(parser.getSymbol(), romAddress);
			}
		}
	} // End of method firstPass

	/**
	 * Second pass - Processes the given .asm source code by parsing each line into C-instruction parts or
	 * A-instruction symbols, translating said parts into Hack binary, and writing the result to the given .hack file
	 * stream.
	 *
	 * If the current line is a C-instruction, the comp, dest, and jump parts are received from the Parser, translated
	 * through Code to binary, appended to "111" and written to the output file.
	 *
	 * For an A-instruction, the symbol will be translated, appended to "0" and written to the output file. If the
	 * symbol can be converted to an unsigned 15-bit binary number, then its decimal value is translated through Code.
	 * If the symbol exists in the SymbolTable, its address will be read and translated into binary. Likewise, new/
	 * declared symbols will be added to the SymbolTable with the next available RAM address, and said address will
	 * be translated into binary for writing into the output file.
	 *
	 * Labels and non-commands are ignored.
	 *
	 * Precondition: inputFileName represents the .asm file read in firstPass, and symbolTable has been populated with
	 * pre-defined symbols and labels.
	 * Postcondition: outputFile will produce a .hack file containing each line from the given .asm file translated
	 * into binary A- and C-instructions.
	 *
	 * @param inputFileName the name of the .asm input file
	 * @param symbolTable the SymbolTable containing both pre-defined symbols and labels found in firstPass
	 * @param outputFile the resulting .hack file from translating the given .asm file
	 */
	private static void secondPass(String inputFileName, SymbolTable symbolTable, PrintWriter outputFile) {
		Parser parser = new Parser(inputFileName);
		Code code = new Code();

		int symbolValue, ramAddress = RAM_START; // from 16 for assigning user-defined symbols to RAM
		char commandType;
		String symbol = "", currentLine = "";

		// Read the same .asm file to process and write into the given .hack file.
		while (parser.hasMoreCommands()) {

			parser.advance();
			commandType = parser.getCommandType();

			if (commandType == C_COMMAND) {
				// Translate comp, dest, and jump and append to "111" of this C-instruction.
				currentLine = "111" + code.getComp(parser.getComp()) + code.getDest(parser.getDest()) +
								code.getJump(parser.getJump());

				// Write line to the output file.
				outputFile.println(currentLine);
			}
			else if (commandType == A_COMMAND) {
				// Translate decimal literal or symbol and append to "0" of this A-instruction.
				currentLine = "0";

				if (isDecimal(parser.getSymbol())) {
					// The symbol can be converted to an unsigned 15-bit binary number; translate.
					symbol = Code.decimalToBinary(Integer.parseInt(parser.getSymbol()));
				}
				else if (symbolTable.contains(parser.getSymbol())) {
					// The symbol exists in the table; obtain and translate its address.
					symbolValue = symbolTable.getAddress(parser.getSymbol());
					symbol = Code.decimalToBinary(symbolValue);
				}
				else {
					// The symbol is not found; add it to the SymbolTable with the current RAM address,
					// translate, then increment to the next available address.
					symbolTable.addEntry(parser.getSymbol(), ramAddress);
					symbol = Code.decimalToBinary(ramAddress++);
				}

				// Append translated symbol to line and write to the output file.
				currentLine += symbol;
				outputFile.println(currentLine);
			}
		}
	} // End of method secondPass

	/**
	 * Helper method for secondPass to determine if a given symbol can be represented as an unsigned 15-bit binary
	 * value.
	 *
	 * @param symbol a symbol for an A-instruction
	 * @return true if symbol corresponds to a decimal integer, false otherwise
	 */
	private static boolean isDecimal(String symbol) {
		for (char c : symbol.toCharArray()) {
			if (!Character.isDigit(c)) {
				return false;
			}
		}
		return true;
	}

} // End of class Assembler
