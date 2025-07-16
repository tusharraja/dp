#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Summary:
 * -----------------
 * Given an array of strings `arr`, find the length of the longest string
 * that can be formed by concatenating a subsequence of `arr` such that
 * all characters in the resulting string are unique.
 * 
 * Example:
 * Input: arr = ["un", "iq", "ue"]
 * Output: 4 (Longest string with all unique characters: "uniq" or "ique")
 */

class Solution {
public:
    int ans = 0; // To store the maximum length found

    /**
     * Checks if the string `s` contains any character from `abhitak`.
     *
     * @param s: Current string to try to add
     * @param abhitak: Accumulated string so far
     * @return true if no characters in `s` are present in `abhitak`, false otherwise
     */
    bool check(string s, string abhitak) {
        unordered_set<char> st;

        // Add all characters from abhitak to the set
        for (auto x : abhitak) {
            st.insert(x);
        }

        // Check if any character in s already exists
        for (auto x : s) {
            if (st.find(x) != st.end()) {
                return false;
            }
        }
        return true;
    }

    /**
     * Checks if the string `s` has duplicate characters.
     *
     * @param s: String to check
     * @return true if all characters are unique, false if any character is repeated
     */
    bool dupcheck(string s) {
        unordered_set<char> st;
        for (auto x : s) {
            if (st.find(x) != st.end()) {
                return false;
            }
            st.insert(x);
        }
        return true;
    }

    /**
     * Recursive backtracking function to explore all valid concatenations.
     *
     * @param ind: Current index in arr
     * @param arr: Input array of strings
     * @param ds: Current concatenated string
     * @param n: Size of arr
     */
    void f(int ind, vector<string>& arr, string ds, int n) {
        // Base case: end of array reached
        if (ind >= n) {
            ans = max(ans, (int)ds.size());
            return;
        }

        // Case 1: Skip current string
        f(ind + 1, arr, ds, n);

        // Case 2: Include current string if it's valid
        if (check(arr[ind], ds) && dupcheck(arr[ind])) {
            f(ind + 1, arr, ds + arr[ind], n);
        }
    }

    /**
     * Main function to be called for solving the problem.
     *
     * @param arr: Array of strings
     * @return Maximum length of a unique-character concatenated string from subsequence of arr
     */
    int maxLength(vector<string>& arr) {
        string tmp;
        int n = arr.size();
        f(0, arr, tmp, n);
        return ans;
    }
};

int main() {

    return 0;
}

/**
 * ---------------------
 * Time and Space Analysis:
 * ---------------------
 * Time Complexity:
 *   - There are 2^n possible subsequences (each string can be included or not)
 *   - For each valid subsequence, we check:
 *     - whether characters are unique in O(L), where L is the string length (at most 26)
 *     - whether it overlaps with the current set in O(L)
 *   - So total time complexity: O(2^n * L), where L is max length of concatenated string
 *
 * Space Complexity:
 *   - Call stack: O(n) depth for recursion
 *   - Temporary string: O(L)
 *   - Hash sets: O(26) = O(1)
 *   - Total space: O(n + L)
 */
