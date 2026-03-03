class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int>um;//number , freq
        int num=0;
        for(int idx=0; idx<nums.size() ; idx++){
            if(um.find(nums[idx]) == um.end() || um[nums[idx]]==1){
                um[nums[idx]]++;
            }
        }
        for(auto a:um){
            if(a.second==1)num=a.first;
        }
        return num;
    }
};