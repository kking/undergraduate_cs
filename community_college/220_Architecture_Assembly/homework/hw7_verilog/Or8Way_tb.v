//-----------------------------------------------------
// Design Name : Xor Testbench
// File Name   : Or_tb.v
// Function    : Testbench for Xor gate
// Coder       : King
// Date        : 13 May, 2019
//-----------------------------------------------------

module Or8Way_tb_tb;
		/* Variable Setup */
		reg[7:0] in; // inputs as registers
		wire out; // outputs as wires (one bit default)
		
		// Create chip instance and connect variables
		Or8Way o8w (
			.in (in),
			.out (out)
		);
		
		/* Pulsing Clock for Test */
		// changes phase after each timestep
		reg clk = 0;
		always #1 clk = !clk;
		
		/* Test Values */
		// #1 means wait one timestep
		initial begin
			in = 8'b0000_0000; // initial value
			
			#1
			in = 8'b1111_1111;
			
			#1
			in = 8'b0001_0000;
			
			#1
			in = 8'b0000_0001;
			
			#1
			in = 8'b0010_0110;
			
			#1 
			$stop; // stops after last timestep
		end
		
		/* Run Test */
		// display happens only once
		// monitor runs whenever variables changes
		initial begin
			$display("| %8s | %8s |", "in", "out");
			$monitor("| %8b | %8b |", in, out);
		end
		
endmodule // End of Or8Way_tb