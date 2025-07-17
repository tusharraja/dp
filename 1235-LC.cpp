#include<bits/stdc++.h>
using namespace std;

int main(){

   return 0;
}
//TAKE -NOT TAKE
// TC O(N X LGN)
//SC O(N)


class Solution {
public:

int f(int ind,vector<vector<int>> &arr,int n,vector<int> &dp){
    if(ind>=n){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }

    int take=0;
    int notake=0;

    notake=f(ind+1,arr,n,dp);

    int newend=ind;
    int orgind=ind;
    int newprofit=arr[ind][2];
    while(ind<n and arr[ind][0]<arr[newend][1]){
        ind++;
    }

    take=newprofit+f(ind,arr,n,dp);
    return dp[orgind]=max(take,notake);

}

    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pro) {
        vector<vector<int>> arr;
        int n=pro.size();
        for(int i=0;i<n;i++){
            arr.push_back({st[i],et[i],pro[i]});
        }
        sort(arr.begin(),arr.end());
        int ind=0;
        vector<int>  dp(n+1,-1);
        return f(ind,arr,n,dp);
        
    }
};