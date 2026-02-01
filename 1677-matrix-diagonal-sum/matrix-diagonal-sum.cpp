class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int diagonal_sum=0;
        for(int idx=0 ; idx<mat.size() ; idx++){
            diagonal_sum= diagonal_sum + mat[idx][idx] + mat[idx][n-(idx+1)];
        }
        return (n%2==1) ? diagonal_sum-mat[n/2][n/2] : diagonal_sum;
    }
};