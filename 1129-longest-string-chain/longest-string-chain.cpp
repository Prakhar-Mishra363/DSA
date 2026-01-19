class Solution {
public:
    bool is_string_chain(string wordIdx , string wordPrev){
        if(wordIdx.size() != wordPrev.size()+1)return false;
        int diff=0;
        int i=0 , j=0;
        while(i<wordIdx.size() && j<wordPrev.size()){
            if(wordIdx[i] != wordPrev[j]){
                if(diff == 1)return false;
                else diff++;
                i++;
            }else{
                i++;
                j++;
            }
        }
        if(i<wordIdx.size())diff++;
        return diff==1;
    }
    int longestStrChainHelper(const vector<string> &words){
        vector<int>dp(words.size() , 1);
        int maxLen=0;
        for(int idx=1 ; idx<words.size() ; idx++){
            for(int prev=idx-1 ; prev>=0 ; prev--){
                if(is_string_chain(words[idx] , words[prev])){
                    if(dp[prev] + 1 > dp[idx]){
                        dp[idx] = dp[prev]+1;
                        maxLen = max(maxLen , dp[idx]);
                    }
                }
            }
        }
        // for(auto a:dp){
        //     cout<<a<<" ";
        // }
        return *max_element(dp.begin(),dp.end());
    }
    void selectionSortBySize(vector<string>& words){
        int idx=0;
        for(int i=0 ; i<words.size() ; i++){
            int minIdx=i;
            for(int j=i+1 ; j<words.size() ; j++){
                if(words[j].size() <words[minIdx].size()){
                    minIdx=j;
                }
            }
            swap(words[i] , words[minIdx]);
        }
    }
    int longestStrChain(vector<string>& words) {
        selectionSortBySize(words);
        // for(auto a:words){
        //     cout<<a<<" ";
        // }cout<<endl;
        return longestStrChainHelper(words);
    }
};