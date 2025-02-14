#include "pwm_setup.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define BCM2835_PERI_BASE 0x3F000000
#define PWM_BASE (BCM2835_PERI_BASE + 0x20C000)
#define BLOCK_SIZE (4 * 1024)

void setup_pwm(volatile unsigned** pwm) {
  int mem_fd;
  void* pwm_map;

  if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
    printf("Failed to open /dev/mem\n");
    exit(-1);
  }

  pwm_map = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, PWM_BASE);
  close(mem_fd);

  if (pwm_map == MAP_FAILED) {
    printf("mmap error\n");
    exit(-1);
  }

  *pwm = (volatile unsigned*)pwm_map;
}

void init_pwm(volatile unsigned* gpio, volatile unsigned* pwm, volatile unsigned* clk) {
  // Set GPIO18 to PWM0 function (Alt Fun 5)
  *(gpio + 1) = (*(gpio + 1) & ~(7 << 24)) | (2 << 24);

  // Stop PWM
  *(pwm + 0) = 0;

  // Stop PWM clock
  *(clk + 40) = 0x5A000000 | (1 << 5);
  usleep(10);

  // Configure PWM Clock - 50Hz
  // PWMDIV = 19.2MHz / 50Hz = 384000
  *(clk + 41) = 0x5A000000 | (384 << 12);
  *(clk + 40) = 0x5A000011;

  // Configure PWM
  *(pwm + 4) = 1000;  // Range = 1000
  *(pwm + 5) = 0;     // Initial duty cycle = 0
  *(pwm + 0) = 0x81;  // Enable PWM in MS mode
}
