#include<bits/stdc++.h>
using namespace std;

int main(){

   return 0;
}

class Solution
{
public:
  int dp[101][3];

  int f(int ind, vector<int> &arr, int n, int freedom)
  {
    if (ind >= n)
    {
      return 0;
    }
    if (dp[ind][freedom] != -1)
    {
      return dp[ind][freedom];
    }
    int take = 0;
    int skip = 0;
    if (freedom)
    {
      take = arr[ind] + f(ind + 1, arr, n, 0);
    }
    skip = f(ind + 1, arr, n, 1);

    return dp[ind][freedom] = max(take, skip);
  }
  int rob(vector<int> &arr)
  {
    int n = arr.size();
    int ind = 0;
    int freedom = 1;
    memset(dp, -1, sizeof(dp));
    return f(ind, arr, n, freedom);
  }
};