class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0)return 0;
        if(nums.size()==1){
            if(nums[0]==k)return 1;
            else return 0;
        }
        int count=0;
        vector<int>preSum(nums.size(),0);
        unordered_map<int,int>m;
        preSum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            // prefixSum+=nums[i];
            // preSum.push_back(preSum[i-1]+nums[i]);
            preSum[i]=preSum[i-1]+nums[i];
            
        }
        for(int i=0;i<nums.size();i++){
            if(preSum[i]==k){
                count++;
                // m[k]=1;
                // continue;
            }
            if(m.find(preSum[i]-k)!=m.end()){
                // m[preSum[i]]++;
                count+=m[preSum[i]-k];
                m[preSum[i]]++;
                continue;
            }
            if(m.find(preSum[i])!=m.end()){
                m[preSum[i]]++;
            }else{
                m[preSum[i]]=1;
            }
        }

        return count;
    }
};