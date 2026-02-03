class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=-1 , q=-1 , lastIdx=-1;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]<=nums[i-1]){
                p=i-1;
                break;
            }
        }
        if(p==0 || p==-1)return false;
        for(int i=p+1 ; i<nums.size() ; i++){
            if(nums[i]>=nums[i-1]){
                q=i-1;
                break;
            }
        }
        if(q==p || q==-1)return false;
        for(int i=q+1 ; i<nums.size() ; i++){
            if(nums[i]<=nums[i-1])return false;
            lastIdx=i;
        }
        if(lastIdx==-1 || lastIdx==q)return false;
        return true;
    }
};