class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;
        for(int idx=0 ; idx < 1<<n ; idx++){
            vector<int>tmp;
            for(int i=0 ; i<n ; i++){
                if(idx&(1<<i))tmp.push_back(nums[i]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};