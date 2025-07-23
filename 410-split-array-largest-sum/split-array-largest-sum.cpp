class Solution {
public:
    bool isValid(vector<int> &nums, int max, int k){
        int student = 1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                return false;
            }
            if((sum+nums[i])<=max){
                sum+=nums[i];
            }else{
                student++;
                sum=nums[i];
            }
        }
        if(student<=k){
            return true;
        }else{
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {
        int maxSum = 0,ans=0;
        if(k>nums.size()){
            return -1;
        }
        for(int i=0;i<nums.size();i++){
            maxSum += nums[i];
        }
        int start=0,end=maxSum;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(nums,mid,k)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
        
    }
};