#include "types.h"
#include "stat.h"
#include "user.h"
#include "signals.h"

uint k, done, ticks, trials;

void h2(void) {
  if (trials == k++)
    done = 1;
}

int
main(int argc, char **argv)
{
  if (argc != 2) {
    printf(1, "usage: part4 <number of trials>\n");
    exit();
  }

  trials = atoi(argv[1]);
  uint start, end, p;
  signal(SIGSEGV, &h2);

  start = uptime();
  while (!done)
    p = *(uint*)10000000000;
  end = uptime();

  p = p;
  ticks = end - start;

  printf(1, "Finished. %d signals raised in ~%dms\n", trials, ticks * 100);

  exit();
}
