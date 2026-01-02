class Solution {
public:
    // void subarraySumHelper(int idx,int k,int currSum ,int &count,vector<int>&nums){
    //     if(idx == nums.size())
    // }
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefixSum(nums.size(),0);
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int sum = nums[i];
            if(sum == k)count++;
            for(int j=i+1;j<nums.size();j++){
                sum += nums[j];
                if(sum == k)count++;
            }
        }
        return count;
    }
};