class Solution {
public:
    int lengthOfLISHelper(int idx , int prev ,const vector<int> &nums , vector<vector<int>> &dp){
        if(idx == nums.size()+1)return 0;
        if(dp[idx][prev] != -1)return dp[idx][prev];
        int pick = (prev == 0 || nums[idx-1] > nums[prev-1]) ? 1 + lengthOfLISHelper(idx + 1 , idx , nums , dp) : -1e7;
        int notPick = lengthOfLISHelper(idx + 1 , prev , nums , dp);
        return dp[idx][prev] = max(pick , notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size() + 1 , vector<int>(nums.size()+ 1 , -1));
        return lengthOfLISHelper(1 , 0 , nums , dp);
    }
};