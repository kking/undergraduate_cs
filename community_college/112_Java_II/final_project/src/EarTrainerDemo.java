/**
 * Course: CS112		Project: Final Project
 * Programmer: King		Date last modified: 11 December, 2017
 * 
 * File name: EarTrainerDemo.java
 *
 * Description: Demo program for the EarTrainer view class and Intervals model class.
 *
 * Purpose: This program is used to test the user's ability to identify an interval represented by a wav file stored within an 
 * object of class IntervalWavFile, where said file is passed through methods of AudioSystem, AudioInputStream, and Clip in order 
 * to playback its data through the system's audio device. An ArrayList of IntervalWavFile objects is automatically defined according 
 * 12 wav files created to represent each interval from within a musical octave, and its contents may be selected and removed at a 
 * specified or randomized index.
 *
 * Classes:
 * EarTrainer - A graphics-based program to operate the Ear Trainer application.
 * Intervals - A container which tracks the audio playback of wav files for several objects of the inner class IntervalWavFile.
 */
 
public class EarTrainerDemo
{
	public static void main(String[] args)
	{
		EarTrainer earTrainerApp = new EarTrainer();
	}
} 