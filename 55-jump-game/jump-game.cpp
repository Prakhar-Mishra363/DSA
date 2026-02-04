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
        /*
            //dp + memoization
            // vector<int>dp(nums.size() , -1);
            // return canJumpHelper(0 , nums , dp);
        */
        vector<bool>vis(nums.size(),false);
        int idx=0 ;
        for(; idx<nums.size() ; ){
            if(idx >= nums.size()-1)return true;
            if(nums[idx] > 0){
                idx += nums[idx];
            }else{
                int prev=idx-1;
                while(prev>=0){
                    if((prev + nums[prev]) > idx){
                        idx = prev + nums[prev];
                        break;
                    }
                    prev--;
                }
                if(prev == -1)return false;
            }
        }
        return (idx >= nums.size()-1) ? true : false;
    }
};