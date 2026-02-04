class Solution {
public:
    bool canJumpHelper(int idx , vector<int> &nums , vector<int> &dp){
        if(idx >= nums.size())return false;
        if(idx == nums.size()-1)return true;
        if(dp[idx] != -1)return dp[idx];
        for(int i=1 ; i<=nums[idx] ; i++){
            bool result=canJumpHelper(idx+i , nums , dp);
            if(result)return true;
        }
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size() , -1);
        return canJumpHelper(0 , nums , dp);
    }
};