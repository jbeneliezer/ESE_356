#include "prob1_mod.h"

void seq_det::prc_seq_det()
{
  first = data;
  second = first;
  third = second;
  fourth = third;
}

void seq_det::prc_output()
{
  seq_found = first & (!second) & third & fourth;
}
