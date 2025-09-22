class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxFreq = 0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>maxFreq){
                maxFreq = m[nums[i]];
            }
        }
        int count = 0;
        for(auto val:m){
            if(val.second == maxFreq)count++;
        }
        return (count*maxFreq);
    }
};