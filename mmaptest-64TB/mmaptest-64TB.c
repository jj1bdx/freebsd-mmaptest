#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>

/* 64TB */
#define HYPERLARGESIZE 0x400000000000UL

int main(int argc, char *argv[]) {

  void *ptr;
  void *res;
  uint64_t size = HYPERLARGESIZE;

  ptr = (char *)(512 * 1024 * 1024); /* 0.5GB */

  /* try reserving an extremely large block */
  res = mmap((void *)ptr, (size_t)HYPERLARGESIZE, PROT_NONE,
             (MAP_ANON | MAP_PRIVATE), (-1), 0);
  if (res == (void *)MAP_FAILED) {
    printf("map failed\n");
  } else {
    printf("map succeeded: size=%" PRIu64 "\n", size);
    printf("wait until input\n");
    (void)getchar();
  }
}
