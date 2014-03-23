#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char **argv)
{
  int k = test();

  printf(1, "%d\n", k); // Should raise SIGSEGV

  exit();
}
