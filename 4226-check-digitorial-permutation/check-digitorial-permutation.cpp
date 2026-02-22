class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10) , freqOfOgDigits(10,0) , freqCalDigit(10,0);
        fact[0]=1;
        int num=1 , digitorialNum=0;;
        while(num<=9){
            fact[num]=num*fact[num-1];
            num++;
        }
        while(n){
            freqOfOgDigits[n%10]++;
            digitorialNum += fact[n%10];
            n /= 10;
        }
        while(digitorialNum){
            freqCalDigit[digitorialNum%10]++;
            digitorialNum /= 10;
        }
        for(int idx=0 ; idx<10 ; idx++){
            if(freqCalDigit[idx] != freqOfOgDigits[idx])return false;
        }
        return true;
    }
};