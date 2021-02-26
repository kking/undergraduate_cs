/**
 * Course: CS112		Project: Final Project
 * Programmer: King		Date last modified: 11 December, 2017
 * 
 * File name: Intervals.java
 *
 * Description: A container which tracks the audio playback of wav files for several objects of the inner class IntervalWavFile.
 *
 * Purpose: This program is used to test the user's ability to identify an interval represented by a wav file stored within an 
 * object of class IntervalWavFile, where said file is passed through methods of AudioSystem, AudioInputStream, and Clip in order 
 * to playback its data through the system's audio device. An ArrayList of IntervalWavFile objects is automatically defined according 
 * 12 wav files created to represent each interval from within a musical octave, and its contents may be selected and removed at a 
 * specified or randomized index.
 * 		
 * Classes:
 * IntervalWavFile - private inner class to store a wav file with information specifying the interval to be played
 */

import java.io.File;
import java.io.IOException;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;
import java.util.ArrayList;
import java.util.Random;

class Intervals 
{	
	/* Name of directory for audio files. */
	private static final String FILE_DIRECTORY = "audio/";
	/* Names of audio files. */
	private static final String[] FILE_NAMES = { FILE_DIRECTORY + "00_cUnison.wav", FILE_DIRECTORY + "01_cMinorSecond.wav",
					FILE_DIRECTORY + "02_cMajorSecond.wav", FILE_DIRECTORY + "03_cMinorThird.wav",
					FILE_DIRECTORY + "04_cMajorThird.wav", FILE_DIRECTORY + "05_cPerfectFourth.wav",
					FILE_DIRECTORY + "06_cTritone.wav", FILE_DIRECTORY + "07_cPerfectFifth.wav",
					FILE_DIRECTORY + "08_cMinorSixth.wav", FILE_DIRECTORY + "09_cMajorSixth.wav",
					FILE_DIRECTORY + "10_cMinorSeventh.wav", FILE_DIRECTORY + "11_cMajorSeventh.wav",	
					FILE_DIRECTORY + "12_cUnison.wav" };
	/* Defines initial ArrayList capacity */
	static final int INITIAL_CAPACITY = 13;
	/* All intervals should be consistent with the first note played */
	static final String KEY = "C";	
	/* For randomly generating an integer from 0 to 12 in relation to the number of semitones within a given interval. */
	static final Random SEMITONE_GENERATOR = new Random();
	/* The number of milliseconds delayed between the invocation of the start and stop methods of a Clip object */
	static final int STOP_DELAY = 2000;
	/* Diatonic = within the key (such as C major, including only 8 notes within the octave), otherwise chromatic (Inludes all 12 
	   notes within the octave) */
	boolean isDiatonic;	
	/* An ArrayList of IntervalWavFile objects, where each element is represented by their IntervalWavFile instance variable
	   values, namely their constituent wav file and the number of semitones within the given interval. */
	ArrayList<IntervalWavFile> wavFiles;
	/* Tracks the interval just played by methods playClip and playRandomClip for use in repeatClip */
	String intervalString;
	
	
	/**
	 * Default constructor. Assuming use of the chromatic scale, isDiatonic is set to false. As a result, the loadFiles method will 
	 * add all 12 possible IntervalWavFile objects to the ArrayList of base type IntervalWavFile.
	 */	
	public Intervals()
	{
		isDiatonic = false; // chromatic
		loadFiles();
	}
	
	/**
	 * Full consructor
	 *
	 * @param isDiatonic - where diatonic includes 8 out of 12 intervals from within an octave to form the major scale. If set to 
	 *  false, the chromatic scale is assumed, where all 12 notes from within the octave are included. 	
	 */
	public Intervals(boolean isDiatonic)
	{
		this.isDiatonic = isDiatonic; // true = diatonic/major scale, false = chromatic scale
		this.loadFiles(); 
	}
	
	/** 
	 * Adds to the ArrayList of base type IntervalWavFile objects based on the 12 wav files created to represent all intervals from 
	 * within a single octave.
	 */	
	private void loadFiles()
	{
		// ArrayList object is instantiated with an initial capacity of INITIAL_CAPACITY
		wavFiles = new ArrayList<IntervalWavFile>(INITIAL_CAPACITY);
		
		// First, the IntervalWavFile objects representing the major and perfect intervals will be added to the ArrayList to create 
		// the major scale.
		wavFiles.add(new IntervalWavFile(KEY, "P1", FILE_NAMES[0])); 
		wavFiles.add(new IntervalWavFile(KEY, "M2", FILE_NAMES[2]));    
		wavFiles.add(new IntervalWavFile(KEY, "M3", FILE_NAMES[4]));      
		wavFiles.add(new IntervalWavFile(KEY, "P4", FILE_NAMES[5]));   
		wavFiles.add(new IntervalWavFile(KEY, "P5", FILE_NAMES[7]));  
		wavFiles.add(new IntervalWavFile(KEY, "M6", FILE_NAMES[9]));      
		wavFiles.add(new IntervalWavFile(KEY, "M7", FILE_NAMES[11]));  
		wavFiles.add(new IntervalWavFile(KEY, "P8", FILE_NAMES[12]));
		
		// If isDiatonic is set to false, add the minor intervals and tritone to the list to complete the chromatic scale.
		// Though the index of each IntervalWavFile is irrelevant to the operations of this program, these intervals will be added 
		// in context to the ascending order of semitones in the list.
		if (!(isDiatonic))
		{
			wavFiles.add(1, (new IntervalWavFile(KEY, "m2", FILE_NAMES[1]))); 
			wavFiles.add(3, (new IntervalWavFile(KEY, "m3", FILE_NAMES[3]))); 
			wavFiles.add(6, (new IntervalWavFile(KEY, "A4", FILE_NAMES[6])));
			wavFiles.add(8, (new IntervalWavFile(KEY, "m6", FILE_NAMES[8]))); 
			wavFiles.add(10, (new IntervalWavFile(KEY, "m7", FILE_NAMES[10])));
		}
			           
	}
	
	/** 
	 * Utilizes the AudioSystem, AudioInputStream, and Clip classes to play and stop a given IntervalWavFile object's wav file. 
	 * The object's intervalSymbol value is returned for use in evaluating a user's identification of the interval represented by 
	 * the audio file.
	 *
	 * @param iwf - an existing IntervalWavFile object, which contains String information and a wav file representing an interval
	 * @return the interval abbreviation represented by the selected wav file from within the IntervalWavFile object
	 */
	public String playClip(IntervalWavFile iwf)
	{
		intervalString = "";
		
		try
		{
			// Checking if iwf's constituent wav file exists
			if (!(iwf.wavFile.exists()))
			{
				System.out.println("Error in locating audio file. Closing program ... ");
				System.exit(0);
			}
			
			// Using the AudioSystem class for:
			// Opening an audio input stream from an audio file in the program's directory
			AudioInputStream audioIn = AudioSystem.getAudioInputStream(iwf.wavFile);
			
			// Storing the input into a Clip object for loading its data for playback
			Clip aClip = AudioSystem.getClip();
			
			// Opening the Clip which acquires the system's resources for processing audio data
			aClip.open(audioIn);
			
			// Starting audio playback of the audio data that was just stored
			aClip.start();
			
			// Delaying execution of the Clip stopping by the given amount of milliseconds assigned to STOP_DELAY (2000, or 2 
			// seconds). This is done to allow for the Clip to play through its duration, where each IntervalWavFile's wav file is 
			// of a consistent length
			Thread.sleep(STOP_DELAY); // throws InterruptedException
			
			// Stopping audio playback of current Clip
			aClip.stop();
			
			// Precautionary step; resetting the position from which the wav file is played
			aClip.setFramePosition(0);
			
			// Closing the Clip and its audio input stream
			aClip.close();
			audioIn.close();
			
			// To return the interval abbreviation represented by the selected file
			intervalString = iwf.intervalSymbol;
			
		}
		catch (InterruptedException e) // when a Thread operation is suddenly halted
		{
			e.printStackTrace();
			System.exit(0);
		}
		catch (LineUnavailableException e) // if an audio resource cannot be opened
		{
			e.printStackTrace();
			System.exit(0);
		}
		catch (UnsupportedAudioFileException e) // if the file is not a recognized format
		{
			e.printStackTrace();
			System.exit(0);
		}
		catch (IOException e)
		{
			e.printStackTrace();
			System.exit(0);
		}
		
		// Returns the interval abbreviation assigned to the IntervalWavFile object
		// This will be useful in the case that the user is asked to name the interval represented by the Clip's audio data
		return intervalString;
	}
	
	/** 
	 * Invokes Interval's playClip method, passing an IntervalWavFile of a randomy selected index within its cooresponding ArrayList. 
	 * A random selection is made by invoking the Random method nextInt(n), where n is an integer within the range of 0 to the size 
	 * of the list.
	 *
	 * @return the interval abbreviation represented by the selected wav file
	 */
	public String playRandomClip()
	{
		// Obtaining a random index from within the domain of [0, wavFIles.size()]
		// The InvervalWavFile occupying this index will be passed through the playClip method
		int randomIndex = SEMITONE_GENERATOR.nextInt(this.wavFiles.size());
		
		// Returns the interval abbreviation obtained by invoking the playClip method
		return this.playClip(wavFiles.get(randomIndex));
	}
	
	/**
	 * In the case that playClip or playRandomClip has been prebviously executed, the IntervalWavFile object's wav file is accessed
	 * through its cooresponding intervalSymbol value and said object is passed through the playClip method to repeat playback of 
	 * the interval.
	 *
	 * @return the interval abbreviation represented by the selected wav file
	 */
	public String repeatClip()
	{
		IntervalWavFile repeatedIWF = new IntervalWavFile();
		
		// If neither playRandomClip nor playClip were previously invoked, then the String is still empty.
		// Therefore, this method will call and return from the playRandomClip method
		if (intervalString.equals("")) 
		{
			return this.playRandomClip();
		}
		else
		{
			// Searching for the first IntervalWavFile whose intervalSymbol value matches the String defined by playClip
			for (IntervalWavFile iwf : wavFiles)
			{
				if (iwf.intervalSymbol.equals(intervalString))
				{
					repeatedIWF = iwf;
					break;
				}
			}
		
			// Call and return from the playClip method
			return this.playClip(repeatedIWF);
		}
	}
	
	/**
	 * Searches through the calling object's ArrayList<IntervalWavFile> and removes the first instance of an IntervalWavFile object 
	 * whose intervalSymbol value matches that passed through the argument.
	 *
	 * @param intervalSymbol - an inteval as defined by its quality (major/M, minor/m, perfect/P, augmented/A, or diminished/d) and 
	 *  size (1-8)
	 * @return the interval abbreviation representing the removed IntervalWavFile object
	 */
	public String removeInterval(String intervalSymbol)
	{
		boolean removed = false;
		int index = 0;
		String intervalString = "";
		
		if (!(wavFiles.isEmpty())) // If the ArrayList is not empty
		{
			// Evaluate each object from within the ArrayList in ascending order
			for (IntervalWavFile iwf : this.wavFiles)
			{
				// If the current IntervalWavFile object's intervalSymbol value matches the one passed through the method,
				// store the index of said object, 
				// store its intervalSymbol value to be returned by the method,
				// set removed to true to indicate that an object to remove has been found, 
				// and break the for-each loop
				if (iwf.intervalSymbol.equals(intervalSymbol))
				{
					index = wavFiles.indexOf(iwf);
					intervalString = iwf.intervalSymbol;
					removed = true;
					break;
				}
			}
		}
		
		// If removed has been set to true, then an IntervalWavFile object has been found for removal
		if (removed)
			this.wavFiles.remove(index);
		
		// Return the interval abbreviation representing the removed IntervalWavFile object	
		return intervalString;
	}
	
	/**
	 * @return a reference to the Intervals object's ArrayList of type IntervalWavFile
	 */
	public ArrayList<IntervalWavFile> getIntervals()
	{
		return this.wavFiles;
	}
	
	/**
	 * @return the full interval name based on the intervalSymbol value returned by either playClip or playRandomClip.
	 */
	public String getFullIntervalName()
	{
		if (intervalString == null)
			return null;
		else
		{
			IntervalWavFile temp = new IntervalWavFile();
			temp.setInterval(intervalString);
			
			return temp.intervalName;
		}
	}
	
	/**
	 * @return a String listing the Intervals object's current mode (diatonic or chromatic) and, from its ArrayList of base type 
	 *  IntervalWavFile, each element's toString data
	 */	
	public String toString()
	{
		// Listing the mode, or scale that is represented by the Intervals object
		String intervalString = "Mode: ";
		if (isDiatonic)
			intervalString += "Major (Diatonic) \n";
		else
			intervalString += "Chromatic \n";
		
		// Listing each IntervalWavFile's file name, full interval name, interval abbreviation, number of semitones, and key based 
		// on the data returned by their toString method		
		intervalString += "Files: \n";
		if (!(this.wavFiles.isEmpty()))
			intervalString += "None. \n";
		else
		{
			for (IntervalWavFile iwf : wavFiles)
				intervalString += iwf.toString() + "\n";
		}
			
		return intervalString;
	}
	
	/**
	 * @param anObject - any given Object
	 * @return true if the two Intervals objects have equivalent isDiatonic values, wavFiles.size() values, and if all elements in 
	 *  their respective ArrayLists are equal for each index.
	 */	
	public boolean equals(Object anObject)
	{
		if ((anObject == null) || (this.getClass() != anObject.getClass()))
			return false;
		else
		{
			boolean isEqual = true;
			Intervals other = (Intervals) anObject;
			
			// Checking the equivalency of the two object's isDiatonic values
			if (this.isDiatonic != other.isDiatonic)
				isEqual = false;
			
			// Checking the equivalency of the two object's ArrayList<IntervalWavFile> size	
			if (this.wavFiles.size() != other.wavFiles.size())
				isEqual = false;
			else
			{
				// Checking the equivalency of each element at the same indexes of the ArrayList
				for (int i = 0; i < this.wavFiles.size(); i++)
				{
					if (!(this.wavFiles.get(i).equals(other.wavFiles.get(i))))
					{
						isEqual = false;
						break;
					}
						
				}
			}
			
			return isEqual;
		}
	}
	
	/**
	 * Private inner class IntervalWavFile
	 *
	 * Description: A class for storing an audio file with variables to describe it as a representation of a musical interval. 
	 *
	 * Purpose: From within the class Intervals, this private inner class is used to give each of the 12 wav files created for 
	 * Intervals data which explicitly defines the interval that is being played. Specifically, the wav file stored in each 
	 * instance may be identified by its interval name (String), interval abbreviation (String), and number of semitones (int) 
	 * in context to its given key (char). 
	 */
	private class IntervalWavFile
	{
		/* This program is limited to the C major and C chromatic scales. */
		private char key;
		/* The maximum amount of seimitones from the first note is 12 semitones. */
		private int semitones; 
		private String intervalName, intervalSymbol, fileName; 
		private File wavFile; 
		
		/**
		 * Default constructor
		 */
		private IntervalWavFile()
		{
			this.setKey("C");
			this.setInterval("P1");
			this.setFile("audio/00_cUnison.wav"); // Must exist within the program's directory
		}
		
		/**
		 * Full constructor
		 *
		 * @param key The key as defined by the first note played in the file. In the case of this program, it will be C.
		 * @param intervalSymbol Named by its quality (major/M, minor/m, perfect/P, dimnished/d, or augmented/A) and size (1-8)
		 * @param fileName The name of the wav file demonstrating the sound of the interval
		 */
		private IntervalWavFile(String key, String intervalSymbol, String fileName)
		{
			this.setKey(key);
			this.setInterval(intervalSymbol);
			this.setFile(fileName);
		}
		
		/**
		 * Copy constructor
		 *
		 * @param iwf - an existing IntervalWavFile object
		 */
		private IntervalWavFile(IntervalWavFile iwf)
		{
			this.setKey(iwf.key + "");
			this.setInterval(iwf.intervalSymbol);
			this.setFile(iwf.fileName);
		}
		
		/**
		 * Clone method
		 *
		 * @return an IntervalWavFile whose key, intervalSymbol and fileName values match those of the calling object
		 */
		public IntervalWavFile clone()
		{
			return new IntervalWavFile(this);
		}	
		
		/**
		 * Sets the key for which a set of IntervalWavFile objects are represented. Major keys are represented by a 'A' 
		 * through 'G', and minor keys by 'a' through 'g'. In the case of this program, the key will always be in C.
		 *
		 * @param key - the key as defined by the first note played in the file.
		 */
		private void setKey(String key)
		{
			// Checking if the given key is a letter within the musical alphabet
			// Otherwise, the proram will forcefully terminate.
			switch (key.trim().toLowerCase().charAt(0))
			{
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
				case 'g':
					this.key = key.charAt(0);
					break;
				default:
					System.out.println("Invalid key entry. Closing program ... ");
					System.exit(0);
					break;
			}
		}
		
		/**
		 * Sets the full interval name and symbol based on its formal abbreviation. In this program, the maximum interval size 
		 * is 8 and the qualities may be major (M), minor (m), perfect (P), or augmented (A4) and diminiahws (d5) in the case 
		 * that both represent the tritone.
		 *
		 * @param intervalSymbol - the interval named by its quality (major/M, minor/m, perfect/P, dimnished/d, or augmented/A) 
		 *  and size (1-8)
		 */
		private void setInterval(String intervalSymbol)
		{
			this.intervalSymbol = intervalSymbol;
			
			// If the given symbol matches any of the cases listed below, 
			// intervalName will be defined as the full interval name based on the given abbreviation
			switch (intervalSymbol)
			{
				case "P1":
					intervalName = "Unison";
					semitones = 0;
					break;
				case "m2":
					intervalName = "Minor second";
					semitones = 1; // One half tone
					break;
				case "M2":
					intervalName = "Major second";
					semitones = 2; // One whole tone
					break;
				case "m3":
					intervalName = "Minor third";
					semitones = 3;
					break;
				case "M3":
					intervalName = "Major third";
					semitones = 4; // Two whole tones
					break;
				case "P4":
					intervalName = "Perfect fourth";
					semitones = 5;
					break;
				case "A4": // Augmented fourth; 1 semitone above a P4
				case "d5": // Diminished fifth; 1 semitone below a P5
					intervalName = "Tritone"; // Existing between a P4 and a P5,
					semitones = 6;			  // the tritone may be named as an A4 or d5
					break;
				case "P5":
					intervalName = "Perfect fifth";
					semitones = 7;
					break;
				case "m6":
					intervalName = "Minor sixth";
					semitones = 8; // Four whole tones
					break;
				case "M6":
					intervalName = "Major sixth";
					semitones = 9;
					break;
				case "m7":
					intervalName = "Minor seventh";
					semitones = 10; // Five whole tones
					break;
				case "M7":
					intervalName = "Major seventh";
					semitones = 11;
					break;
				case "P8":
					intervalName = "Octave";
					semitones = 12; // Six whole tones
					break;
				default:
					System.out.println("Invalid interval entry. Closing program ... ");
					System.exit(0);
					break;
			}
		}
		
		/**
		 * Creates a File object from an existing wav file.
		 * In this program, 12 wav files have been created, each playing two notes on a synthesized piano. The first note is 
		 * always a C4 (middle C), and the second is one of each intervals from C4 to C5 (an octave above middle C).
		 *
		 * @param fileName - the name of the wav file demonstrating the sound of a given interval. 
		 */
		private void setFile(String fileName)
		{
			this.fileName = fileName;	
			wavFile = new File(fileName);
			
			if (!(wavFile.exists()))
			{
				System.out.println(fileName + " does not exist. Closing program ... ");
				System.exit(0);
			}
		}
		
		/**
		 * @return a String listing the wav file's file name, full interval name, interval abbreviation, number of semitones 
		 *  within the interval, and key.
		 */
		public String toString()
		{
			String intervalString = this.fileName +
									" | " + this.intervalName +
									" (" + this.intervalSymbol +
									", " + this.semitones +
									" semitones) in the key of " + this.key;
			
			return intervalString;
		}
		
		/**
		 * @param anObject - any given Object
		 * @return true if the two IntervalWavFiles have matching key, intervalSymbol, and fileName values
		 */
		public boolean equals(Object anObject)
		{
			if ((anObject == null) || (this.getClass() != anObject.getClass()))
				return false;
			else
			{
				IntervalWavFile iwf = (IntervalWavFile) anObject;
				
				return ((this.key == iwf.key) &&
						(this.intervalSymbol.equals(iwf.intervalSymbol)) &&
						(this.fileName.equals(iwf.fileName)));	
			}
		}
		
		
	} // End of class IntervalWavFile
		
} // End of class Intervals
