class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // if(nums.size()==1){
        //     if(nums[0]>=target)return 1;
        //     return 0;
        // }
        int left=0,right=0;
        int sum=0,ans=INT_MAX;
        while(right<nums.size()){
            sum+=nums[right];
            
            while(sum>=target){
                ans = min(ans,right-left+1);
                sum-=nums[left++];
            }
            right++;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};