#include <stdio.h>
#include <cilk/cilk.h>
#include <assert.h>
#include <sys/types.h>

#include <pthread.h>

#include <unistd.h>

int fib(int n)
{
  if (n < 2)
    return n;
  int x, y;
  x = cilk_spawn fib(n - 1);
  y = fib(n - 2);
  cilk_sync;
  return x + y;
}

int par_for()
{
  cilk_for(int i = 0; i < 11; i++)
  {
    // printf("%d", i);

    printf("%d", i);
    printf("\n");
  }
}

int main()
{
  // printf("%d", fib(10));
  par_for();
}
