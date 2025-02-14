#ifndef PWM_SETUP_H
#define PWM_SETUP_H

void setup_pwm(volatile unsigned** pwm);
void init_pwm(volatile unsigned* gpio, volatile unsigned* pwm, volatile unsigned* clk);

#endif  // PWM_SETUP_H
