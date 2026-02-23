class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total_possible_com=1<<k;
        int n=s.size();
        unordered_set<string>combination;
        for(int idx=0 ; idx<n-k+1 ; idx++){
            combination.insert(s.substr(idx , k));
        }
        return combination.size()==total_possible_com;
    }
};