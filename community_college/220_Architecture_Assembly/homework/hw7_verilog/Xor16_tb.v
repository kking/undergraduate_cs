//-----------------------------------------------------
// Design Name : Xor16 Testbench
// File Name   : Xor16_tb.v
// Function    : Testbench for Xor16 gate
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------

module Xor16_tb;
		/* Variable Setup */
		reg[15:0] a, b; // inputs as registers
		wire[15:0] out; // outputs as wires (one bit default)
		
		// Create chip instance and connect variables
		Xor#(16) x16 (
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
			a = 16'b0000_0000_0000_0000; // initial values
			b = 16'b0000_0000_0000_0000;
			
			#1 
			a = 16'b0000_0000_0000_0000;
			b = 16'b1111_1111_1111_1111;
			
			#1
			a = 16'b1111_1111_1111_1111;
			b = 16'b1111_1111_1111_1111;
			
			#1
			a = 16'b1010_1010_1010_1010;
			b = 16'b0101_0101_0101_0101;
			
			#1
			a = 16'b0011_1100_1100_0011;
			b = 16'b0000_1111_1111_0000;
			
			#1
			a = 16'b0001_0010_0011_0100;
			b = 16'b1001_1000_0111_0110;
			
			#1 
			$stop; // stops after last timestep
		end
		
		/* Run Test */
		// display happens only once
		// monitor runs whenever variables changes
		initial begin
			$display("| %16s | %16s | %16s |", "a", "b", "out");
			$monitor("| %16b | %16b | %16b |", a, b, out);
		end
		
endmodule // End of Xor16_tb
