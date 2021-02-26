//-----------------------------------------------------
// Design Name : And Testbench
// File Name   : And_tb.v
// Function    : Testbench for And gate
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------

module And_tb;
		/* Variable Setup */
		reg a, b; // inputs as registers
		wire out; // outputs as wires (one bit default)
		
		// Create chip instance and connect variables
		And a1 (
			.a (a),
			.b (b),
			.out (out)
		);
		
		/* Pulsing Clock for Test */
		// changes phase after each timestep
		reg clk = 0;
		always #1 clk = !clk;
		
		/* Test Values */
		// #1 means wait one timestep
		initial begin
			a = 0; // initial values
			b = 0;
			
			#1
			b = 1;
			
			#1
			a = 1;
			b = 0;
			
			#1
			b = 1;
			
			#1 
			$stop; // stops after last timestep
		end
		
		/* Run Test */
		// display happens only once
		// monitor runs whenever variables changes
		initial begin
			$display("| a | b | out |");
			$monitor("| %b | %b |  %b  |", a, b, out);
		end
		
endmodule // End of And_tb
