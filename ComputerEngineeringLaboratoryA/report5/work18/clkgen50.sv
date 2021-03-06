module clkgen1m
(
	input	logic clk50,
	output	logic	clk1
);
	reg	[5:0]	prescale;
	always_ff @(posedge clk50)
		if(prescale == 49)
		begin
			prescale	<=	0;
			clk1		<=	~clk1;
		end
		else
		begin
			prescale	<=	prescale+1;
			clk1		<=	clk1;
		end
endmodule
