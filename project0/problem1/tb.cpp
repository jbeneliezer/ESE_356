#include "tb.h"
#include <stdlib.h>
#include <time.h>

void tb::source()
{
	data_tb.write(0);
	rst.write(1);
	wait();
	rst.write(0);
	wait();

	bool tmp;
	srand(time(0));

	for(int i = 0; i < 64; ++i)
	{
		tmp = rand() % 2;
		data_tb.write(tmp);
	}
}

void tb::sink()
{
	bool results;

	sc_trace_file *tfile = sc_create_vcd_trace_file("myvcdfile");

  	sc_trace(tfile, data_tb, "data_tb");
  	sc_trace(tfile, results, "results");
  	sc_trace(tfile, clk, "clk");
  	sc_trace(tfile, rst, "rst");

  	sc_close_vcd_trace_file(tfile);

	for (int i = 0; i < 64; ++i)
	{
		results = seq_found_tb;
		wait();
		cout << i << ":\t" << results << endl;
	}

	sc_stop;
}	
