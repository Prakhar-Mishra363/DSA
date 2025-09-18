#include<numeric>
class Solution {
public:
    int isPossibleToAllocate(vector<int>& nums,int minimizedSum ){
        int subArray = 1;
        int currSum =0;
        for(int i=0;i<nums.size();i++){
            if(currSum+nums[i]<=minimizedSum){
                currSum += nums[i];
            }else{
                subArray++;
                currSum = nums[i];
            }
        }
        // if(currSum <= minimizedSum)subArray++;
        return subArray;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size()-1;
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(int i=0;i<=n;i++){
            high += nums[i];
        }
        int ans = low;
        while(low <= high){
            int mid = low + (high - low)/2;
            int allocatedArr = isPossibleToAllocate(nums,mid);
            if(allocatedArr>k) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};