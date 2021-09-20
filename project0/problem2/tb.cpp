#include "tb.h"
#include <stdlib.h>
#include <time.h>

void tb::source()
{
	inData.write(0);
	rst.write(0);
	wait();
	rst.write(1);
	wait();

	sc_uint<12> tmp;
	srand(time(0));

	for(int i = 0; i < 32; ++i)
	{
		tmp = ((rand() % 2) << 8) + ((rand() % 16) << 4) + (rand() % 2);
		inData.write(tmp);
		wait();
	}
}

void tb::sink()
{
	for (int i = 0; i < 32; ++i)
	{
		wait();
	}

	sc_stop;
}	
