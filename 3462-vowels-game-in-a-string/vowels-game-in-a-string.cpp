class Solution {
public:
    bool doesAliceWin(string s) {
        
        unordered_set<char>ch={'a','e','i','o','u'};
        int count=0;
        for(int i=0;i<s.size();i++){
            if(ch.find(s[i])!=ch.end())return true;
        }
        return false;
    }
};