#include <stdio.h>
#include <stdlib.h>

void get_sum_vals(int * sum, int a, int b)
{
  *sum = a + b;
}

int sum_vals(int a, int b)
{
  return a + b;
}

int main()
{
  int sum, * sum_p;

  get_sum_vals(sum_p, 2, 3);

  printf("\nValue of sum pointer %d\n", *sum_p);

  sum = sum_vals(2, 3);

  printf("\nValue of sum %d\n", sum);
}
