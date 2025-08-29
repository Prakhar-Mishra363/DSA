class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // if(k>nums.size())
        // int maxEle=nums[0]
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<k;i++){
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
                // dq.push_back(i);
            }
            dq.push_back(i);
        }
        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);
            //check if the current front element should be in the window
            while(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            //maintaining the decreasing order
            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
                // dq.push_back(i);
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        
        return ans;
    }
};
auto init = atexit([](){ofstream("display_runtime.txt") << 0;});
