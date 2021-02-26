package edu.miracosta.cs113;

/**
 * MorseCodeException : An exception class for cases in which a MorseCodeTree is given input for one morse
 * code value contains invalid characters or exceeds the length equal to the height of the tree - 1.
 *
 * @author King
 * @version 1.0
 */
public class MorseCodeException extends Exception {

    /**
     * Default constructor
     */
    public MorseCodeException() {
        super("MorseCodeException - Invalid morse code token.");
    }

    /**
     * Constructor whose error message is defined by the given string.
     * @param message A specified error message
     */
    public MorseCodeException(String message) {
        super(message);
    }

} // End of class MorseCodeException