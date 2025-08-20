class Solution {
public:

    bool isValid(string s) {
        stack<char>st;
        //simply one bracket is missing
        // if(!s.length())return false;
        if(s.length()%2!=0)return false;
        int i=0;
        while(i<s.length()){
            if(s[i]=='{'||s[i]=='('||s[i]=='['){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    char ch = st.top();
                    if((ch=='('&&s[i]==')')||
                    (ch=='{'&&s[i]=='}')||
                    (ch=='['&&s[i]==']'))st.pop();
                    else return false;
                    
                }else{
                    return false;
                }
                
            }
            i++;
        }
        return st.empty();
    }
};