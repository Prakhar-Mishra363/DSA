class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n<=0)return false;
        if(n<=0)return false;
        if(n==1)return true;
        while(n>1){
            if(n%4==3||n%4==2||n%4==1)return false;
            n/=4;
        }return true;
        
        
    }
};