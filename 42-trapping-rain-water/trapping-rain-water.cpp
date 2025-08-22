class Solution {
public:
    int trap(vector<int>& arr) {
        vector<int>rightMax(arr.size());
        vector<int>leftMax(arr.size());
        //calculating leftMax
        leftMax[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            leftMax[i]=leftMax[i-1]>arr[i]?leftMax[i-1]:arr[i];
        }
        //calculating right max
        rightMax[arr.size()-1]=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            rightMax[i]=rightMax[i+1]>arr[i]?rightMax[i+1]:arr[i];
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(leftMax[i]==arr[i]||rightMax[i]==arr[i])continue;
            ans+=min(rightMax[i],leftMax[i])-arr[i];
        }
        return ans;
    }
};