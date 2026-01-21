class Solution {
public:
    int longestMountainHelper(vector<int> &arr){
        int n=arr.size();
        // vector<int>dp(n , 1);
        // vector<int>dpInc(n , 1);
        // vector<int>dpDec(n , 1);
        int maxEle=0;
        for(int idx=1 ; idx<=n-2 ; idx++){
            int prev=idx-1;
            int prevCount=0;
            while(prev>=0 && arr[prev] < arr[prev+1]){
                prevCount++;
                prev--;
            }
            int nextIdx=idx+1;
            int nextCount=0;
            while(nextIdx < n && (arr[nextIdx] < arr[nextIdx-1])){
                nextCount++;
                nextIdx++;
            }
            if(prevCount>0 && nextCount>0){
                maxEle =max(maxEle , prevCount+ nextCount + 1);
            }
        }
        return maxEle;

    }
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)return 0;
        return longestMountainHelper(arr);
    }
};