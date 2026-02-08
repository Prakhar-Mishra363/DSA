class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0 , right=0 , jump=0;
        while(right<nums.size()-1){
            int farthest=0;
            for(int idx=left ; idx<=right ; idx++){
                farthest = max(idx+nums[idx],farthest);
            }
            left=right+1;
            right=farthest;
            jump++;
        }
        return jump;
    }
};