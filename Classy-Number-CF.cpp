// // DIGIT DP

#include <bits/stdc++.h>
using namespace std;

// DP state: dp[index][non_zero_count][is_tight]
long long dp[20][4][2];
string S;


// cnt: count of non-zero digits used so far


long long solve(int ind, int cnt, bool tight)
{
   
    if (cnt > 3)
    {
        return 0;
    }
   
    if (ind == S.size())
    {
        return 1;
    }
    
    if (dp[ind][cnt][tight] != -1)
    {
        return dp[ind][cnt][tight];
    }

    long long ans = 0;
    
    int upper_bound = tight ? (S[ind] - '0') : 9;

    for (int digit = 0; digit <= upper_bound; digit++)
    {
        
        if ( digit == 0)
        {
            ans += solve(ind + 1, cnt, tight && (digit == upper_bound));
        }
        else
        {
            
            ans += solve(ind + 1, cnt + (digit != 0), tight && (digit == upper_bound));
        }
    }

    return dp[ind][cnt][tight] = ans;
}


long long count_classy_up_to(long long n)
{
    if (n == 0)
    {
        return 1; 
    }
    S = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, true);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        long long a = count_classy_up_to(r);
        long long b = count_classy_up_to(l - 1);
        cout << a - b << endl;
    }

    return 0;
}