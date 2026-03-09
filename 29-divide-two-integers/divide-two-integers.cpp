class Solution {
public:
    int divide(int dividend, int divisor) {
        int power=31;
        bool isPositive=true;
        long currDividend=labs(dividend) , currDivisor=labs(divisor);
        if(dividend<0 && divisor>0 || dividend>=0 && divisor<0){
            isPositive=false;
        }
        long answer=0;
        while(power>=0 && (currDividend < currDivisor * (1L<<power)))power--;
        while(power >= 0){
            if(currDividend >= currDivisor * (1L << power)){
                currDividend -= currDivisor * (1L << power);
                answer += (1L << power);
            }
            power--;
        }
        if(answer>INT_MAX){
            return (isPositive) ? INT_MAX : INT_MIN;
        }
        return (isPositive) ? answer : -answer;
    }
};