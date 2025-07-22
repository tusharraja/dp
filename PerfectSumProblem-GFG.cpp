class Solution
{
public:
  int f(int ind, int n, int W, vector<int> &arr, vector<vector<int>> &dp)
  {

    if (ind >= n)
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
    int take = 0;
    int skip = 0;

    if (arr[ind] <= W)
    {
      take = f(ind + 1, n, W - arr[ind], arr, dp);
    }
    skip = f(ind + 1, n, W, arr, dp);
    return dp[ind][W] = (take + skip);
  }

  int perfectSum(vector<int> &arr, int target)
  {
    // code here
    int ind = 0;
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 10, -1));
    return f(ind, n, target, arr, dp);
  }
};