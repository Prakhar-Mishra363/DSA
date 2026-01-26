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
        // return minCostHelper(1, cutSize , cuts , dp);
        vector<vector<int>>dp(cutSize+2 , vector<int>(cutSize+2 , 0));
        for(int i=cutSize ; i>=1 ; i--){
            for(int j=1 ; j<=cutSize ; j++){
                if(i>j)continue;
                int minCost=1e9;
                for(int idx=i ; idx<=j ; idx++){
                    int madeCutLen = (cuts[j+1]-cuts[i-1]) + dp[i][idx-1]+ dp[idx+1][j];
                    minCost = min(minCost , madeCutLen);
                }
                dp[i][j] = minCost;
            }
        }
        return dp[1][cutSize];
    }
};