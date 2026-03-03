class Solution {
public:
    int minBitFlips(int start, int goal) {
        int i=0 , flips_required=0;
        int n=1;
        while((n<=start)||(n<=goal)){
            if((n&start) && !(n&goal))flips_required += 1;
            else if(!(n&start) && (n&goal))flips_required += 1;
            i++;
            n=1<<i;
        }
        return flips_required;
    }
};