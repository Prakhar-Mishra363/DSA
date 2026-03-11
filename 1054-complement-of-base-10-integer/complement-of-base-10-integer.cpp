class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int power=30 , complement=0;
        while(power>=0 && !(n & (1<<power)))power--;
        while(power>=0){
            if(!(n & (1<<power)))complement += 1<<power;
            power--;
        }

        return complement;
    }
};