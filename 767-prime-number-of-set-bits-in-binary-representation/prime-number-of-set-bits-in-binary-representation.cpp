class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>s={2,3,5,7,11,13,17,19};
        int count=0;
        while(left <= right){
            if(s.find(__builtin_popcount(left)) != s.end())count++;
            left++;
        }
        return count;
    }
};