#include "types.h"
#include "stat.h"
#include "user.h"
#include "signals.h"

void h1(void)
{
  printf(1, "handler called\n");
  exit();
}

void h2(void) {
  printf(1, "oi!\n");
  exit();
}

int
main(int argc, char **argv)
{

  signal(SIGSEGV, &h2);

  printf(1, "%d\n", *(int*)10000000000); // Should raise SIGSEGV

  exit();
}
