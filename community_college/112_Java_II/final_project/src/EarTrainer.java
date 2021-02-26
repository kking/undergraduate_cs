/**
 * Course: CS112		Project: Final Project
 * Programmer: King		Date last modified: 11 December, 2017
 * 
 * File name: EarTrainer.java
 *
 * Description: The view program for Intervals.java
 *
 * Purpose: This program is used to test the user's ability to identify an interval represented by a wav file stored within an 
 * object of class IntervalWavFile, where said file is passed through methods of AudioSystem, AudioInputStream, and Clip in order 
 * to playback its data through the system's audio device. An ArrayList of IntervalWavFile objects is automatically defined according 
 * 12 wav files created to represent each interval from within a musical octave, and its contents may be selected and removed at a 
 * specified or randomized index.
 *	
 * Classes:
 * Intervals - A container which tracks the audio playback of wav files for several objects of the inner class IntervalWavFile.
 */
 
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.Border;
import javax.swing.BorderFactory; 			
import java.util.Random;

class EarTrainer extends JFrame
{
	// GUI constants
	public static final int WINDOW_WIDTH = 400;
	public static final int WINDOW_HEIGHT = 260;
	public static final int TEXT_AREA_ROWS = 2; 
	public static final int TEXT_AREA_COLUMNS = 30; 
	
	// GUI variables
	Border playBorder, selectionBorder;    
	ImageIcon earTrainerIcon; 			  
	JButton playButton; 				   
	JLabel titleLabel;
	JMenu options, reset;
	JMenuBar menuBar;
	JMenuItem chromaticMode, diatonicMode; // To set the current instance of Intervals based on its full constructor flag (isDiatonic)
	JPanel playPanel; 
	JPanel selectionPanel;
	JTextArea messageArea; 
	String areaMessage;
	
	// EarTrainer event variables
	Intervals intervalsDemo;   // Intervals object
	String intervalPlayed;
	boolean repeat, answered;  // Tracks user interaction in button events
	double correct, incorrect; 
	double score;
		
	/**
	 * Default constructor; creates a Swing program presenting a single window for actions pertaining to the EarTrainer class. 
	 * Its contents are defined by the invocation of setMenuBar, setPlayPanel, and setButtonPanel.
	 */
	public EarTrainer()
	{
		super("EarTrainer");
		
		// The main panel utilizes a GridLayout manager comprised of two rows and one column
		setLayout(new GridLayout(2,1));
		
		// Setting the frame's icon image with an existing image included in this program's directory
		earTrainerIcon = new ImageIcon("earTrainerIcon.png");
		setIconImage(earTrainerIcon.getImage());
		
		// Setting the frame's size and close operation
		setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// Invoking the following methods to add the menu bar and contents of the two rows of the main panel
		setMenuBar(); 
		setPlayPanel(); 
		setButtonPanel(); 
		
		setVisible(true);
		
		// Create the initial instance of Intervals, where it's default setting (isDiatonic = true) instantiates its ArrayList 
		// with 8 out of 12 possible IntervalWavFile objects
		setIntervals(true);
	
	} // End of default constructor EarTrainer
	
	/**
	 * Overwrites the EarTrainer instance's intervalsDemo variable with a new instance of Intervals based on its full constructor 
	 * (given the boolean isDiatonic).
	 *
	 * @param isDiatonic - determines if the Intervals class is to store 8 out of 12 files which represent intervals of the major
	 *  scale (true, diatonic) into its ArrayList of IntervalWavFiles which represent it. If set to false, then all 12 files are 
	 *  added to represent the chromatic scale.
	 */
	private void setIntervals(boolean isDiatonic)
	{
		intervalsDemo = new Intervals(isDiatonic);
		repeat = false;	// Tracks the event in which the user has selected the "Play" button
		answered = false;	
		intervalPlayed = null;
		correct = 0;
		incorrect = 0;
		score = 0;
	}
	
	/**
	 * Called from the default constructor to create and add a menu bar comprised of the menu options and actions of resetting the 
	 * Intervals variable within the current instance.
	 */
	private void setMenuBar()
	{
		// The outermost menu option to be added to the menu bar
		options = new JMenu("Options");
		
		// A submenu added to the above JMenu object
		reset = new JMenu("Reset");
		options.add(reset);
		
		// Two menu items whose action listenes are registered as an instance of the inner class MenuSelectionListener are added to 
		// the above submenu. These action listeners interact with the EarTrainer's intervalDemo variable by setting it to a new 
		// instance of Intervals based on its chromatic or major (diatonic) modes.
		chromaticMode = new JMenuItem("Chromatic");
		chromaticMode.addActionListener(new MenuSelectionListener());
		reset.add(chromaticMode);
		
		diatonicMode = new JMenuItem("Diatonic (major)");
		diatonicMode.addActionListener(new MenuSelectionListener());
		reset.add(diatonicMode);
		
		// Creating and adding the JMenuBar to the JFrame
		menuBar = new JMenuBar();
		menuBar.add(options);
		setJMenuBar(menuBar);
	}
	
	/**
	 * Creates a panel comprised of the following items to be added to the first row of the main panel
	 */
	private void setPlayPanel()
	{
		// Creating a JPanel whose layout manager utilizes a GridLayout configuration of three rows and one column
		playPanel = new JPanel();
		playPanel.setLayout(new GridLayout(3, 1));
		
		// Creating and adding a title label to the first row of the panel
		titleLabel = new JLabel("Interval Ear Trainer");
		titleLabel.setHorizontalAlignment(JLabel.CENTER);
		playPanel.add(titleLabel);
		
		// Definining and setting an initial message to a new JTextArea object
		areaMessage = "Press 'Play' to begin practicing your ability to identify musical intervals.";
		messageArea = new JTextArea(areaMessage, TEXT_AREA_ROWS, TEXT_AREA_COLUMNS);
		
		messageArea.setEditable(false);
		messageArea.setLineWrap(true);
		messageArea.setWrapStyleWord(true);
		
		// Adding the JTextArea object to the second row of the panel
		playPanel.add(messageArea);
		
		playButton = new JButton("Play");
		playButton.addActionListener(new PlayListener());
		playPanel.add(playButton);
		
		playBorder = BorderFactory.createLoweredBevelBorder();;
		playPanel.setBorder(playBorder);
		
		// Panel is added to the main panel's uppermost row of its GridLayout
		add(playPanel);
	}
		
	/**
	 * Creates 12 buttons to represent each possible interval to be identified by the user, which are then added to a panel for the 
	 * second row of the pain panel by invoking the method addButtonToSelectionPanel.
	 */
	private void setButtonPanel()
	{
		selectionPanel = new JPanel();
		
		// Each button is named based on every possible interval from within an octave
		addButtonToSelectionPanel("m2");
		addButtonToSelectionPanel("M2");
		addButtonToSelectionPanel("m3");
		addButtonToSelectionPanel("M3");
		addButtonToSelectionPanel("P4");
		addButtonToSelectionPanel("Tritone"); // may be an augmented fourth (A4) or diminished fifth (d5)
		
		addButtonToSelectionPanel("P5");
		addButtonToSelectionPanel("m6");
		addButtonToSelectionPanel("M6");
		addButtonToSelectionPanel("m7");
		addButtonToSelectionPanel("M7");
		addButtonToSelectionPanel("Octave"); // may be a perfect unison (P1) or octave (P8)
		
		// Creates and adds a titled border to the panel
		selectionBorder = BorderFactory.createTitledBorder("Intervals");
		selectionPanel.setBorder(selectionBorder);
		
		// Adds panel to the second row of the main panel
		add(selectionPanel);
	} 
	
	/**
	 * Creates a JButton of the given interval symbol value, assigns an action listener of the subclass IntervalSelectionListener,
	 * and adds the button to the panel which contains the 12 possible options in identifying a given interval.
	 *
	 * @param intervalSymbol - an abbreviation for one of the 12 possible intervals within an octave
	 */
	private void addButtonToSelectionPanel(String intervalSymbol)
	{
		JButton aButton = new JButton(intervalSymbol);
		aButton.addActionListener(new IntervalSelectionListener());
		selectionPanel.add(aButton);
		
	} 
	
	/**
	 * Private inner class MenuSelectionListener
	 */
	private class MenuSelectionListener implements ActionListener
	{
		String selection;
		
		/**
		 * Determines the new instance of Intervals to be created based on the two JMenuItem options of "Chromatic" and "Diatonic 
		 * (major)", where the former sets the Intervals instance of isBoolean to false and the latter sets it to true, creating an 
		 * ArrayList of IntervalWavFiles  which appropriately represent the mode selected.
		 *
		 * @param e - an event generated by selecting one of the 2 JMenuItem objects representing the major and chromatic scales
		 */
		public void actionPerformed(ActionEvent e)
		{
			selection = e.getActionCommand();
			
			if (selection.equals("Chromatic"))
			{
				setIntervals(false); // Includes all possible interval files
				messageArea.setText("");
				messageArea.setText("Mode: " + Intervals.KEY + " chromatic"); // Presents the new mode/scale to the user
			}
			else if (selection.equals("Diatonic (major)"))
			{
				setIntervals(true); // Includes 8 of the 12 files
				messageArea.setText("");
				messageArea.setText("Mode: " + Intervals.KEY + " major"); // Presents the new mode/scale to the user
			}
		}
		
	} // End of class MenuSelectionListener
	
	/**
	 * Private inner class PlayListener
	 */
	private class PlayListener implements ActionListener
	{
		String selection;
		
		public void actionPerformed(ActionEvent e)
		{
			selection = e.getActionCommand();
			
			if (!(intervalsDemo.getIntervals().isEmpty()))
			{
				if ((selection.equals("Play")) && (!repeat))
				{
					intervalPlayed = intervalsDemo.playRandomClip();
					repeat = true;
				}
				else if ((selection.equals("Play")) && (repeat))
					intervalPlayed = intervalsDemo.repeatClip();
			}
			
			answered = false;
		}
		
	} 
	
	/**
	 * Private inner class IntervalSelectionListener
	 */	
	private class IntervalSelectionListener implements ActionListener
	{
		String input;
		
		public void actionPerformed(ActionEvent e)
		{
			input = e.getActionCommand();
			
			if (intervalPlayed == null)
				System.out.println(""); // Does nothing; no interval has been played.
			else if (answered)
				System.out.println(""); // Also does nothing; the user has already attempted an answer.
				
			else if ((input.equals(intervalPlayed)) || 
				((input.equals("Tritone")) && (intervalPlayed.equals("A4"))) || // A tritone may be called an augmented 4th (A4)
				((input.equals("Tritone")) && (intervalPlayed.equals("d5"))) || // or diminished 5th (d5),
				((input.equals("Octave")) && (intervalPlayed.equals("P1"))) ||  // and an octave a perfect unison (P1)
				((input.equals("Octave")) && (intervalPlayed.equals("P8"))))	// or perfect 8th (P8).
			{
				correct ++; 
				answered = true;
				messageArea.setText("");
				intervalsDemo.removeInterval(intervalPlayed);
				messageArea.setText(intervalsDemo.getFullIntervalName() + " is correct. \n");
			}
			else // If the user selection is incorrect
			{
				incorrect ++;
				answered = true;
				messageArea.setText("");
				messageArea.setText("Wrong. That was a " + intervalsDemo.getFullIntervalName().toLowerCase() + ". \n");
			}
			
			if (intervalsDemo.getIntervals().isEmpty()) // When the Intervals' ArrayList of IntervalWavFile objects is empty
			{
				answered = true;
				score = ((correct) / (correct + incorrect)) * 100;
				areaMessage = String.format("Exercise completed with a score of %.2f%%. You may try again by selecting a mode from the options menu.", score);
				messageArea.setText("");
				messageArea.setText(areaMessage);
			}
			
			repeat = false;
		}
	} 
		
} // End of class EarTrainer
