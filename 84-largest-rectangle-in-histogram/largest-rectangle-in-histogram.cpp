class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>s;
        vector<int>leftSmal(arr.size());
        vector<int>rightSmal(arr.size());
        int area=0;
        //calculating left smaller
        for(int i=0;i<arr.size();i++){
            while((!s.empty())&&arr[s.top()]>=arr[i])s.pop();
            if(s.empty()){
                leftSmal[i]=-1;
            }else{
                leftSmal[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty())s.pop();
        //calculating right smaller
        for(int i=arr.size()-1;i>=0;i--){
            while((!s.empty())&&arr[s.top()]>=arr[i])s.pop();
            if(s.empty()){
                rightSmal[i]=arr.size();
            }else{
                rightSmal[i]=s.top();
            }
            s.push(i);
        }
        // int area=0;
        for(int i=0;i<arr.size();i++){
            // int width=0;
            // if(lefSmal[i]==i)
            area=max(area,arr[i]*(rightSmal[i]-leftSmal[i]-1));
        }

        
        return area;
    }
};