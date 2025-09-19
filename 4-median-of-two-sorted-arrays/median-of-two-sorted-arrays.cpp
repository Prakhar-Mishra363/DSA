class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        int n2 = n/2;
        int n1 = n2-1;
        int i=0,j=0;
        int count = -1;
        int ele1 = -1, ele2 = -1;
        bool flag = false;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                count++;
                if(count == n1)ele1 = nums1[i];
                if(count == n2){
                    ele2 = nums1[i];
                    flag = true;
                    break;
                }
                i++;
            }
            else {
                count++;
                if(count == n1)ele1 = nums2[j];
                if(count == n2){
                    ele2 = nums2[j];
                    flag=true;
                    break;
                }
                j++;
            }
            
        }
        while(i<nums1.size() && !flag){
            count++;
            if(count == n1)ele1 = nums1[i];
            if(count == n2){
                ele2 = nums1[i];
                break;
            }
            i++;
        }
        while(j<nums2.size() && !flag){
            count++;
            if(count == n1)ele1 = nums2[j];
            if(count == n2){
                ele2 = nums2[j];
                break;
            }
            j++;
        }
        if(n & 1)return ele2;
        return ((float(ele1)+float(ele2))/2);
    }
};