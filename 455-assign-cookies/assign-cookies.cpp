class Solution {
public:
    int binary_search(int key , vector<int> &arr){
        int start=0 , end=arr.size()-1;
        while(start <=end){
            int mid = start + (end-start)/2;
            if(arr[mid] >= key){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return (start == arr.size()) ? -1 : start;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int result=0;
        int greed=0 , cookie=0;
        while(greed < g.size() && cookie < s.size()){
            if(g[greed] <= s[cookie]){
                greed++;
            }
            cookie++;
        }
        return greed;
    }
};