#include<bits/stdc++.h>
using namespace std;



class Solution {
public:

int m;

int f(int idx,int d,vector<int> &arr,int n,vector<vector<int>> &dp){

    if(idx>=n){
        return 0;
    }
    
    if(d==1){
        int mxk=INT_MIN;
        for(int i=idx;i<n;i++){
            mxk=max(mxk,arr[i]);
            
        }
        return mxk;
    }

    if(dp[idx][d]!=-1){
        return dp[idx][d];

    }
    int mx=INT_MIN;
    int ans=INT_MAX;

    for(int j=idx;j<=n-d;j++){
        mx=max(mx,arr[j]);
        ans=min(ans,mx+f(j+1,d-1,arr,n,dp));
    }
    return dp[idx][d]=ans;
}

    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        m=d;
        if(n<d){
            return -1;
        }
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return f(0,d,arr,n,dp);
        
    }
};

int main(){

   return 0;
}