class Solution {
public:
    int reverseBits(int n) {
        string tmp=string(32,'0');
        int tmp_integer=n;
        int idx=31;
        unsigned long long reversed_int=0;
        while(tmp_integer){
            int rem=tmp_integer%2;
            tmp_integer /= 2;
            char ch= rem+'0';
            tmp[idx--]= ch;
        }
        reverse(tmp.begin(),tmp.end());
        int radix=0;
        idx=31;
        while(idx>=0){
            if(tmp[idx]=='1'){
                reversed_int += pow(2,radix);
            }
            radix++;
            idx--;
        }
        
        return reversed_int;
    }
};