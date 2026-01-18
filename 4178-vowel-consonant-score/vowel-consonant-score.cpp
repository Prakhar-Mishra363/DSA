class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowelCount = 0;
        int consonantCount = 0;
        unordered_set<char>vowel = {'a' , 'e' , 'i' , 'o' , 'u'};
        for(int idx=0 ; idx<s.size() ; idx++){
            if(s[idx] >= 97 && s[idx] <= 122){
                if(vowel.find(s[idx]) != vowel.end())vowelCount++;
                else consonantCount++;
            }
        }
        // cout<<consonantCount <<" "<<vowelCount;
        return (consonantCount == 0) ? 0 : floor(vowelCount/consonantCount);
        
    }
};