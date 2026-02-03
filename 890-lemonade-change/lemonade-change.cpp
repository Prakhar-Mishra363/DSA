class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0,tens=0,twenties=0;
        for(int i=0 ; i<bills.size() ; i++){
            if(bills[i]==5)fives++;
            else if(bills[i]==10){
                if(fives==0)return false;
                tens++;
                fives--;
            }else{
                if(fives>=3 && tens==0){
                    twenties++;
                    fives -= 3;
                }else if(tens>=1 && fives>=1){
                    twenties++;
                    tens--;
                    fives--;
                }
                else return false;

            }
        }
        return true;
    }
};