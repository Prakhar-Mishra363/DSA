class Solution {
public:
    bool hasAlternatingBits(int n) {
        int total_bits=(int)log2(n)+1;//O(logn)
        int tmp_num=0;
        //O(total_bits*(logn))
        while(total_bits>=1){
            tmp_num += pow(2,total_bits-1);
            total_bits -= 2;
        }
        return tmp_num==n;
    }
};