class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0 , twos=0;
        for(int idx=0 ; idx<nums.size() ; idx++){
            int tmp=(ones^nums[idx])&(~twos);
            ones=tmp;
            twos=(twos^nums[idx])&(~ones);
        }
        return ones;
    }
};