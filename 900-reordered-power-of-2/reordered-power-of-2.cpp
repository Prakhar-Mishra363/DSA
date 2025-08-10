// #include<unordered_set>
#include<algorithm>
#include<vector>
#include<string>
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int prePower=1;
        vector<string>m;
        while(prePower<1e9){
            string s = to_string(prePower);
            sort(s.begin(),s.end());
            m.push_back(s);
            prePower*=2;
        }
        string str = to_string(n);
        sort(str.begin(),str.end());
        for(auto& val : m){
            if(val==str)return true;
        }

        return false;
    }
};