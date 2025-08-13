class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        int power = 3;
        while(((long)power*3)<INT_MAX){
            power*=3;
        }
        return power%n==0;
    }
};