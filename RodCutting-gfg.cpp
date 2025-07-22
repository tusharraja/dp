// User function Template for C++

class Solution
{
public:
  int f(int ind, vector<int> &price, int n, int W, vector<vector<int>> &dp)
  {

    if (ind == n)
    {
      return 0;
    }

    if (dp[ind][W] != -1)
    {
      return dp[ind][W];
    }

    int lenofcut = ind + 1;
    int cutit = 0;
    int skip = 0;

    if (lenofcut <= W)
    {
      cutit = price[ind] + f(ind, price, n, W - lenofcut, dp);
    }
    skip = f(ind + 1, price, n, W, dp);
    return dp[ind][W] = max(cutit, skip);
  }
  int cutRod(vector<int> &price)
  {
    // code here
    int ind = 0;
    int n = price.size();
    int W = n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(ind, price, n, W, dp);
  }
};