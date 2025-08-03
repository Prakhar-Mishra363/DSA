class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin(),s.end());//reversing the string
        for(int i=0;i<s.length();i++){
            string word = "";
            //seperating the substring from the original string
            while((i<s.length())&&(s[i]!=' ')){
                word += s[i++];
            }
            //finding the right string
            if(word.length()>0){
                reverse(word.begin(),word.end());
                ans += " "+word;
            }
        }
        return ans.substr(1);
    }
};