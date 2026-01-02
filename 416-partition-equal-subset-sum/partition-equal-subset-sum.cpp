class Solution {
public:
    bool canPartitionHelper(int idx, int target,const vector<int> &nums, vector<vector<int>> &dp){
        if( target == 0)return dp[idx][target] = true;
        // if(sumOfPartition > target)return false;
        if(idx == nums.size()-1)return dp[idx][target] = (nums[idx]) == target;
        if(dp[idx][target] != -1)return dp[idx][target];
        bool onePartition = (nums[idx] <= target) ? canPartitionHelper(idx+1,  target - nums[idx] , nums,dp) : false;
        bool otherPartition = canPartitionHelper(idx+1, target, nums , dp);
        return dp[idx][target] = onePartition | otherPartition;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1 || nums.size() == 1)return false;
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        // bool result = canPartitionHelper(0,sum/2,nums,dp);
        // for(auto a : dp){
        //     for(auto b : a){
        //         cout<<b<<" ";
        //     }cout<<endl;
        // }
        // return result;
        vector<vector<bool>>dp(n,vector<bool>(sum/2+1,0));
        for(int i=0 ; i<n ; i++)dp[i][0] = true;
        if(nums[n-1] <= sum/2)dp[n-1][nums[n-1]] = true;
        for(int idx=n-2; idx >= 0; idx--){
            for(int target = 1; target <= sum/2 ; target++){
                bool onePartition = (target >= nums[idx]) ? dp[idx+1][target - nums[idx]] : false;
                bool otherPartition = dp[idx+1][target];
                dp[idx][target] = onePartition | otherPartition;
            }
        }
        // for(auto a : dp){
        //     for(auto b : a){
        //         cout<<b<<" ";
        //     }cout<<endl;
        // }
        return dp[0][sum/2];
    }
};