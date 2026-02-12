class Solution {
public:
    bool valid(unordered_map<char,int> &freq , int count){
        for(auto a:freq){
            if(a.second != count)return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int length=0;
        if(s.size()==1)return 1;
        for(int idx=0 ; idx<s.size() ; idx++){
            unordered_map<char , int>freq;
            freq[s[idx]]++;
            for(int j=idx+1 ; j<s.size() ; j++){
                freq[s[j]]++;
                if(valid(freq ,freq[s[j]]))length=max(length,j-idx+1);
            }
        }
        return length;
    }
};