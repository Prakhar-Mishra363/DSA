class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        // if((m==0)&&(n!=0)){
        //     nums1[0]=nums2[0];
        //     return;
        // }
        int idx = m+n-1,i=m-1,j=n-1;
        while((j>=0)&&(i>=0)){
            if(nums1[i]<nums2[j]){
                nums1[idx--]=nums2[j--];
            }else{
                nums1[idx--]=nums1[i--];
            }
        }
        if(i<0){
            while(j>=0){
                nums1[idx--]=nums2[j--];
            }
        }


    }
};