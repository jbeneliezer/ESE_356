#include "seq_det.h"

void seq_det::prc_seq_det()
{
	fourth = third;
	third = second;
	second = first;
	first = data_in;
}

void seq_det::prc_output()
{
  	data_out = first & (!second) & third & fourth;
}

void seq_det::prc_clear()
{
	data_out = false;
}

void seq_det::prc_reset()
{
	first = second = third = fourth = false;
}