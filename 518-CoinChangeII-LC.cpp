class Solution
{
public:
  int f(int ind, vector<int> &price, int n, int W, vector<vector<int>> &dp)
  {

    if (ind == n)
    {
      if (W == 0)
      {
        return 1;
      }
      return 0;
    }

    if (dp[ind][W] != -1)
    {
      return dp[ind][W];
    }

    int cutit = 0;
    int skip = 0;

    if (price[ind] <= W)
    {
      cutit = f(ind, price, n, W - price[ind], dp);
    }
    skip = f(ind + 1, price, n, W, dp);
    return dp[ind][W] = (cutit + skip);
  }

  int change(int amount, vector<int> &price)
  {

    int ind = 0;
    int n = price.size();
    int W = amount;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return f(ind, price, n, W, dp);
  }
};