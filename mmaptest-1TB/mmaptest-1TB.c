#include <stdio.h>
#include <sys/mman.h>

#define TERABYTE 0x10000000000UL

int main(int argc, char *argv[]) {

  void *ptr;
  void *res;

  ptr = (char *)(512 * 1024 * 1024); /* 0.5GB */

  /* try reserving 1TB block */
  res = mmap((void *)ptr, (size_t)TERABYTE, PROT_NONE, (MAP_ANON | MAP_PRIVATE),
             (-1), 0);
  if (res == (void *)MAP_FAILED) {
    printf("map failed\n");
  } else {
    printf("map succeeded\n");
    printf("wait until input\n");
    (void)getchar();
  }
}
