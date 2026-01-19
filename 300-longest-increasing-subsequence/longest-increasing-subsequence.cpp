class Solution {
public:
    int lengthOfLISHelper(int idx , int prev ,const vector<int> &nums , vector<vector<int>> &dp){
        if(idx == nums.size()+1)return 0;
        if(dp[idx][prev] != -1)return dp[idx][prev];
        int pick = (prev == 0 || nums[idx-1] > nums[prev-1]) ? 1 + lengthOfLISHelper(idx + 1 , idx , nums , dp) : -1e7;
        int notPick = lengthOfLISHelper(idx + 1 , prev , nums , dp);
        return dp[idx][prev] = max(pick , notPick);
    }
    int tabulationOptimization(int n , vector<vector<int>> &dp , const vector<int> &nums){
        for(int idx=n ; idx>=1 ; idx--){
            for(int prev=n ; prev>=0 ; prev--){
                int pick = (prev == 0 || nums[idx-1] > nums[prev-1]) ? 1 + dp[idx + 1][idx] : -1e7;
                int notPick = dp[idx + 1][prev];
                dp[idx][prev] = max(pick , notPick);
            }
        }
        return dp[1][0];
    }
    int spaceOptimization(int n , const vector<int> &nums){
        vector<int>dp(n , 1) , hash(n , 0);
        for(int i=0; i<n ; i++){
            hash[i] = i;
        }
        int maxIdx=0;
        for(int idx=0 ; idx<n ; idx++){
            for(int prv=idx-1 ; prv>=0 ; prv--){
                if(nums[idx] > nums[prv]){
                    hash[idx] = (1 + dp[prv] > dp[idx]) ? prv : hash[idx];
                    dp[idx] = max(1 + dp[prv] , dp[idx]);
                    maxIdx = (dp[idx] > dp[maxIdx]) ? idx : maxIdx;
                }
            }
        }
        vector<int>seq(dp[maxIdx] , 0);
        int currIdx = maxIdx;
        int i=dp[maxIdx]-1;
        while(hash[currIdx] != currIdx){
            seq[i--] = nums[currIdx];
            currIdx = hash[currIdx];
        }
        seq[0] = nums[currIdx];
        return dp[maxIdx];
        
    }
    int lowerBound(const vector<int> &result , int key){
        int start=0 , end=result.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(result[mid] >= key){
                end = mid-1;
            }else{
                start = start + 1;
            }
        }
        return start;
    }
    int binary_search_approach(const vector<int> &nums){
        vector<int>result;
        result.push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] > result[result.size() - 1]){
                result.push_back(nums[i]);
            }else{
                int idx = lowerBound(result  , nums[i]);
                result[idx] = nums[i];
            }
        }
        return result.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        /*
        recursion + memoization
        vector<vector<int>>dp(nums.size() + 1 , vector<int>(nums.size()+ 1 , -1));
        int result = lengthOfLISHelper(1 , 0 , nums , dp);
        */
        int n=nums.size();
        /*
        vector<vector<int>>dp(n+2 , vector<int>(n+1 , 0));
        //tabulation
        return tabulationOptimization(n , dp , nums);
        */
        // return spaceOptimization(n , nums);
        return binary_search_approach(nums);
        
    }
};