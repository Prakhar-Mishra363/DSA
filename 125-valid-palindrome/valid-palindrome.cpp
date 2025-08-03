class Solution {
public:
    bool isAlphanumeric(char c){
        if(((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))||((c>='0')&&(c<='9'))){
            return true;
        }else{
            return false;
        }
    }
    bool isPalindrome(string s) {
        int start = 0,end = s.length()-1;
        while(start<end){
            if(!isAlphanumeric(s[start])){
                start++;
                continue;
            }
            if(!isAlphanumeric(s[end])){
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