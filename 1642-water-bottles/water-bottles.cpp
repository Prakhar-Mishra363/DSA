class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrink = numBottles;
        int carry = 0;
        while(numBottles){
            if(carry){
                numBottles += carry;
            }
            carry = numBottles%numExchange;
            numBottles = numBottles/numExchange;
            totalDrink += numBottles;
        }
        return totalDrink;
    }
};