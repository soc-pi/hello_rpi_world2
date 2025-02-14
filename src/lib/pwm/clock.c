#include "clock.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define BCM2835_PERI_BASE 0x3F000000
#define CLOCK_BASE (BCM2835_PERI_BASE + 0x101000)
#define BLOCK_SIZE (4 * 1024)

void setup_clock(volatile unsigned** clk) {
  int mem_fd;
  void* clk_map;

  if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
    printf("Failed to open /dev/mem\n");
    exit(-1);
  }

  clk_map = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, CLOCK_BASE);
  close(mem_fd);

  if (clk_map == MAP_FAILED) {
    printf("mmap error\n");
    exit(-1);
  }

  *clk = (volatile unsigned*)clk_map;
}
