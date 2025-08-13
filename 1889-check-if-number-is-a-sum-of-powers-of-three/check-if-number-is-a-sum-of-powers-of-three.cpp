class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x;
        while(n>=1){
            if(n%3==2)return false;
            n/=3;
        }return true;
    }
};