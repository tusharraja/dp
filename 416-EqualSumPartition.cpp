class Solution
{
public:
  bool f(int W, int ind, vector<int> &arr, int n, vector<vector<int>> &dp)
  {
    if (W == 0)
    {
      return true;
    }

    if (ind == n)
    {
      return false;
    }
    if (dp[W][ind] != -1)
    {
      return dp[W][ind];
    }

    int take = 0;
    int skip = 0;
    if (arr[ind] <= W)
    {
      take = f(W - arr[ind], ind + 1, arr, n, dp);
    }
    skip = f(W, ind + 1, arr, n, dp);
    return dp[W][ind] = take or skip;
  }
  bool canPartition(vector<int> &arr)
  {
    int n = arr.size();
    int sum = 0;
    for (auto x : arr)
    {
      sum = sum + x;
    }
    if (sum % 2 == 1)
    {
      return false;
    }
    int ind = 0;
    vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1));
    return f(sum / 2, ind, arr, n, dp);
  }
};