#include<unordered_set>
#include<algorithm>
#include<string>
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int prePower=1;
        unordered_set<string>m;
        while(prePower<1e9){
            string s = to_string(prePower);
            sort(s.begin(),s.end());
            // if(!(s[0]=='0'))s="0"+s;
            m.insert(s);
            prePower*=2;
        }
        string str = to_string(n);
        sort(str.begin(),str.end());
        // if(!(str[0]=='0'))str="0"+str;
        return (m.find(str)!=m.end());


    }
};