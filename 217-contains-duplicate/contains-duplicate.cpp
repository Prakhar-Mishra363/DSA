class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int>m;
        // for(int i=0;i<nums.size();i++){
        //     if(m.find(nums[i])!=m.end()){
        //         return true;
        //     }else{
        //         m.insert(nums[i]);
        //     }
        // }return false;
        sort(nums.begin(),nums.end());
        int i=0;
        while((i<nums.size()-1)){
            if(nums[i]==nums[i+1])return true;
            i++;
        }
        return false;
    }
};