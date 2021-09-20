#include "systemc.h"
#include "communications.h"
#include "tb.h"

SC_MODULE (SYSTEM)
{
	tb* tb0;	
	communications* coms0;
  	sc_signal<bool> reset_sig, clear_sig;
	sc_signal<sc_uint<12> > inData_sig;
	sc_signal<sc_uint<4> > payload_sig;
	sc_signal<sc_uint<8> > count_sig, error_sig;
	sc_clock clk_sig;

	SC_CTOR(SYSTEM)
		: clk_sig("clk_sig", 20, SC_NS)
	{
		tb0 = new tb("tb0");
		coms0 = new communications("coms0");

		tb0->clk(clk_sig);
		tb0->rst(reset_sig);
		tb0->clr(clear_sig);
		tb0->inData(inData_sig);
		tb0->payload(payload_sig);
		tb0->count(count_sig);
		tb0->error(error_sig);

		coms0->clk(clk_sig);
		coms0->rst(reset_sig);
		coms0->clr(clear_sig);
		coms0->inData(inData_sig);
		coms0->payload(payload_sig);
		coms0->count(count_sig);
		coms0->error(error_sig);
	}

	~SYSTEM()
	{
		delete tb0;
		delete coms0;
	}
};

SYSTEM* top = NULL;	

int sc_main(int argc, char* argv[])
{
	top = new SYSTEM("top");

 	sc_trace_file *tfile = sc_create_vcd_trace_file("p2");

  	sc_trace(tfile, top->inData_sig, "inData");
  	sc_trace(tfile, top->payload_sig, "payload");
  	sc_trace(tfile, top->count_sig, "count");
  	sc_trace(tfile, top->error_sig, "error");
  	sc_trace(tfile, top->clk_sig, "clk");
  	sc_trace(tfile, top->reset_sig, "rst");
  	sc_trace(tfile, top->clear_sig, "clr");

  	sc_start(640, SC_NS);

   	sc_close_vcd_trace_file(tfile);

	sc_stop();

  	return(0);
}
