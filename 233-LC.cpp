//DIGIT DP

//TC
// SIZE X TIGHT X CNT
// O(D X 2 X D)

// O(D^2) // where D is digits = log10n


#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int dp[11][2][20];
    int solve(string &r, int size, bool tight, int ind, int cnt)
    {

        if (ind >= size)
        {
            return cnt;
        }

        if (dp[ind][tight][cnt] != -1)
        {
            return dp[ind][tight][cnt];
        }

        char ch = r[ind];
        int limit = ch - '0';
        int ans = 0;

        if (tight == true)
        {
            for (int i = 0; i <= limit; i++)
            {
                if (i < limit)
                {
                    if (i == 1)
                    {
                        ans += solve(r, size, false, ind + 1, cnt + 1);
                    }
                    else
                    {
                        ans += solve(r, size, false, ind + 1, cnt);
                    }
                }
                else
                {
                    // i==limit
                    if (i == 1)
                    {
                        ans += solve(r, size, true, ind + 1, cnt + 1);
                    }
                    else
                    {
                        ans += solve(r, size, true, ind + 1, cnt);
                    }
                }
            }
        }
        else
        {

            for (int i = 0; i <= 9; i++)
            {
                if (i == 1)
                {
                    ans += solve(r, size, false, ind + 1, cnt + 1);
                }
                else
                {
                    ans += solve(r, size, false, ind + 1, cnt);
                }
            }
        }

        return dp[ind][tight][cnt] = ans;
    }

    int countDigitOne(int n)
    {
        string r = to_string(n);
        int size = r.size();
        bool tightrestrict = true;
        int ind = 0;
        int cnt = 0;
        memset(dp, -1, sizeof(dp));
        return solve(r, size, tightrestrict, ind, cnt);
    }
};