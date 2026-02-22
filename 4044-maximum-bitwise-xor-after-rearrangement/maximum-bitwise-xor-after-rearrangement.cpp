class Solution {
public:
    string maximumXor(string s, string t) {
        int ones=0;
        string result="";
        for(int idx=0 ; idx<t.size() ; idx++){
            if(t[idx]=='1')ones++;
        }
        int zeroes=t.size()-ones;
        cout<<ones<<" "<<zeroes;
        for(int idx=0 ; idx<s.size() ; idx++){
            if(s[idx]=='1' ){
                if(zeroes>0){
                    result += "1"; zeroes--;
                }else{
                    result += '0'; ones--;
                }
            }else{
                if(ones>0){
                    result += "1";ones--;
                }else{
                    result += '0'; zeroes--;
                }
            }
        }
        return result;
    }
};