class Solution {
public:
    int maxCoinsHelper(int left , int right , vector<int> nums , vector<vector<int>> &dp){
        if(left > right)return 0;
        // if(left == right)return nums[left];
        if(dp[left][right] != -1)return dp[left][right];
        int maxResult=-1e5;
        for(int idx=left ; idx<=right ; idx++){
            int tmp_result = nums[left-1] * nums[idx] * nums[right+1] + maxCoinsHelper(left , idx-1 , nums , dp) + maxCoinsHelper(idx+1 , right , nums , dp);
            maxResult = max(maxResult , tmp_result);
        }
        return dp[left][right] = maxResult;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.emplace(nums.begin() , 1);
        vector<vector<int>>dp(n+2 , vector<int>(n+2 , 0));
        // return maxCoinsHelper(1 , n , nums , dp);
        for(int left=n ; left>=1 ; left--){
            for(int right=1 ; right<=n ; right++){
                if(left>right)continue;
                int maxResult=-1e5;
                for(int idx=left ; idx<=right ; idx++){
                    int tmp_result = nums[left-1] * nums[idx] * nums[right+1] + dp[left][idx-1] + dp[idx+1][right];
                    maxResult = max(maxResult , tmp_result);
                }
                dp[left][right] = maxResult;
            }
        }
        return dp[1][n];
    }
};