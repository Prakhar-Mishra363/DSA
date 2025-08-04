class Solution {
public:
int reverseNum(int num){
    long int reverse=0;
    while(num!=0){
        reverse = reverse*10 + num%10;
        num /= 10;
    }
    return reverse;
}
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==reverseNum(x))return true;
        return false;
    }
};