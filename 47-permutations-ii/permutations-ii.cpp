class Solution {
public:
void calPer(vector<int>& nums,vector<vector<int>>& ans,set<vector<int>>& s,int idx){
    if(idx==nums.size()&&(s.find(nums)==s.end())){
        ans.push_back({nums});
        s.insert(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[i],nums[idx]);
        calPer(nums,ans,s,idx+1);
        swap(nums[i],nums[idx]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>>ans;
       set<vector<int>>s;
       calPer(nums,ans,s,0); 
        return ans;
    }
};