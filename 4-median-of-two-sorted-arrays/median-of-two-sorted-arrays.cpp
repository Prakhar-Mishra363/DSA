class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged;
        int len1 = nums1.size(),len2 = nums2.size();
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i++]);
            }else{
                merged.push_back(nums2[j++]);
            }
        }
        while(i<len1){
            merged.push_back(nums1[i++]);
        }
        while(j<len2){
            merged.push_back(nums2[j++]);
        }
        int totalEle = merged.size();
        if(totalEle & 1){
            return merged[totalEle/2];
        }
        return ((float)merged[totalEle/2] + (float)merged[totalEle/2-1])/2;
    }
};