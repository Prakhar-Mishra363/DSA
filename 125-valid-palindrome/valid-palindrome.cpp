class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0,end = s.length()-1;
        while(start<end){
            if(!iswalnum(s[start])){
                start++;
                continue;
            }
            if(!iswalnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};