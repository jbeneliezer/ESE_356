#include "communications.h"

void communications::prc_recv()
{
	bool parity = inData[0];
	if (inData.read().range(11, 8) == 1)
	{
		payload.write(inData.read().range(7, 4));
		count.write(count.read() + 1);
	}
    for (sc_uint<4> i = 7; i > 3; --i)
	{
		parity = parity ^ inData.read()[i];
	}
	if (!parity)
	{
		error.write(error.read() + 1);
	}
}

void communications::prc_clear()
{
	payload.write(0);
}

void communications::prc_reset()
{
	count.write(0);
	error.write(0);
}