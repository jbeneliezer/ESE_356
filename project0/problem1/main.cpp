#include "systemc.h"
#include "prob1_mod.h"
#include "prob1_drv.h"

int sc_main(int argc, char* argv[])
{
  sc_signal<bool> clock, reset, enable;
  sc_signal<sc_uint<4> > din, qout;
  sc_signal<sc_lv<4> > dout;

  tristate_reg* tr1 = new tristate_reg("tristate_reg_tr1");
  tr1->clock(clock);

  sc_clock clk("clk", 20, SC_NS);

  sc_start();

  sc_stop();


  sc_trace_file *tfile = sc_create_vcd_trace_file("myvcdfile");

  sc_trace(tfile, signal_name, "signal_name");

  sc_close_vcd_trace_file(tfile);

  return(0);
}
