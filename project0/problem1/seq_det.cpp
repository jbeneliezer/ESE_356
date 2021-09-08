#include "seq_det.h"

void seq_det::prc_seq_det()
{
  	fourth = third;
	third = second;
  	second = first;
  	first = data;
}

void seq_det::prc_output()
{
  	seq_found = first & (!second) & third & fourth;
}
