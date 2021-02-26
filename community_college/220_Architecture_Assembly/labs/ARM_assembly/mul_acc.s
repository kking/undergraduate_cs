// ========================================================
// File name: mul_acc.s
// Programmer: King
// Date last modified: 25 April, 2019
// ========================================================

.text                   // Indicates start of ASM code

.global _start

_start:                 /* Creating label */
  MOV R1, #0xA          // Set R1 to hex value A, dec 10
  MOV R2, #0x14         // Set R2 to hex value 14 (dec 20)
  MOV R3, #0x5          // Set R3 to hex value 5 (dec 5)
  MLA  R0, R1, R2, R3   // R0 = R1 * R2 + R3 = 10 * 20 + 5 = 205
  MOV R7, #1            // Storing system call number (exit)
  SWI 0                 // Software interrupt (tell OS to do R7)

.data                   // Start of data, not code (.text)

message:
  .ascii " "
