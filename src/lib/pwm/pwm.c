#include "pwm.h"

#include <stdio.h>

void set_pwm(volatile unsigned* pwm, int value) {
  *(pwm + 5) = value;
}
