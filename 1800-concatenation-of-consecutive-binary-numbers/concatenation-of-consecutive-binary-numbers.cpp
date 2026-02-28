int modulo=1e9+7;
class Solution {
public:
    int helper(unsigned long long &pow ,int n , int curr_num){
        if(curr_num>n)return 0;
        unsigned long long cal_sum=helper(pow , n , curr_num+1);
        while(curr_num){
            if(curr_num%2)cal_sum += pow;
            pow = (pow << 1)%modulo;
            curr_num = curr_num >> 1;
        }
        return cal_sum%modulo;
    }
    int concatenatedBinary(int n) {
        unsigned long long pow=1;
        return helper(pow , n , 1)%modulo;
    }
};