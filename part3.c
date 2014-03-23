#include "types.h"
#include "stat.h"
#include "user.h"
#include "signals.h"


void handler(void) {
  printf(1, "handler called!\n");
}

int
main(int argc, char **argv)
{
  uint p;

  signal(SIGSEGV, &handler);
  p = *(int*)10000000000; // Should raise SIGSEGV

  p = p;
  printf(1, "Handled the signal and continued the program!\n");

  exit();
}
