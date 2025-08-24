class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int conOnes=0;
        int size=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                conOnes=max(conOnes,size);
                size=0;
            }else{
                size++;
            }
        }
        if(size){
            return conOnes=max(conOnes,size);
        }
        return conOnes;
    }
};