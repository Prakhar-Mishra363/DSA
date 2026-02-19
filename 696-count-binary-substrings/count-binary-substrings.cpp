class Solution {
public:
    int helper(int left , int right , string s){
        char a=s[left] , b=s[right];
        if(a==b)return 0;
        int curr_cnt=0;
        while(left >=0 && right<s.size() && (s[left]==a) && (s[right]==b)){
            curr_cnt++;
            left--;
            right++;
        }
        return curr_cnt;
    }
    int countBinarySubstrings(string s) {
        int total_subs=0;
        for(int idx=0 ; idx<s.size()-1 ; idx++){
            if(s[idx]==s[idx+1])continue;
            total_subs += helper(idx , idx+1 , s);
        }
        return total_subs;
    }
};