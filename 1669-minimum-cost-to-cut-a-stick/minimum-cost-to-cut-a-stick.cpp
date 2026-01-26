class Solution {
public:
    int minCostHelper(int i , int j , vector<int> &cuts , vector<vector<int>> &dp){
        // if(j <= cuts[0])return 0;
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int minCost=1e9;
        for(int idx=i ; idx<=j ; idx++){
            int madeCutLen = (cuts[j+1]-cuts[i-1]) + minCostHelper(i , idx-1 , cuts , dp ) + minCostHelper(idx+1 , j , cuts , dp);
            minCost = min(minCost , madeCutLen);
        }
        return dp[i][j] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        int cutSize = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin() , cuts.end());
        vector<vector<int>>dp(cutSize+1 , vector<int>(cutSize+1 , -1));
        return minCostHelper(1, cutSize , cuts , dp);
    }
};