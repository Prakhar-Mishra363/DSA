class Solution {
public:
    int areaOfHistogram(vector<int> &rec){
        vector<int> nextSmaller(rec.size() , 0);
        vector<int> prevSmaller(rec.size() , 0);
        stack<int>next, prev;
        next.push(rec.size()-1);
        prev.push(0);
        int i=1;
        for(int i=1; i<rec.size()-1 ; i++){
            while(rec[prev.top()] >= rec[i])prev.pop();
            prevSmaller[i]=prev.top();
            prev.push(i);
        }
        for(int i=rec.size()-2; i>=1 ; i--){
            while(rec[next.top()] >= rec[i])next.pop();
            nextSmaller[i]=next.top();
            next.push(i);
        }
        int area=0;
        for(int i=1;i<rec.size()-1;i++){
            area = max(area , rec[i] * (-prevSmaller[i] + nextSmaller[i]-1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> rec(matrix[0].size()+2 , 0);
        int area=0;
        rec[0]=rec[matrix[0].size()+1]=-1;
        for(int row=0 ; row<matrix.size() ; row++){
            for(int col=0 ; col<matrix[0].size() ; col++){
                rec[col+1] = (matrix[row][col] != '0') ? rec[col+1] + 1 : 0;
            }
            area = max(areaOfHistogram(rec) , area);
        }
        return area;
    }
};