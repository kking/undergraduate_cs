// ========================================================
// File name: key_input.s
// Programmer: King
// Date last modified: 25 April, 2019
// ========================================================

.text                    // Indicates start of ASM code

.global _start

_start:
  MOV R7, #3             // Set R7 to system call for screen input
  MOV R0, #0             // Set R0 to use keyboard as input stream
  MOV R2, #10            // Length of string to from keyboard
  LDR R1, =message       // Save string into R1
  SWI 0                  // Runs system command (R7=input from keyboard)

_write:
  MOV R7, #4             // Set R7 to system call for screen output
  MOV R0, #1             // Set R0 to use monitor as output stream
  MOV R2, #10            // Length of string to output to screen
  LDR R1, =message       // Load string into R1
  SWI 0                  // Runs system command (R7=output to screen)

end:
  MOV R7, #1             // Storing system call number (exit)
  SWI 0                  // Software interrupt (tell OS to do R7)

.data                    // Start of data, not code (.text)

message:
  .ascii " "
