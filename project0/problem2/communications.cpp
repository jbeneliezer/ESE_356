#include "communications.h"

void seq_det::prc_recv()
{
	header = inData[11:8]
	data = inData[7:4]
	parity = inData[0]
	if (header == 1)
	{
		payload = data;
		++count;
	}
}

void seq_det::prc_parity_check()
{
    for (sc_uint<3> i = 0; i < 4; ++i)
	{
		parity ^= data[i];
	}
	if (!parity)
	{
		++error;
	}
}

void seq_det::prc_clear()
{
	data_out = false;
}

void seq_det::prc_reset()
{
	first = second = third = fourth = false;
}