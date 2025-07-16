#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Summary:
 * -----------------
 * Given an array `arr` of job difficulties and an integer `d` (number of days),
 * partition the jobs such that:
 *   - Each day has at least one job
 *   - The difficulty of a day is the maximum difficulty of a job assigned that day
 * Return the minimum total difficulty of scheduling the jobs over `d` days,
 * or -1 if not possible.
 */

class Solution {
public:
    int m; // Number of days

    /**
     * Helper function using recursion and memoization.
     *
     * @param idx: Current index in the job array
     * @param d: Remaining number of days
     * @param arr: Job difficulty array
     * @param n: Size of the job array
     * @param dp: 2D memoization table (dp[idx][d] stores the minimum difficulty from index `idx` using `d` days)
     * @return Minimum total difficulty from index `idx` with `d` days remaining
     */
    int f(int idx, int d, vector<int> &arr, int n, vector<vector<int>> &dp) {
        // Base case: all jobs assigned
        if (idx >= n) return 0;

        // If last day, assign all remaining jobs to this day
        if (d == 1) {
            int maxDifficulty = INT_MIN;
            for (int i = idx; i < n; i++) {
                maxDifficulty = max(maxDifficulty, arr[i]);
            }
            return maxDifficulty;
        }

        if (dp[idx][d] != -1) return dp[idx][d];

        int maxJob = INT_MIN;
        int ans = INT_MAX;

        // Try all possible partitions for the current day
        // Constraint: at least one job per day → loop up to `n - d`
        for (int j = idx; j <= n - d; j++) {
            maxJob = max(maxJob, arr[j]); // Track max difficulty for the day
            ans = min(ans, maxJob + f(j + 1, d - 1, arr, n, dp)); // Recurse for remaining days
        }

        return dp[idx][d] = ans; 
    }

    /**
     * Entry point function to compute minimum schedule difficulty.
     *
     * @param arr: Array of job difficulties
     * @param d: Number of days to schedule jobs
     * @return Minimum total difficulty or -1 if not possible
     */
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        m = d;

        // Not enough jobs to assign at least one per day
        if (n < d) return -1;

       
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));

        return f(0, d, arr, n, dp); 
    }
};

int main() {

    return 0;
}

/**
 * ---------------------
 * Time and Space Analysis:
 * ---------------------
 * Time Complexity: O(n^2 * d)
 *   - There are O(n * d) states in the DP table
 *   - Each state performs up to O(n) work (loop from idx to n-d)
 *
 * Space Complexity: O(n * d)
 *   - DP table of size n x d
 *   - Recursion stack depth up to O(d)
 */
