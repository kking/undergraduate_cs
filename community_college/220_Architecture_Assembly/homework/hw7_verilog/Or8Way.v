//-----------------------------------------------------
// Design name : Or8Way
// File Name   : Or8Way.v
// Function    : Xor chip
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------

module Or8Way (input[7:0] in, output out);
				
	assign out = (in[7] | in[6] | in[5] | in[4] | 
					in[3] | in[2] | in[1] | in[0]);
	
endmodule // End of module Or8Way
