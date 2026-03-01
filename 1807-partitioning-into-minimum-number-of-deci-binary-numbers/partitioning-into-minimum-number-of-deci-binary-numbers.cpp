class Solution {
public:
    int minPartitions(string n) {
        int curr_max=-1e5;
        for(int idx=0 ; idx<n.size() ; idx++){
            curr_max = max(curr_max , n[idx]-'0');
        }
        return curr_max;
    }
};