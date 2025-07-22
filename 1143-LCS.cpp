class Solution
{
public:
  int f(string &a, string &b, int i, int j, int n, int m, vector<vector<int>> &dp)
  {

    if (i >= n or j >= m)
    {
      return 0;
    }

    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }

    if (a[i] == b[j])
    {
      return 1 + f(a, b, i + 1, j + 1, n, m, dp);
    }
    return dp[i][j] = max(f(a, b, i + 1, j, n, m, dp), f(a, b, i, j + 1, n, m, dp));
  }
  int longestCommonSubsequence(string a, string b)
  {
    int n = a.size();
    int m = b.size();
    int i = 0;
    int j = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(a, b, i, j, n, m, dp);
  }
};