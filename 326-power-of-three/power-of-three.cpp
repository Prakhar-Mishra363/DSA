class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        long power = 1;
        while((power<n)){
            power*=3;
        }
            return power==n;
        // return ;
    }
};