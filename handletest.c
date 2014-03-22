#include "types.h"
#include "stat.h"
#include "user.h"

void
handler(void)
{
  printf(1, "handler called\n");
  exit();
}

int
main(int argc, char **argv)
{
  signal(0, handler);
  syscall(SIGKILL);

  printf(1, "%d\n", *(int *)1);

  return 0;
}
