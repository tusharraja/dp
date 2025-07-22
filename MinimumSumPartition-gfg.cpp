class Solution
{

public:
  vector<int> sumarr;
  void f(vector<int> &arr, int ind, int n, int sum, vector<vector<int>> &dp)
  {

    if (ind >= n)
    {
      return;
    }

    if (dp[ind][sum] == 1)
    {

      return;
    }
    dp[ind][sum] = 1;

    int cumsum = sum + arr[ind];
    sumarr.push_back(cumsum);

    f(arr, ind + 1, n, cumsum, dp);
    f(arr, ind + 1, n, cumsum - arr[ind], dp);
  }
  int minDifference(vector<int> &arr)
  {
    // Your code goes here
    int sum = 0;
    int ind = 0;
    int n = arr.size();
    int s = 0;
    for (auto x : arr)
    {
      s = s + x;
    }

    vector<vector<int>> dp(n, vector<int>(s + 1, -1));
    f(arr, ind, n, sum, dp);

    int ans = INT_MAX;

    for (auto x : sumarr)
    {
      ans = min(ans, abs(s - 2 * x));
    }

    return ans;
  }
};
