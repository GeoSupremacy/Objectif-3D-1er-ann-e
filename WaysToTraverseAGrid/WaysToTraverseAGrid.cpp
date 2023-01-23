// C++ program using recursive solution to count
// number of ways to reach mat[m-1][n-1] from
// mat[0][0] in a matrix mat[][]
#include <iostream>
using namespace std;

// Returns The number of way from top-left
// to mat[m-1][n-1]
int countPaths(int m, int n)
{
    // Return 1 if it is the first row or
    // first column
    if (m == 1 || n == 1)
        return 1;

    // Recursively find the no of way to
    // reach the last cell.
    return countPaths(m - 1, n) +
        countPaths(m, n - 1);
}
int factorial(int n)
{
    int res = 1, i;

    for (i = 2; i <= n; i++)
        res *= i;

    return res;
}

// Find number of ways to reach
// mat[m-1][n-1] from mat[0][0]
// in a matrix mat[][]]
int countWays(int m, int n)
{
    m = m - 1;
    n = n - 1;

    return factorial(m + n) /
        (factorial(m) *
            factorial(n));
}
// Driver code
int main()
{
    int m = 5;
    int n = 5;
   // cout << countPaths(n, m);
    cout << factorial(m);
    // Function call
    //int result = countWays(m, n);

   // cout << result;
    return 0;
}