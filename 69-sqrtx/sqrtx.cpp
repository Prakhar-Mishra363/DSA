class Solution {
public:
    int mySqrt(int x) {
       int start=1,end=x;
       while(start<=end){
            int mid = start+(end-start)/2;
            if(((long long)mid*mid)==x){
                return mid;
            }else if(((long long)mid*mid)>x){
                end=mid-1;
            }else{
                start=mid+1;
            }
       } 
       return end;
    }
};