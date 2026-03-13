class Solution {
public:
    bool is_possible(int height , long long secs , vector<int> &arr){
        long long time_taken=0;
        for(int idx=0 ; idx<arr.size() && time_taken<height ; idx++){
            time_taken += sqrt( ((2 * secs)/arr[idx]) + 0.25 ) - 0.5;
        }
        return time_taken >= height;
    }
    long long minNumberOfSeconds(int mountHeight, vector<int>& arr) {
        long long left=1 , right=1e16;
        long long ans=right;
        while(left<=right){
            long long mid=left + (right-left)/2;
            if(is_possible(mountHeight , mid , arr)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};