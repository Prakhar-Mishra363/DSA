class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long size=0;
            while(i<nums.size()&&nums[i]==0){
                size++;
                i++;
            }
            if(size){
                i--;
                size=size*(size+1)/2;
                ans+=size;
            }

        }
        return ans;
        
    }
};