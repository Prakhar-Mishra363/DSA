class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int tempBottles = numBottles;
        int extraBot = 0;
        while(tempBottles>0){
            tempBottles -= numExchange;
            if(tempBottles >= 0){
                numBottles++;
                numExchange++;
                tempBottles++;
            }
        }
        return (numBottles);
    }
};