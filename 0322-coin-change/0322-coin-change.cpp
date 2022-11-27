class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long int dp[amount+1];
        map<int,int>m;
        for(int i = 0;i <= amount;i++){
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for(int i = 0;i < coins.size();i++){
            m[coins[i]] = 1;
            if(coins[i] <= amount){
                dp[coins[i]] = 1;
            }
        }
        for(int i = 1;i <= amount;i++){
            for(int k = 0;k < coins.size();k++){
                if(coins[k] <= i){
                    dp[i] = min(dp[i],1+dp[i-coins[k]]);
                }

            }
                
            
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};