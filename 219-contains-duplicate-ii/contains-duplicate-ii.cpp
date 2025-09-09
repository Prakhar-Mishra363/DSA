class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==1)return false;
        int left=0,right=1;
        unordered_set<int>s;
        s.insert(nums[0]);
        while(right<nums.size()){
            if(abs(left-right)>k){
                s.erase(nums[left]);
                left++;
            }
            if(s.find(nums[right])!=s.end())return true;
            s.insert(nums[right]);
            right++;
        }
        return false;
    }
};