class Solution
{
public:
  int f(vector<int> &arr, int ind, int W, vector<vector<int>> &dp)
  {

    if (ind == arr.size())
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
      take = f(arr, ind + 1, W - arr[ind], dp);
    }
    skip = f(arr, ind + 1, W, dp);
    return dp[ind][W] = skip + take;
  }
  int countPartitions(vector<int> &arr, int d)
  {
    // Code here
    int n = arr.size();
    int ind = 0;
    int s = 0;
    for (auto x : arr)
    {
      s = s + x;
    }
    int tofind = d + s;
    if ((d + s) % 2 == 1)
    {
      return 0;
    }
    tofind = tofind / 2;
    vector<vector<int>> dp(n + 1, vector<int>(tofind + 10, -1));
    return f(arr, ind, tofind, dp);
  }
};