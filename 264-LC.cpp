#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Summary:
 * -----------------
 * An *ugly number* is a positive integer whose prime factors are limited to 2, 3, and 5.
 * Given an integer n, return the nth ugly number.
 *
 * Example:
 * Input: n = 10
 * Output: 12
 * Explanation: The first 10 ugly numbers are: 
 * 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
 */

class Solution {
public:
    /**
     * Uses a min-heap (priority queue) and set to generate ugly numbers
     * in ascending order without duplicates.
     *
     * @param n: The index of the ugly number to return
     * @return The nth ugly number
     */
    int nthUglyNumber(int n) {
        // Min-heap to always get the smallest available ugly number
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        // Set to track already added numbers and avoid duplicates
        set<long long> s;

        // Counter for how many ugly numbers we've generated
        int cnt = 0;

        // Edge case: first ugly number is 1
        if (n == 1) return 1;

        // Start with the first ugly number
        pq.push(1);
        s.insert(1);

        // Generate ugly numbers in increasing order
        while (!pq.empty()) {
            long long x = pq.top();
            pq.pop();
            cnt++;

            // Found the nth ugly number
            if (cnt == n) {
                return x;
            }

            // Multiply current number by 2, 3, 5 to generate next ugly numbers
            if (s.find(2 * x) == s.end()) {
                pq.push(2 * x);
                s.insert(2 * x);
            }

            if (s.find(3 * x) == s.end()) {
                pq.push(3 * x);
                s.insert(3 * x);
            }

            if (s.find(5 * x) == s.end()) {
                pq.push(5 * x);
                s.insert(5 * x);
            }
        }

        return -1; // Should never be reached
    }
};


// Operation	        Count	    Cost per operation	  Total Time
// Heap insertions/pops 	O(n)	   O(log n)	       O(n log n)
// Set insertions/lookups	O(n)	O(log n)	  O(n log n)