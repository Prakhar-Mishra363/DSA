class Solution {
public:
    string expand_ard_cen(int left , int right , string s){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        left++;right--;
        if(left>right)return s.substr(right,1);
        return s.substr(left , right-left+1);
    }
    string longestPalindrome(string s) {
        if(s.size()==1)return s;
        string result="";
        for(int idx=0 ; idx<s.size() ; idx++){
            string odd=expand_ard_cen(idx,idx,s);
            string even=expand_ard_cen(idx,idx+1,s);
            string tmp = (odd.size() > even.size()) ? odd : even;
            result = (result.size() >= tmp.size()) ? result : tmp;
        }
        return result;
    }
};