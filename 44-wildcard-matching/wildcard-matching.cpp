class Solution {
public:
    bool isMatchHelper(int idx1 , int idx2 , const string &s , const string &p , vector<vector<int>> &dp){
        //edge case I
        if(idx1 == s.size()){
            //if pattern contains anything other than '*' return false
            for(int i=idx2 ; i<p.size() ; i++){
                if(p[i] != '*')return false;
            }
            return true;
        }
        //edge case II => if input string still has some characters left and pattern is exhausted return false
        if(idx2 == p.size() && idx1 < s.size())return false;
        if(dp[idx1][idx2] != -1)return dp[idx1][idx2];
        //if '?' is encountered then using it to match with the current character of the input string in the current state
        if(p[idx2] == '?'){
            return dp[idx1][idx2] = isMatchHelper(idx1 + 1 , idx2 + 1 , s , p , dp);
        }
        //"*" wild card character is encountered so checking different possibilities
        if(p[idx2] == '*'){
            if(idx2 == p.size()-1)return true;
            if (isMatchHelper(idx1, idx2 + 1, s, p, dp)) 
                return dp[idx1][idx2] = true;

            // '*' matches one character (and stays)
            if (isMatchHelper(idx1 + 1, idx2, s, p, dp)) 
                return dp[idx1][idx2] = true;

            return dp[idx1][idx2] = false;
        }
        //both characters are non-wild card and same
        if(p[idx2] != '*' && p[idx2] != '?' && s[idx1] == p[idx2]){
            return dp[idx1][idx2] = isMatchHelper(idx1 + 1 , idx2 + 1 , s , p , dp);
        }
        //simply both characters of the both string are not wild characters and do not match
        return dp[idx1][idx2] = false;
    }
    bool isMatch(string s, string p) {
        // return true;
        vector<vector<int>>dp(s.size() , vector<int>(p.size() , -1));
        return isMatchHelper(0 ,0 , s , p , dp);
    }
};