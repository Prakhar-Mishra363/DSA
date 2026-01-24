class Solution {
public:
    int minPairSum(vector<int>& nums) {
       priority_queue<int> max_heap;
       priority_queue<int , vector<int> , greater<int>>min_heap;
       for(int i=0; i<nums.size() ; i++){
        max_heap.push(nums[i]);
        min_heap.push(nums[i]);
       }
       int minimized_max_pair_sum=-1e9;
       while(!max_heap.empty()){
            int currSum=max_heap.top()+min_heap.top();
            max_heap.pop();
            min_heap.pop();
            minimized_max_pair_sum = max(minimized_max_pair_sum , currSum);
        }
        return minimized_max_pair_sum;
    }
};