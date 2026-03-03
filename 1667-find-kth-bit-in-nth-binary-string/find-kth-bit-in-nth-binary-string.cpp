class Solution {
public:
    string flip(string f){
        for(int idx=0 ; idx<f.size() ; idx++){
            f[idx] = (f[idx]=='1') ? '0' : '1' ;
        }
        return f;
    }
    char findKthBit(int n, int k) {
        string s="0";
        for(int len=2 ; len<=n ; len++){
            string flipped=flip(s);
            reverse(flipped.begin(),flipped.end());
            s = s + "1" + flipped;
        }
        return s[k-1];
    }
};