// ===============================================================
// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.

// File name: mult.asm
// Programmer: King
// Date last modified: 04 March, 2019
// Line count: 18

// * Multiplies R0 and R1 and stores the result in R2.
// * R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.
// * This program assumes that R0>=0, R1>=0, and R0*R1<32768.
// ===============================================================
// ALGORITHM:
// 1. Set R2 to 0. This will store the resulting product, R1*R2.
// 2. Set RAM[i] to -(R1). This will represent the number of
//    loop iterations based on the first operand (R0), from RAM[i]
//    to 0 (exclusive).
// 3. If R0 <=0, go to (END) from step #5.
// 4. (LOOP) Evaluate the product of RAM[0] and RAM[1].
//    a. Store the value of the second operand (RAM[1]) in D.
//    b. Add data in D to R2.
//    c. Increment data in RAM[i] and store in D.
//    d. If data in D is < 0, go to (LOOP) from step #4.
// 5. (END) Run an infinite loop to end the program.
// ===============================================================

// Initialize product for RAM[2] to 0.
@R2     // A = R2
M = 0   // RAM[2] = 0

// Store multiplier; number of loop iterations based on first 
// operand (RAM[0]). 
// Following loop will increment from -(RAM[0]) to 0 (exclusive).
@R0     // A = R0
D = M   // D = RAM[0]
@i      // A = i
M = -D  // RAM[a] = -(RAM[0]); store loop data

// Goto END if RAM[0] <= 0; loop value must be > 0.
@END    // A = END
D;JLE   // If RAM[0] <= 0, PC = ROM[END]; else PC++

// Loop to evaluate product of RAM[0] and RAM[1].
(LOOP)
    // Obtain value of second operand (RAM[1]); constant data.
    @R1         // A = R1
    D = M       // D = RAM[1]

    // Add data from RAM[1] to RAM[2].
    @R2         // A = R2
    M = M + D   // RAM[2] = RAM[2] + RAM[1]

    // Increment RAM[i]; loop value.
    @i          // A = i
    MD = M + 1  // RAM[i] = RAM[i] + 1, D = RAM[i] + 1

    // Goto LOOP if loop value at RAM[i] < 0.
    @LOOP      // A = LOOP
    D;JLT      // If RAM[i] < 0, PC = ROM[LOOP]; else PC++

(END)
    // Goto END; runs an infinite loop to end the progam.
    @END       // A = END
    0;JMP      // PC = ROM[END]
