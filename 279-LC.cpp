#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        set<int> vis;
        int lvl=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto f=q.front();
                q.pop();
                if(f==0){
                    return lvl;
                }
                for(int i=1;i*i<=f;i++){
                    if(vis.find(f-i*i)==vis.end()){
                    q.push(f-(i*i));
                    vis.insert(f-(i*i));
                    }
                }
            }
            lvl++;
        }
        return -1;
        
    }
};

int main(){

   return 0;
}


// Time Complexity: O(n * √n)
// For each number from n down to 0, we try subtracting all perfect squares i*i ≤ f.

// The branching factor is at most √n per node.

// In total, there are up to n different values we can visit (0 to n).

// Each is visited once due to the vis set.


 
// Space Complexity: O(n)
// Queue and Set: Both store up to n different states (0 to n).
 