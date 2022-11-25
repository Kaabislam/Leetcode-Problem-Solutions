class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int a[n],ans = 0;
        a[n-1] = prices[n-1];
        for(int i = n-2;i >= 0;i--){
            a[i] = max(prices[i],a[i+1]);
        }
        for(int i = 0;i < n-1;i++){
            int x = a[i] - prices[i];
            ans = max(ans,x);
        }
        return ans;
    }
};