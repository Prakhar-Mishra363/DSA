class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int j=i;
            for(int j=i;j<nums.size();j++){
                // if(k==sum)count++;
                sum+=nums[j];
                if(sum==k)count++;
                
            }
        }
        return count;
    }
};