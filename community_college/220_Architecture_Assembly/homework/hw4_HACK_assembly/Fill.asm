// ===================================================================
// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.

// File name: Fill.asm
// Programmer: King
// Date last modified: 04 March, 2019
// Line count: 23

// * Runs an infinite loop that listens to the keyboard input.
// * When a key is pressed (any key), the program blackens the screen, 
// i.e. writes "black" in every pixel; the screen should remain fully
// black as long as the key is pressed. 
// * When no key is pressed, the program clears the screen, i.e. 
// writes "white" in every pixel; the screen should remain fully clear
// as long as no key is pressed.
// ===================================================================
// ALGORITHM:
// 1. (RESET) Set starting index for fill to SCREEN (16384).
// 2. (KBD_LOOP) Run infinite loop listening to the keyboard input.
// 3. Store data from KBD in D. If a key is pressed, KBD > 0.
// 4. If KBD == 0, go to (SET_CLEAR).
//    a. Set data at D to 0 (white).
//    b. Go to (FILL_LOOP) through step #6.
// 5. Otherwise, set data at D to -1 (black).
// 6. (FILL_LOOP) Color or clear the screen based on data in D.
//    Note: SCREEN ranges from 16,384 to 24,575 (inclusive).
//    KBD is a pointer to the keyboard register at 24,576.
//    Thus, KBD can be used as a sentinel value for the 
//    coloring and clearning of the screen.
//    a. Set each bit at current fill index to data at colorVal 
//       (-1 == true, black; 0 == false, white).
//    b. Increment and store value of the new fill index.
//    c. If new fill index == KBD (24576), go to (RESET) through
//       step #1.
//    d. Otherwise, go to (KBD_LOOP) through step #2. 
// ===================================================================

// Set/reset the starting value for coloring or clearing the screen.
(RESET)
    // Set starting index for fill at SCREEN.
    @SCREEN     // A = SCREEN (16384)
    D = A       // D = SCREEN
    @fillIndex  // A = fillIndex
    M = D       // RAM[fillIndex] = SCREEN

// Infinite loop that listens to the keyboard input.
(KBD_LOOP)
    // Obtain value at KBD. If a key is pressed, RAM[KBD] > 0.
    @KBD        // A = KBD (24576; stores value of key pressed)
    D = M       // D = RAM[KBD]

    // If a key is not currently pressed, goto (SET_CLEAR).
    @SET_CLEAR  // A = SCREEN_CLEAR
    D;JEQ       // If RAM[KBD] == 0, PC = ROM[SET_CLEAR]

    // Otherwise, set D to -1 for coloring the screen.
    D = -1      // D = -1

// Loop that colors or clears the screen based on data in D.
(FILL_LOOP)
    // All 16 bits in RAM[vFillIndex] is set to 1 or 0.
    @fillIndex  // A = fillIndex
    A = M       // A = RAM[fillIndex]; vFillIndex
    M = D       // RAM[vFillIndex] = RAM[colorVal]

    // Increment current screen index.
    @fillIndex  // A = fillIndex
    MD = M + 1  // M = RAM[fillIndex] + 1
        
    // If screen is completely colored, goto (RESET).
    @KBD        // A = KBD (16386)
    D = D - A   // D = vFillIndex - KBD
    @RESET      // A = RESET
    D;JEQ       // If fillIndex - KBD == 0, PC = ROM[RESET]

    // Otherwise, goto (KBD_LOOP).
    @KBD_LOOP   // A = KBD_LOOP
    0; JMP      // PC = ROM[KBD_LOOP]

// Sets D to 0 for clearing the screen.
(SET_CLEAR)
    // Set D to 0.
    D = 0       // RAM[colorVal] = 0
  
    // Proceed through (FILL_LOOP).
    @FILL_LOOP  // A = FILL_LOOP
    0;JMP       // PC = ROM[FILL_LOOP]
