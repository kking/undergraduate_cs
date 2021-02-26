// ========================================================
// File name: cond_branch_input.s
// Programmer: King
// Date last modified: 29 April, 2019
// ========================================================
// Conditional Branching:
// CMP R1, R2           // R1 - R2; check CPRS flags:
//      R2 > R1, then negative flag would be enabled (1)
//      R2 < R1, then negative flag would be disabled (0)
//      R2 == R1, then zero flag would be enabled (1)
// ========================================================
// note: this program results in unexpected behavior. If I can
// figure out how to read multiple console inputs into different
// registers I will return to this.
// ========================================================

.text                   // Start of ASM code

.global _start

_start:
  MOV R7, #4            // Set R7 to system call for screen output
  MOV R0, #1            // Set R0 to use monitor as output stream
  MOV R2, #52           // Set length of output string
  LDR R1, =prompt       // Load value in prompt into R1
  SWI 0                 // Runs system command (R7=output to screen)

read:
  MOV R7, #3            // Set R7 to system call for screen input
  MOV R0, #0            // Set R0 to use keyboard as input stream
  MOV R2, #2            // Length of string from input
  LDR R3, =value_r3     // Load first input value into R3
  SWI 0                 // Runs system command (R7=input from keyboard)
  LDR R4, =value_r4     // Load second value into R4
  SWI 0                 // Runs system command (R7=input from keyboard)

compare:
  CMP R3, R4            // Compare R3 to R4
  BEQ vals_equal        // Branch to label if R3 == R4
  BGT r3_gt             // Else (R3 < R4), fall into r3_lt label

r3_lt:                  /* R3 < R4 */
  MOV R2, #20           // Set length of string
  LDR R1, =message_lt   // Load value in message_lt into R1
  B output              // Branch to output label

vals_equal:             /* R3 == R4 */
  MOV R2, #21           // Set length of string
  LDR R1, =message_eq   // Load value in message_eq into R1
  B output              // Branch to output label

r3_gt:                  /* R3 > R4 */
  MOV R2, #23           // Set length of string
  LDR R1, =message_gt   // Load value in message_gt into R1

output:
  MOV R7, #4            // Set R7 to system call for screen output
  MOV R0, #1            // Set R0 to use monitor as output stream
  SWI 0                 // Runs system command (R7=output to screen)

end:
  MOV R7, #1            // Storing system call number (exit)
  SWI 0                 // Software interrupt (tell OS to do R7)

.data                   // Start of data

prompt:
  .ascii "Enter values for R3 and R4, each on separate lines.\n"

value_r3:
  .ascii " "

value_r4:
  .ascii " "

message_lt:
  .ascii "R3 is less than R4.\n"

message_eq:
  .ascii "R3 and R4 are equal.\n"

message_gt:
  .ascii "R3 is greater than R4.\n"
