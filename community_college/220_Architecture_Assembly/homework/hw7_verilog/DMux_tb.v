//-----------------------------------------------------
// Design Name : DMux Testbench
// File Name   : DMux_tb.v
// Function    : Testbench for DMux gate
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------

module DMux_tb;
		/* Variable Setup */
		reg in, sel; // inputs as registers
		wire a, b; // outputs as wires (one bit default)
		
		// Create chip instance and connect variables
		DMux dm1 (
			.in (in),
			.sel (sel),
			.a (a),
			.b (b)
		);
		
		/* Pulsing Clock for Test */
		// changes phase after each timestep
		reg clk = 0;
		always #1 clk = !clk;
		
		/* Test Values */
		// #1 means wait one timestep
		initial begin
			in = 0; // initial values
			sel = 0;
			
			#1
			sel = 1;
			
			#1
			in = 1;
			sel = 0;
			
			#1
			sel = 1;
			
			#1 
			$stop; // stops after last timestep
		end
		
		/* Run Test */
		// display happens only once
		// monitor runs whenever variables changes
		initial begin
			$display("| in | sel | a | b |");
			$monitor("| %b  | %b   | %b | %b |", in, sel, a, b);
		end
		
endmodule // End of DMux_tb