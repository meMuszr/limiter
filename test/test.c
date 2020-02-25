#include  <assert.h>
#include <stdint.h>

#include "../include/limiter.h"

int main(void)
{
  int64_t min = 93;
  int64_t max = 100;
  int64_t amount = 95;
  assert(apply_limit(&min, &max, &amount) == amount);
  amount = 90;
  assert(apply_limit(&min, &max, &amount) == min);
  amount = 101;
  assert(apply_limit(&min, &max, &amount) == max);
}
