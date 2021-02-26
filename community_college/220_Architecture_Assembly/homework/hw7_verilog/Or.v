//-----------------------------------------------------
// Design name : Or
// File Name   : Or.v
// Function    : Or chip (parameterized)
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------

module Or #(parameter WIDTH = 1) // parameterized
				(input[WIDTH-1:0] a, b, output[WIDTH-1:0] out);
				
	assign out = (a | b);
	
endmodule // End of module Or
