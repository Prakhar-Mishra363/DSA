class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1,end=num;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(((long long)mid*mid)==num){
                return true;
            }else if(((long long)mid*mid)>num){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }return false;
    }
};