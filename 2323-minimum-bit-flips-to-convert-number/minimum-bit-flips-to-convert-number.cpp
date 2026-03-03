class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start^goal , required_flips=0;
        while(n){
            required_flips += (n&1);
            n >>= 1;
        }
        return required_flips;
    }
};