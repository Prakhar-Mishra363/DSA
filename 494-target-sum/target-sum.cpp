class Solution {
public:
    int findTargetSumWaysHelper(int idx, int currTarget, const vector<int> &nums, vector<vector<int>> &dp){
        if(idx == nums.size()-1){
            if(currTarget == 0 && nums[idx] == 0)return dp[idx][currTarget] = 2;
            else if(currTarget == 0 || currTarget == nums[idx])return dp[idx][currTarget] = 1;
            else return dp[idx][currTarget] = 0;
        }
        if(dp[idx][currTarget] != -1)return dp[idx][currTarget];
        int pickedIdx = (currTarget >= nums[idx]) ? findTargetSumWaysHelper(idx + 1, currTarget - nums[idx], nums, dp) : 0;
        int leftIdx = findTargetSumWaysHelper(idx + 1, currTarget, nums, dp);
        return dp[idx][currTarget] = (pickedIdx + leftIdx);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int targetSum = (total - target)/2;
        if((total - target) < 0 || ((total - target)%2 == 1))return 0;
        vector<vector<int>> dp(nums.size(),vector<int>(abs(targetSum)+1, -1));
        int result = findTargetSumWaysHelper(0, targetSum , nums, dp);
        for(auto a : dp){
            for(auto b : a){
                cout<<b<<" ";
            }cout<<endl;
        }
        return result;
    }
};