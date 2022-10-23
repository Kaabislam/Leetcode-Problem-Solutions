class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int c[n+1];
        for(int i = 1;i <= nums.size();i++){c[i] = 0;}
        for(int i = 0;i < nums.size();i++){
            c[nums[i]] += 1;
        }
        vector<int>ans;
        for(int i = 1;i <= nums.size();i++){
            if(c[i] > 1) ans.push_back(i);
        }
        for(int i = 1;i <= nums.size();i++){
            if(!c[i]) ans.push_back(i);
        }
        return ans;
    }
};