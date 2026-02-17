class Solution {
public:
    int almostPalindromic(string s) {
        vector<vector<pair<bool,bool>>>dp(s.size(),vector<pair<bool,bool>>(s.size()));
        //the string of length 2 will be almost palindromic always as we can always remove 1 character from them
        //length 1 is always palindrome always
        dp[0][0]={true,true};
        int max_len=2;
        for(int idx=1 ; idx<s.size() ; idx++){
            dp[idx][idx]={true,true};
            if(s[idx]==s[idx-1]){
                dp[idx][idx-1]={true,true};
                dp[idx-1][idx]={true,true};
            }else{
                dp[idx][idx-1]={true,false};
                dp[idx-1][idx]={true,false};
            }
        }
        for(int len=2 ; len<s.size() ; len++){
            for(int j=0 ; j<s.size()-len ; j++){
                int left=j;
                int right=j+len;
                if(s[left] != s[right]){
                    auto lftDel=dp[left+1][right];
                    auto rhtDel=dp[left][right-1];
                    if((lftDel.first && lftDel.second) || rhtDel.first && rhtDel.second){
                        dp[left][right]={true,false};
                        max_len=max(max_len,right-left+1);
                    }
                    else dp[left][right]={false,false};
                }else{
                    if(dp[left+1][right-1].first){
                        dp[left][right]=dp[left+1][right-1];
                        max_len=max(max_len,right-left+1);
                    }
                }
            }
        }
        return max_len;
    }
};