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
        int result=0;
        vector<bool> is_assigned(s.size() , false);
        for(int i=0 ; i<g.size() ; i++){
            int idx = binary_search(g[i] , s);
            if(idx==-1)continue;
            if(s[idx]>=g[i]){
                if(!is_assigned[idx]){
                    result++;
                    is_assigned[idx]=true;
                }else{
                    int j=idx+1;
                    while(j<s.size()){
                        if(s[j]>=g[i] && !is_assigned[j]){
                            result++;
                            is_assigned[j]=true;
                            break;
                        }
                        j++;
                    }
                }
            }
        }
        return result;
    }
};