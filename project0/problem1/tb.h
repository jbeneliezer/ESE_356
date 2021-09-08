#include "systemc.h"

SC_MODULE(tb)
{
	sc_out<bool> clk, rst;
	sc_out<bool> data_tb;
	sc_in<bool> seq_found_tb;

	void source();
	void sink();

	SC_CTOR(tb)
	{
		SC_CTHREAD(source, clk.pos());
		SC_CTHREAD(sink, clk.pos());
	}
};
