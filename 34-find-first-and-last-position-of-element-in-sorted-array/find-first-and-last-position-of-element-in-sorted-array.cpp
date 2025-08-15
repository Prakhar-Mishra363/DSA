class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return {-1,-1};
        int start=0, end=nums.size()-1;
        int mid;
        while(start<=end){
            mid = start+(end-start)/2;
            if(nums[mid]==target){
                break;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        int iniPos=mid,lastPos=mid;
        if(start<=end){
            int j=mid-1;
            while(j>=0&&nums[j]==nums[mid]){
                iniPos=j;
                j--;
            }
            j=mid+1;
            while(j<nums.size()&&nums[j]==nums[mid]){
                lastPos=j;
                j++;
            }
        }
        if(nums[iniPos]!=target){
            return {-1,-1};
        }else{
            return {iniPos,lastPos};
        }
    }
};