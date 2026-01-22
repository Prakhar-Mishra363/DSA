class Solution {
public:
    int lower_bound(vector<int> & arr , int target){
        int start=0 , end=arr.size()-1;
        while(start<=end){
            int mid=start + (end-start)/2;
            if(arr[mid] >= target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
    int findNumberOfLISHelper(vector<int> &nums){
        int n=nums.size();
        vector<int>dp(n , 1);
        vector<int>count(n , 1);
        for(int idx=1 ; idx<n ; idx++){
            for(int prv=idx-1 ; prv>=0 ; prv--){
                //now two things can be done 
                //1. if nums[idx]>nums[prv] 
                if(nums[idx] > nums[prv]){
                    /*
                    1+dp[idx] > dp[idx] means a longer length of LIS is found with that element  
                    so reset the count of LIS for that element to 1
                    */
                    if((1 + dp[prv]) > dp[idx]){
                        count[idx] = count[prv];
                        dp[idx] = 1+dp[prv];
                    /*
                    if 1+dp[prv] == dp[idx] means LIS of same length has been found so increase 
                    the count by 1 for current LIS for that element
                    */ 
                    }else if((1+dp[prv]) == dp[idx]){
                        count[idx] += count[prv];
                    }
                }

            }
        }
        // for(auto a:dp){
        //     cout<<a<<" ";
        // }cout<<endl;
        // for(auto a:count){
        //     cout<<a<<" ";
        // }
        int maxLength = *max_element(dp.begin() , dp.end());
        int numberOfLIS=0;
        for(int idx=0 ; idx<n ; idx++){
            if(dp[idx] == maxLength)numberOfLIS += count[idx];
        }
        return numberOfLIS;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return findNumberOfLISHelper(nums);
    }
};