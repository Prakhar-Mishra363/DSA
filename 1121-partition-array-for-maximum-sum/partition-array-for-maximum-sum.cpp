class Solution {
public:
    int helper(int idx , int k , vector<int> &arr , vector<int> &dp){
        if(idx >= arr.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        int max_ele=-1;
        int sum=0 , len=0;
        for(int i=idx ; i < min((int)arr.size() , idx+k) ; i++){
            max_ele = (max_ele > arr[i]) ? max_ele : arr[i];
            len++;
            int calculated_sum=len*max_ele + helper(i+1 , k , arr , dp);
            sum=max(sum , calculated_sum);
        }
        return dp[idx] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // vector<int> dp(arr.size(),-1);
        // return helper(0 , k , arr , dp);
        int n=arr.size();
        vector<int>dp(arr.size()+1 , 0);
        for(int idx=n-1 ; idx>=0 ; idx--){
            int max_ele=-1;
            int sum=0 , len=0;
            for(int i=idx ; i < min((int)arr.size() , idx+k) ; i++){
                max_ele = (max_ele > arr[i]) ? max_ele : arr[i];
                len++;
                int calculated_sum=len*max_ele + dp[i+1];
                sum=max(sum , calculated_sum);
            }
            dp[idx] = sum;
        }
        return dp[0];
    }
};