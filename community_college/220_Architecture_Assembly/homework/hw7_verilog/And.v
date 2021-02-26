//-----------------------------------------------------
// Design name : And
// File Name   : And.v
// Function    : And chip (parameterized)
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------

module And #(parameter WIDTH = 1) // parameterized
				(input[WIDTH-1:0] a, b, output[WIDTH-1:0] out);
				
	assign out = (a & b);
	
endmodule // End of module And
