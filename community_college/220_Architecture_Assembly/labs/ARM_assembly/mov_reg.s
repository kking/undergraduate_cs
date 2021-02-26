// ========================================================
// File name: mov_reg.s
// Programmer: King
// Date last modified: 25 April, 2019
// ========================================================

.text           // Indicates start of ASM code

.global _start

_start:         // Creating label
  MOV R0, #71   // Storing decimal value 71 into register 0
  MOV R7, #1    // Storing system call number (exit)
  SWI 0         // Software interrupt (tell OS to do R7)
