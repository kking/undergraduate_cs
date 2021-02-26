// ========================================================
// File name: cond_branch_string.s
// Programmer: King
// Date last modified: 25 April, 2019
// ========================================================
// Conditional Branching:
// CMP R1, R2    // R1 - R2; check CPRS flags:
//      R2 > R1, then negative flag would be enabled (1)
//      R2 < R1, then negative flag would be disabled (0)
//      R2 == R1, then zero flag would be enabled (1)
// ========================================================

.text                   // Start of ASM code

.global _start

_start:
  MOV R1, #1            // Store dec 1 into R1
  MOV R2, #10           // Store dec 10 into R2
  CMP R1, R2            // Compare R1 to R2
  BEQ vals_equal        // Branch if R1 == R2 to vals_equal label
  BGT r1_gt             // Else (R1 < R2), fall into r1_lt label

r1_lt:                  /* R1 < R2 */
  MOV R2, #20           // Set length of string
  LDR R1, =message_lt   // Load value in message_lt into R1
  B output              // Branch to output label

vals_equal:             /* R1 == R2 */
  MOV R2, #21           // Set length of string
  LDR R1, =message_eq   // Load value in message_eq into R1
  B output              // Branch to output label

r1_gt:                  /* R1 > R2 */
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

message_lt:
  .ascii "R1 is less than R2.\n"

message_eq:
  .ascii "R1 and R2 are equal.\n"

message_gt:
  .ascii "R1 is greater than R2.\n"
