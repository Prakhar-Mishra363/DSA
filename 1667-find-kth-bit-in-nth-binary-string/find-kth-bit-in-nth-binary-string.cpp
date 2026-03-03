class Solution {
public:
    string flip_and_reverse(string f){
        int n=f.size();
        for(int idx=n-1 ; idx>=0 ; idx--){
            f[(n)-idx-1] = (f[idx]=='1') ? '0' : '1' ;
        }
        return f;
    }
    char findKthBit(int n, int k) {
        string s="0";
        for(int len=2 ; len<=n ; len++){
            string flipped=flip_and_reverse(s);
            s = s + "1" + flipped;
        }
        return s[k-1];
    }
};