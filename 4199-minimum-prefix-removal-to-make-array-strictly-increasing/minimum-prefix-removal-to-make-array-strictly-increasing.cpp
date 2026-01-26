class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int start=0 , end=1e6;
        for(int idx=0 ; idx<nums.size()-1 ; idx++){
            if(nums[idx+1] <= nums[idx]){
                end=idx;
            }
        }
        if(end==1e6)return 0;
        return end-start+1;
    }
};