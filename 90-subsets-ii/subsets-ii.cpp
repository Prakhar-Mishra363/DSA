class Solution {
public:
void helper(vector<int>& arr,vector<vector<int>>& ans,int i,vector<int>& container){
    sort(arr.begin(),arr.end());
    if(i==arr.size()){
        ans.push_back(container);
        return;
    }
    container.push_back(arr[i]);
    helper(arr,ans,i+1,container);
    container.pop_back();
    int x=i+1;
    while(x<arr.size()&&(arr[x-1]==arr[x])){
        x++;
        i++;
    }
    helper(arr,ans,i+1,container);
    return;

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cont;
        helper(nums,ans,0,cont);
        return ans;
    }
};