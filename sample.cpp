#include <iostream>

#include <cilk/cilk.h>
#include <assert.h>
#include <vector>

using namespace std;
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

int main()
{
    // cout << fib(10);
    vector<int> vec;

    cilk_for(int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }

    cilk_for(vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
    {
        cout << *it << endl;
    }
}