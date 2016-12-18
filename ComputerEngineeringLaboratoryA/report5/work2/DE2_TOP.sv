// --------------------------------------------------------------------
// Copyright (c) 2011 by Gian. 
// --------------------------------------------------------------------
//
// Permission:
//
//   Gian grants permission to use and modify this code for use
//   in synthesis for all educational purpose.
//
// Disclaimer:
//
//   This VHDL/Verilog or C/C++ source code is intended as a design reference
//   which illustrates how these types of functions can be implemented.
//   It is the user's responsibility to verify their design for
//   consistency and functionality through the use of formal
//   verification methods.  Gian provides no warranty regarding the use 
//   or functionality of this code.
//
// --------------------------------------------------------------------
//
// Major Functions:	DE2 TOP LEVEL 
//
// --------------------------------------------------------------------
//
// Revision History :
// --------------------------------------------------------------------
//   Ver  :| Author            :| Mod. Date :| Changes Made:
//   V1.0 :| Gian              :| 08/08/11  :| Initial Revision
//   V2.0 :| Gian              :| 16/10/15  :| Convert to SystemVerilog
// --------------------------------------------------------------------

module DE2_TOP (
////////////////////////	Clock Input	 	////////////////////////
  input logic	iCLK_50,				//	50 MHz
////////////////////////	Push Button		////////////////////////
  input logic [3:0] iKEY,				//	Pushbutton[3:0]
////////////////////////	DPDT Switch		////////////////////////
  input logic [17:0] iSW,				//	Toggle Switch[17:0]
////////////////////////	7-SEG Dispaly	////////////////////////
  output logic [6:0] oHEX0_D,				//	Seven Segment Digit 0
  output logic [6:0] oHEX1_D,				//	Seven Segment Digit 1
  output logic [6:0] oHEX2_D,				//	Seven Segment Digit 2
  output logic [6:0] oHEX3_D,				//	Seven Segment Digit 3
  output logic [6:0] oHEX4_D,				//	Seven Segment Digit 4
  output logic [6:0] oHEX5_D,				//	Seven Segment Digit 5
  output logic [6:0] oHEX6_D,				//	Seven Segment Digit 6
  output logic [6:0] oHEX7_D,				//	Seven Segment Digit 7
////////////////////////////	LED		////////////////////////////
  output logic [8:0] oLEDG,				//	LED Green[8:0]
  output logic [17:0] oLEDR,				//	LED Red[17:0]
////////////////////////////	UART	////////////////////////////
  output logic oUART_TXD,				//	UART Transmitter
  input logic iUART_RXD					//	UART Receiver
);

//===========================================================================
// PARAMETER declarations
//===========================================================================


///////////////////////////////////////////////////////////////////
//=============================================================================
// REG/WIRE declarations
//=============================================================================



//=============================================================================
// Structural coding
//=============================================================================
//assign oLEDR[0] = iSW[0];
//assign oLEDG[0] = iKEY[0];
	assign	oLEDR[0]	=	iSW[0];
	assign	oLEDR[1]	=	~iSW[1];

	assign	oLEDR[2]	=	iSW[2];
	assign	oLEDR[3]	=	iSW[3];
	assign	oLEDR[4]	=	iSW[2]	&	iSW[3];

	assign	oLEDR[5]	=	iSW[4];
	assign	oLEDR[6]	=	iSW[5];
	assign	oLEDR[7]	=	iSW[4]	|	iSW[5];

	assign	oLEDR[8]	=	iSW[6];
	assign	oLEDR[9]	=	iSW[7];
	assign	oLEDR[10]	=	iSW[6]	^	iSW[7];
endmodule

