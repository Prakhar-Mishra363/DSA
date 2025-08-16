class Solution {
public:
    int maximum69Number (int num) {
        // int x=num;
        string s=to_string(num);
        for(int i=0;i<s.length();i++){
            if(s[i]=='6'){
                s[i]='9';
                return stoi(s);
            }
        }return num;
        
    }
};