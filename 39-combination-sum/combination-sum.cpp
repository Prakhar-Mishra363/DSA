class Solution {
public:
    set<vector<int>>s;
    void helper(vector<int> arr,vector<vector<int>>& ans,vector<int>&container,int i,int target){
        if(i==arr.size()||(target<0))return;
        if(target==0){
            if(s.find(container)==s.end()){
                s.insert(container);
                ans.push_back({container});
            }
            return;
        }
        container.push_back(arr[i]);
        helper(arr,ans,container,i+1,target-arr[i]);
        helper(arr,ans,container,i,target-arr[i]);
        container.pop_back();
        helper(arr,ans,container,i+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>container;
        helper(arr,ans,container,0,target);
        return ans;
    }
};