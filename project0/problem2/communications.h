#include "systemc.h"

SC_MODULE(communications)
{
  	sc_in<bool> clk, rst, clr;
	sc_in<sc_uint<12> > inData;
	sc_out<sc_uint<4> > payload;
	sc_out<sc_uint<8> > count;
	sc_out<sc_uint<8> > error;

	void prc_recv();
	void prc_clear();
	void prc_reset();
	sc_signal<bool> parity;

  	SC_CTOR(communications)
  	{
    	SC_METHOD(prc_recv)
    	{
			sensitive << clk.pos();
    	}

		SC_CTHREAD(prc_clear, clr.pos());
		SC_CTHREAD(prc_reset, rst.neg());

  	}
};

