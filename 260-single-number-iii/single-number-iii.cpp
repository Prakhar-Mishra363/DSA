class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>toReturn;
        unordered_set<int>tne;
        int result=nums[0];
        for(int idx=1 ; idx<nums.size() ; idx++){
            result ^= nums[idx];
        }
        int firstOne,secOne;
        for(int oneEle=0 ; oneEle<nums.size()-1; oneEle++){
            bool isExe=false;
            for(int secEle=oneEle+1 ; secEle<nums.size(); secEle++){
                if(tne.find(oneEle) != tne.end()){
                    isExe=true;
                    break;
                }
                if(nums[oneEle]==nums[secEle]){
                    isExe=true;
                    tne.insert(secEle);
                    break;
                }
                else if((nums[oneEle]^nums[secEle]) == result){
                    firstOne=nums[oneEle];
                    secOne=nums[secEle];
                }
            }
            if(!isExe )return {firstOne,secOne};
        }
        //will not be executed tho
        return {-1,-1};
    }
};