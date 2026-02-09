class Solution {
public:
    static bool comp(vector<int>a1 , vector<int>a2){
        return a1[1]<a2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),comp);
        vector<vector<int>>dp;
        int count=0;
        dp.push_back(inter[0]);
        for(int i=1 ; i<inter.size() ; i++){
            if(dp[dp.size()-1][1]<=inter[i][0])dp.push_back(inter[i]);
            else count++;
        }
        return count;
    }
};