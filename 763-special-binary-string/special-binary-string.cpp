class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt=0 , i=0;
        vector<string>specialSubs;
        for(int idx=0 ; idx<s.size() ; idx++){
            cnt += (s[idx]=='1') ? 1 : -1;
            if(cnt==0){
                specialSubs.push_back('1' + makeLargestSpecial(s.substr(i+1 , idx-i-1)) + '0');
                i=idx+1;
            }
        }
        sort(specialSubs.begin() , specialSubs.end() , greater<string>());
        string result="";
        for(auto &a:specialSubs){
            result += a;
        }
        return result;
    }
};