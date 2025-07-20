#include<bits/stdc++.h>
using namespace std;

//concept of TWO POINTERS also used here vvip

class Solution
{
public:
  int f(int ind, vector<int> &arr, int n, vector<int> &dp)
  {
    if (ind >= n)
    {
      return 0;
    }
    if (dp[ind] != -1)
    {
      return dp[ind];
    }
    int ele = arr[ind];
    int cnt = 0;
    int i = ind;
    while (i < n and arr[i] == ele)
    {
      cnt++;
      i++;
    }
    int skip = 0 + f(i, arr, n, dp);
    int j = i;
    int sum = (cnt * ele);
    while (j < n and arr[j] == ele + 1)
    {
      j++;
    }
    int consideredIT = sum + f(j, arr, n, dp);

    return dp[ind] = max(skip, consideredIT);
  }

  int deleteAndEarn(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> dp(n + 10, -1);
    int ind = 0;
    return f(ind, arr, n, dp);
  }
};