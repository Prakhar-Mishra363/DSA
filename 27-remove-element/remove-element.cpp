class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int st=0,end=nums.size()-1;
        int mid;
        while(st<=end){
            mid=st+(end-st)/2;
            if(nums[mid]==val){
                break;
            }else if(nums[mid]>val){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        if(st<=end){
            int j=mid,i=mid;
            while(j-1>=0&&nums[mid]==nums[j-1])j--;
            while((i+1)<nums.size()&&nums[mid]==nums[i+1])i++;
            int pos=nums.size()-1;
            while(j<=i){
                swap(nums[pos],nums[j]);
                j++;
                pos--;
            }
            return pos+1;
        }
        return nums.size();
        
    }
};