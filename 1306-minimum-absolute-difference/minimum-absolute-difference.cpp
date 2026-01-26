class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int min_diff=1e9;
        for(int idx=1 ; idx<arr.size() ; idx++){
            min_diff = (abs(arr[idx]-arr[idx-1]) < min_diff) ? abs(arr[idx]-arr[idx-1]) : min_diff;
        }
        vector<vector<int>>result;
        for(int idx=1 ; idx<arr.size() ; idx++){
            if(abs(arr[idx]-arr[idx-1]) == min_diff){
                result.push_back({arr[idx-1] , arr[idx]});
            }
        }
        return result;
    }
};