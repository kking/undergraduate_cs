//-----------------------------------------------------
// Design name : DMux
// File Name   : DMux.v
// Function    : DMux chip
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------
// {a, b} = {in, 0} if sel == 0
//          {0, in} if sel == 1
//-----------------------------------------------------

module DMux (input in, sel, output a, b);
				
	wire notSel;
	
	not notSel(notSel, sel);
	and inNotSel(a, in, notSel);
	and inSel(b, in, sel);
	
endmodule // End of module DMux
