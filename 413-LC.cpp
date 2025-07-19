#include<bits/stdc++.h>
using namespace std;

//sliding window approach

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int fl = 0;

            for (int j = i + 1; j < n - 1; j++)
            {

                if (arr[i + 1] - arr[i] != arr[j + 1] - arr[j])
                {

                    fl = 1;
                }
                if (fl == 0)
                {
                    // cout<<i<<j<<endl;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//O(N) GROUPING APPROACH

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0;
        vector<int> dif(n, 0);
        for (int i = 1; i < n; i++)
        {
            dif[i] = arr[i] - arr[i - 1];
        }
        // for(auto x:dif){
        //     cout<<x<<" ";
        // }
        int i = 1;
        while (i < n)
        {
            int c = 1;
            while (i + 1 < n and dif[i + 1] == dif[i])
            {
                c++;
                i++;
            }
            int grp = (c * (c - 1)) / 2;
            cnt = cnt + (grp);
            i++;
        }
        return cnt;
    }
};