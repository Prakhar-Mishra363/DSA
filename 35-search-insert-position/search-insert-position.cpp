class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        if(target<nums[0])return 0;
        if(target>nums[nums.size()-1])return nums.size();
        start=0;end=nums.size()-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(mid!=0){
                if((target<nums[mid])&&(target>nums[mid-1])){
                return mid;
                }
                if((target<nums[mid-1])){
                    end=mid-1;
                }
            }
            if(target>nums[mid]){
                start=mid+1;
            }
        }
        return -1;
        
    }
};