#include "systemc.h"

SC_MODULE(seq_det)
{
  sc_in<bool> clock, data;
  sc_out<bool> seq_found;

  void prc_seq_det();
  void prc_output();
  sc_signal<bool> first, second, third, fourth;

  SC_CTOR(seq_det)
  {
    SC_METHOD(prc_seq_det)
    {
      sensitive_pos << clock;
    }

    SC_METHOD(prc_output)
    {
      sensitive_pos << first << second << third << fourth;
    }

  }
};

