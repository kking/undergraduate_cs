// ========================================================
// File name: uncond_branch.s
// Programmer: King
// Date last modified: 25 April 2019
// ========================================================

.text                   // Indicates start of ASM code

.global _start

_start:                 /* Creating label */
  MOV R0, #0x14         // Store hex 14 (dec 20)
  B end                 // Unconditional branch to label end
  MOV R0, #0xB          // Store hex B (dec 11)

end:
  MOV R7, #1            // Storing system call number (exit)
  SWI 0                 // Software interrupt (tell OS to do R7)

.data                   // Start of data, not code (.text)

message:
  .ascii " "