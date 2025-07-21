#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int f(int i, int j, vector<vector<int>> &arr, int n, int m, vector<vector<int>> &dp)
  {
    if (i == n)
    {
      return 0;
    }

    if (j < 0 or j >= m)
    {
      return INT_MAX;
    }

    if (dp[i][j] != INT_MIN)
    {
      return dp[i][j];
    }

    int cur = arr[i][j];
    int ans = INT_MAX;
    for (int k = 0; k < m; k++)
    {
      if (k != j)
      {
        ans = min(ans, f(i + 1, k, arr, n, m, dp));
      }
    }

    return dp[i][j] = cur + ans;
  }

  int minFallingPathSum(vector<vector<int>> &arr)
  {

    int n = arr.size();
    int m = arr[0].size();
    int ans = INT_MAX;

    if (n == 1)
    {
      return arr[0][0];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

    for (int j = 0; j < m; j++)
    {

      ans = min(ans, f(0, j, arr, n, m, dp));
    }

    return ans;
  }
};