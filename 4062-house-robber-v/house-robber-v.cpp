class Solution {
public:
    long long max_one(int help ,int start , int end , vector<int> &nums , vector<long long> &dp){
        if(start>end)return 0;
        if(dp[start-help] != -1)return dp[start-help];
        long long pick = nums[start] + max_one(help , start+2 , end , nums , dp);
        long long dnp = max_one(help , start+1 , end , nums , dp);
        return dp[start-help] = max(pick , dnp);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        if(nums.size()==1)return nums[0];
        long long result=0;
        int idx=0,n=nums.size();
        while(idx<n-1){
            int start=idx , end=idx;
            while(idx<n-1 && colors[idx] == colors[idx+1]){
                idx += 1;
                end=idx;
            }
            if(end>start){
                int help=start;
                vector<long long> dp(2 , 0);
                idx += 1;
                for(int idx1=end ; idx1>=start ; idx1--){
                    long long pick = nums[idx1] + dp[1];
                    long long dnp = dp[0];
                    dp[1]=dp[0];
                    dp[0] = max(pick , dnp);
                }
                result += dp[0];
            }
            while(idx<n-1 && colors[idx] != colors[idx+1]){
                result += nums[idx];
                idx++;
            }
        }
        if(colors[n-1] != colors[n-2])result += nums[n-1];
        return result;
    }
};