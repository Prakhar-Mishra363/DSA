class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1,n=nums.size()-1;
        for(int i=n-1;i>=0;i--){//finding pivot element
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        //edge case 
        if(pivot==-1){
            int i=0,j=n;
            while(i<j){
                swap(nums[i++],nums[j--]);
            }
            return;
        }
        //finding just larger element than pivot
        for(int i=n;i>=0;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        //reversing the part after the pivot element
        int i=pivot+1,j=n;
        while(i<j){
            swap(nums[i++],nums[j--]);
        }

    }
};