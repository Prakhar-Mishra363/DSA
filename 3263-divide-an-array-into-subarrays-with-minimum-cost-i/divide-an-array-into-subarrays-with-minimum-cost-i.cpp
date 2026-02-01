class Solution {
public:
    int minimumCostHelper(int idx , int k , vector<int> &nums){
        if(idx >= nums.size())return 0;
        int cost=1e5;
        for(int i=idx ; i<min(idx+k , (int)nums.size()) ;i++){
            int temp_cost=nums[idx] + minimumCostHelper(i+1 , k , nums);
            cost = min(temp_cost , cost);
        }
        return cost;
    }
    int minimumCost(vector<int>& nums) {
        priority_queue<int , vector<int>>pq;
        for(int idx=1 ; idx<nums.size() ; idx++){
            if(pq.empty() || pq.size()<2){
                pq.push(nums[idx]);
            }else{
                if(pq.top() > nums[idx]){
                    pq.pop();
                    pq.push(nums[idx]);
                }
            }
        }
        int mini1=pq.top();
        pq.pop();
        int mini2=pq.top();
        pq.pop();
        return nums[0]+mini1+mini2;
        
    }
};