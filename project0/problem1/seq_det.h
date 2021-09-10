#include "systemc.h"

SC_MODULE(seq_det)
{
  	sc_in<bool> clk, rst, clr, data_in;
	sc_out<bool> data_out;

  	void prc_seq_det();
  	void prc_output();
	void prc_clear();
	void prc_reset();
  	sc_signal<bool> first, second, third, fourth;

  	SC_CTOR(seq_det)
  	{
    	SC_METHOD(prc_seq_det)
    	{
			sensitive << clk.pos();
    	}

    	SC_METHOD(prc_output)
    	{
    		sensitive << clk.pos() << first << second << third << fourth;
    	}

		SC_CTHREAD(prc_clear, clr.pos());
		SC_CTHREAD(prc_reset, rst.neg());

  	}
};

