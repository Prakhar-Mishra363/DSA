class Solution {
public:
    int minFlips(int a, int b, int c) {
        int xored=(a|b)^c , minimum_flips_req=0;
        minimum_flips_req += __builtin_popcount(xored);
        minimum_flips_req += __builtin_popcount(xored & (a&b));
        return minimum_flips_req;
    }
};