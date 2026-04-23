class Solution {
  public:
  
    int solve(int sum1,int sum2,int idx,vector<int>& arr,vector<vector<int>>& dp){
        if(idx==arr.size()) return abs(sum1-sum2);
        
        if(dp[idx][sum1]!=-1)   return dp[idx][sum1];
        
        int pick=solve(sum1+arr[idx],sum2-arr[idx],idx+1,arr,dp);
        int notpick=solve(sum1,sum2,idx+1,arr,dp);
        
        return dp[idx][sum1]=min(pick,notpick);
    }
  
    int minDifference(vector<int>& arr) {
        int sum1=0;
        int sum2=0;
        int n=arr.size();
        
        for(int x:arr){
            sum2+=x;
        }
        
        vector<vector<int>> dp(n,vector<int>(sum2+1,-1));
        
        return solve(sum1,sum2,0,arr,dp);
    }
};

/*
  Time Complexity: 𝑂(𝑛⋅𝑆), where 𝑛 is the number of elements and 𝑆 is the total sum of the array.
  Space Complexity: 𝑂(𝑛⋅𝑆) for the DP table.
*/
