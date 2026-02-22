class Solution {
public:
    string maximumXor(string s, string t) {
        int ones=count(t.begin(),t.end(),'1');
        int zeroes=t.size()-ones;
        string result;
        result.reserve(s.size());
        for(int idx=0 ; idx<s.size() ; idx++){
            if(s[idx]=='1' && zeroes || s[idx]=='0' && ones){
                result += '1';
                (s[idx]=='1') ? zeroes-- : ones--;
            }else{
                result += '0';
                (s[idx] == '1') ? ones-- : zeroes--;
            }
        }
        return result;
    }
};