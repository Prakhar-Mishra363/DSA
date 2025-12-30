class Solution {
public:
    // int robHelper(int idx,const vector<int> &nums,vector<int>& dp){
    //     if(idx == 0)return nums[idx];
    //     if(idx < 0)return 0;
    //     int pickedHouse = robHelper(idx-2,nums,dp) + nums[idx];
    //     int leftHouse = robHelper(idx-1,nums,dp);
    //     return dp[idx] = max(pickedHouse, leftHouse);
    // }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0] = nums[0];
        int pickedHouse,leftHouse;
        for(int i=1;i<nums.size();i++){
            pickedHouse = (i-2) < 0 ? nums[i] : nums[i] + dp[i-2];
            leftHouse = dp[i-1];
            dp[i] = max(pickedHouse,leftHouse);
        }
        // return robHelper(nums.size()-1,nums,dp);
        return dp[dp.size()-1];
    }
};