// ========================================================
// File name: hello_world.s
// Programmer: King
// Date last modified: 25 April, 2019
// ========================================================

.text                    // Indicates start of ASM code

.global _start

_start:                  // Creating label
  MOV R7, #4             // Set R7 to system call for outputting to screen
  MOV R0, #1             // Set R0 to use monitor as output stream
  MOV R2, #12            // Length of string to output to screen
  LDR R1, =message       // Load a message to display
  SWI 0                  // Runs system command (R7=output to screen)

end:
  MOV R7, #1             // Storing system call number (exit)
  SWI 0                  // Software interrupt (tell OS to do R7)

.data                    // Start of data, not code (.text)

message:
  .ascii "Hello World\n"


