// ========================================================
// File name: cond_branch.s
// Programmer: King
// Date last modified: 25 April, 2019
// ========================================================
// Conditional Branching:
// CMP R1, R2    // R1 - R2, check CPRS flags:
//      R2 > R1, then negative flag would be enabled (1)
//      R2 < R1, then negative flag would be disabled (0)
//      R2 == R1, then zero flag would be enabled (1)
// ========================================================

.text                    // Indicates start of ASM code

.global _start

_start:                 // Creating label
  MOV R1, #10           // Store dec 10 in R1
  MOV R2, #10           // Store dec 10 in R2
  CMP R1, R2            // Compare R1 to R2
  BEQ vals_equal        // Branch if R1 == R2 to label
  BGT r1_gt             // Else (R1 < R2), fall into rl_lt label

r1_lt:
  MOV R0, #2            // R0 storing 2 indicates R1 < R2
  B end                 // Branch to end

r1_gt:
  MOV R0, #3            // R0 storing 3 indicates R1 > R2
  B end                 // Branch to end

vals_equal:
  MOV R0, #1            // R0 storing 1 indicates R1 == R2

end:
  MOV R7, #1            // Storing system call number (exit)
  SWI 0                 // Software interrupt (tell OS to do R7)
