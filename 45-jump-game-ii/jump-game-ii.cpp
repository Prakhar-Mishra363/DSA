class Solution {
public:
    int helper(int idx , vector<int> &nums , vector<int> &dp){
        if(idx >= nums.size()-1)return 0;
        if(dp[idx] != -1)return dp[idx];
        int result=1e5;
        for(int j=idx+1 ; j<=min((int)nums.size()-1 , idx+nums[idx]) ; j++){
            int curr_result =1+helper(j , nums , dp);
            result = min(curr_result , result);
        }
        return dp[idx] = result;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(0 , nums , dp);
    }
};