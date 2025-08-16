class Solution {
public:
    int maximum69Number (int num) {
        int x=num;
        vector<int>v;
        while(x>0){
            v.push_back(x%10);
            x/=10;
        }
        vector<int>pow;
        int exp=1;
        for(int i=0;i<v.size();i++){
            pow.push_back(exp);
            exp*=10;
        }
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==6){
                num=num-6*pow[i];
                num=num+9*pow[i];
                return num;
            }
        }
        return num;
    }
};