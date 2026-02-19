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
        int curr , prev=0;
        int n=s.size();
        if(n==1)return 0;
        for(int idx=0 ; idx<n-1 ; idx++){
            curr=1;
            while(idx<n-1 && s[idx]==s[idx+1]){
                curr++;
                idx += 1;
            }
            total_subs += min(curr,prev);
            prev=curr;
        }
        if(s[n-1]!=s[n-2])total_subs++;
        return total_subs;
    }
};