//-----------------------------------------------------
// Design Name : Not
// File Name   : Not.v
// Function    : Not chip (parameterized)
// Coder       : King
// Date        : 06 May, 2019
//-----------------------------------------------------

module Not #(parameter WIDTH = 1) // parameterized
			(input[WIDTH-1:0] in, output[WIDTH-1:0] out);
			
	assign out = ~in;

endmodule //End Of Module Not
