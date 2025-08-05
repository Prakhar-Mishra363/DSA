class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced=fruits.size();
        // vector<bool>placed(fruits.size(),false);
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if((fruits[i]<=baskets[j])&&(baskets[j]!=0)){
                    // placed[j]= true;
                    baskets[j]=0;
                    unplaced--;
                    break;
                }
            }
        }return unplaced;

    }
};