class Solution
{
public:
  int f(int ind, int n, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
  {

    if (ind >= n)
    {
      return 0;
    }
    if (dp[ind][W] != -1)
    {
      return dp[ind][W];
    }
    int take = 0;
    int skip = 0;

    if (wt[ind] <= W)
    {
      take = val[ind] + f(ind + 1, n, W - wt[ind], val, wt, dp);
    }
    skip = f(ind + 1, n, W, val, wt, dp);
    return dp[ind][W] = max(take, skip);
  }
  int knapsack(int W, vector<int> &val, vector<int> &wt)
  {
    // code here
    int ind = 0;
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 10, -1));
    return f(ind, n, W, val, wt, dp);
  }
};