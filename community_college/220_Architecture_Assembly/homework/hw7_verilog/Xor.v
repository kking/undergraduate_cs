//-----------------------------------------------------
// Design name : Xor
// File Name   : Xor.v
// Function    : Xor chip (parameterized)
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------

module Xor #(parameter WIDTH = 1) // parameterized
				(input[WIDTH-1:0] a, b, output[WIDTH-1:0] out);
				
	assign out = ((a & ~b) | (~a & b));
	
endmodule // End of module Xor
