#include <ctype.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "../include/limiter.h"

const int64_t apply_limit(const int64_t * min, const int64_t * max,
			  const int64_t * number) {
  if(*number < *min) {
    return *min;
  } else if(*number > *max) {
    return *max;
  } else {
    return *number;
  }
}
