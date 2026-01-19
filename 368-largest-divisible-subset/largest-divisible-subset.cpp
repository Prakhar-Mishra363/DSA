// #include<algorithm>
class Solution {
public:
    vector<int> largestDivisibleSubsetHelper(vector<int> &nums){
        if(nums.size() == 1)return {nums[0]};
        //sorting the array
        sort(nums.begin() , nums.end());
        vector<int>dp(nums.size() , 1);
        vector<int>hash(nums.size());
        for(int i=0 ; i<nums.size() ; i++){
            hash[i] = i;
        }
        // int maxIdx=0;
        for(int idx=1 ; idx<nums.size() ; idx++){
            for(int prev=idx-1 ; prev>=0 ; prev--){
                if((nums[idx] % nums[prev]) == 0){
                    hash[idx] = (1 + dp[prev] > dp[idx]) ? prev : hash[idx];
                    dp[idx] = max(1 + dp[prev] , dp[idx]);
                }
            }
        }
        int maxIdx=0;
        vector<int>result;
        //finding the index of the element who is the highest integer in the set
        for(int i=0 ; i<dp.size() ; i++){
            maxIdx = (dp[i] > dp[maxIdx]) ? i : maxIdx ;
        }
        while(hash[maxIdx] != maxIdx){
            result.push_back(nums[maxIdx]);
            maxIdx = hash[maxIdx];
        }
        result.push_back(nums[maxIdx]);
        return result;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return largestDivisibleSubsetHelper(nums);
    }
};