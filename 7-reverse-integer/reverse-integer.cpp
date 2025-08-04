class Solution {
public:
    int reverse(int x) {
        long int ans = 0;
        while(x!=0){
            if(((ans * 10)>INT_MAX)||(ans * 10)<INT_MIN)return 0;
            ans = ans*10+x%10;

            x /= 10;
        }
        return ans;
    }
};