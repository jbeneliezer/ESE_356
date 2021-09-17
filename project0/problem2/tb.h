#include "systemc.h"

SC_MODULE(tb)
{
  	sc_in<bool> clk;
  	sc_out<bool> rst, clr;
	sc_out<sc_uint<12> > inData;
	sc_in<sc_uint<4> > payload;
	sc_in<sc_uint<8> > count;
	sc_in<sc_uint<8> > error;

	void source();
	void sink();

	SC_CTOR(tb)
	{
		SC_CTHREAD(source, clk.pos());
		SC_CTHREAD(sink, clk.pos());
	}
};
