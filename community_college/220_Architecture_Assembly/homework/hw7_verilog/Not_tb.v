//-----------------------------------------------------
// Design Name : Not Testbench
// File Name   : Not_tb.v
// Function    : Testbench for Not gate
//-----------------------------------------------------

module Not_tb;
	/* Variable Setup */
	reg in; // inputs are registers
	wire out; // outputs are wires, one bit default

	// create chip instance and connect to inputs
	Not n1 (
		.in		(in),
		.out	(out)
	);

	/* Pulsing Clock for Test */
	// (changes phase after each timestep)
	reg clk = 0;
	always #1 clk = !clk; 

	/* Test Values */
	// #1 means wait one timestep
	initial begin
		in = 0;//initial values
		# 1 in = 1;

		# 1 $stop; //stop after last timestep
	end 

	/* Run Test */
	// display happens only once
	// monitor runs whenever variables change
	initial begin
		$display("|  in | out |"); 
		$monitor("|  %b  |  %b  |",in,out); 
	end 

endmodule //End of Not_tb
