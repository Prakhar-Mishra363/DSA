class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        int area=0;
        int length=0;
        for(int i=0;i<arr.size();i++){
            int currDia=arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1];
            int currArea=arr[i][0]*arr[i][1];
            if(length<currDia){
                length=currDia;
                area=currArea;
            }
            if(length==currDia){
                area=max(area,currArea);
            }
        }
        return area;
    }
};