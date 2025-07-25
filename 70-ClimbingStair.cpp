#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int f(int n, vector<int> &dp)
  {
    if (n == 1)
    {
      return 1;
    }
    if (n == 2)
    {
      return 2;
    }
    if (dp[n] != -1)
    {
      return dp[n];
    }
    return dp[n] = f(n - 2, dp) + f(n - 1, dp);
  }
  int climbStairs(int n)
  {
    vector<int> dp(n + 1, -1);

    return f(n, dp);
  }
};