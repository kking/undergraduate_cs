// ========================================================
// File name: add.s
// Programmer: King
// Date last modified: 25 April, 2019
// ========================================================

.text                    // Indicates start of ASM code

.global _start

_start:                  // Creating label
  MOV R1, #0xA           // Set R1 to hex value A, dec 10
  ADD R0, R1, #0x14      // R0 = R1 + hex 14 (dec 20)
  MOV R7, #1             // Storing system call number (exit)
  SWI 0                  // Software interrupt (tell OS to do R7)

.data                    // Start of data, not code (.text)

message:
  .ascii " "
