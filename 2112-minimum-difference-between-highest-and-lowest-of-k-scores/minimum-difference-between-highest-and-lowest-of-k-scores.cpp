class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int minimized_score=INT_MAX;
        for(int i=nums.size()-1 ; i>=(k-1) ; i--){
            minimized_score = min(minimized_score , nums[i] - nums[i-k+1]);
        }
        return minimized_score;
    }
};