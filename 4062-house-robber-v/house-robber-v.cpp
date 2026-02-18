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
        //we encounter the most difficulty when the colors are same (surprising i know)
        //so we simply calculate how many houses with same color are there then alternatively prepare two sum 
        //for example if test case is
        /*
        nums=[1,6,4,9]
        colors=[1,1,1,2]
        same color houses occur from 0 to 2
        so we can rob either house 0 and 2 or only 1 and in this case robbing 1 is better
        */
        if(nums.size()==1)return nums[0];
        long long result=0;
        int idx=0,n=nums.size();
        while(idx<n-1){
            int start=idx , end=idx;
            while(idx<n-1 && colors[idx] == colors[idx+1]){
                idx += 1;
                end=idx;
            }
            //now we compute two sums
            if(end>start){
                vector<long long> dp(end-start+1 , -1);
                idx += 1;
                result += max_one(start , start , end , nums,dp);
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