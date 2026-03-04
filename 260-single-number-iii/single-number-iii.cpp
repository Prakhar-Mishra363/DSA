class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long result=nums[0];
        for(int idx=1 ; idx<nums.size() ; idx++){
            result ^= nums[idx];
        }
        int firstBit = (result&(result-1)) ^ result;
        int firstOne=0,secOne=0;
        for(int idx=0 ; idx<nums.size() ; idx++){
            if(firstBit & nums[idx]) firstOne ^=nums[idx];
            else secOne ^= nums[idx];
        }
        return {firstOne,secOne};
    }
};