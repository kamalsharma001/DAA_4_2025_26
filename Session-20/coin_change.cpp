class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m=coins.size();
        vector<vector<int>>dp(m+1,vector<int>(amount+1,0));
        for(int i=1;i<dp[0].size();i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=amount;j++){
        if(coins[i-1]<=j){
            dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][amount]!=INT_MAX-1?dp[m][amount]:-1;
    }
};
