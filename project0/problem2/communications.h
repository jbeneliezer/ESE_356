#include "systemc.h"

SC_MODULE(communications)
{
  	sc_in<bool> clock, reset, clear;
	sc_out<bool> data_out;
	sc_in<uint<12> > inData;

  	void prc_seq_det();
  	void prc_output();
	void prc_clear();
	void prc_reset();
  	sc_signal<bool> fireset, second, third, fourth;

  	SC_CTOR(communications)
  	{
    	SC_METHOD(prc_seq_det)
    	{
			sensitive << clock.pos();
    	}

    	SC_METHOD(prc_output)
    	{
    		sensitive << fireset << second << third << fourth;
    	}

		SC_CTHREAD(prc_clear, clear.pos());
		SC_CTHREAD(prc_reset, reset.neg());

  	}
};

