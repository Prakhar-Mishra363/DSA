class Solution {
public:
    int longestMountainHelper(vector<int> &arr){
        int n=arr.size();
        // vector<int>dp(n , 1);
        // vector<int>dpInc(n , 1);
        // vector<int>dpDec(n , 1);
        int maxEle=0;
        int i=1;
        while(i<arr.size()){
            int increasing=0 , decreasing=0;
            while(i<arr.size() && arr[i-1] < arr[i]){
                i++; increasing++;
            }
            while(i<n && arr[i-1] > arr[i]){
                i++; decreasing++;
            }
            if(increasing > 0 && decreasing>0){
                maxEle = max(maxEle , decreasing + increasing +1);
            }
            while(i<n && arr[i-1] == arr[i])i++;
        }
        return maxEle;

    }
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)return 0;
        return longestMountainHelper(arr);
    }
};