#include "systemc.h"
#include "seq_det.h"
#include "tb.h"

SC_MODULE (SYSTEM)
{
	tb* tb0;	
	seq_det *seq_det0;
  	sc_signal<bool> reset_sig, enable_sig;
  	sc_signal<sc_uint<4> > din, qout;
  	sc_signal<sc_lv<4> > dout;
	sc_clock clk_sig;

	SC_CTOR(SYSTEM)
		: clk_sig("clk_sig", 20, SC_NS)
	{
		tb0 = new tb("tb0");
		tb0->clk(clk_sig);
		seq_det0 = new seq_det("seq_det0");
	}

	~SYSTEM()
	{
		delete tb0;
		delete seq_det0;
	}
}


SYSTEM* top = NULL;	

int sc_main(int argc, char* argv[])
{

  	sc_clock clk("clk", 20, SC_NS);

  	sc_start();

  	

  	return(0);
}
