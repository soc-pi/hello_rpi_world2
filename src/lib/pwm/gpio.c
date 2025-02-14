#include "gpio.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define BCM2835_PERI_BASE 0x3F000000
#define GPIO_BASE (BCM2835_PERI_BASE + 0x200000)
#define BLOCK_SIZE (4 * 1024)

void setup_gpio(volatile unsigned** gpio) {
  int mem_fd;
  void* gpio_map;

  if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
    printf("Failed to open /dev/mem\n");
    exit(-1);
  }

  gpio_map = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, GPIO_BASE);
  close(mem_fd);

  if (gpio_map == MAP_FAILED) {
    printf("mmap error\n");
    exit(-1);
  }

  *gpio = (volatile unsigned*)gpio_map;
}
