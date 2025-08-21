class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        for(int i=0;i<nums.size()/2+1;i++){
            nums.push_back(nums[i]);
        }
        vector<int>ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while((!s.empty())&&s.top()<=nums[i])s.pop();
            if(s.empty())ans[i]=-1;
            else ans[i]=s.top();
            s.push(nums[i]);
        }
        // while(!s.empty())s.pop();
        // for(int i=0;i<nums.size();i++){
        //     while((!s.empty())&&s.top()<=nums[i])s.pop();
        //     if(ans[i]==-1){
        //         if(s.empty()){s.push(nums[i]);}
        //         else ans[i]=s.top();
        //     }
            
        // }
        for(int i=0;i<nums.size()/2+1;i++)ans.pop_back();
        return ans;
    }
};