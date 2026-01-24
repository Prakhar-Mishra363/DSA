class Solution {
public:
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int left=0 , right=nums.size()-1;
       int minimized_max_pair_sum=0;
       while(left<right){
        minimized_max_pair_sum = max(minimized_max_pair_sum , nums[left++]+nums[right--]);
       }
       return minimized_max_pair_sum;
    }
};