class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool>isOn(101,false);
        int n=bulbs.size();
        for(int idx=0 ; idx<n ; idx++){
            if(isOn[bulbs[idx]])isOn[bulbs[idx]]=false;
            else isOn[bulbs[idx]]=true;
        }
        vector<int>result;
        for(int idx=1 ; idx<=100 ; idx++){
            if(isOn[idx])result.push_back(idx);
        }
        return result;
    }
};