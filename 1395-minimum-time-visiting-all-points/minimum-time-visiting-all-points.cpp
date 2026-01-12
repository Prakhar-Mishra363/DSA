class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int abscissa = points[0][0];
        int ordinate = points[0][1];
        // int currRow = 0;
        int n = points.size();
        int time = 0;
        for(int currRow = 0 ; currRow<n-1 ; currRow++){
                if(abscissa == points[currRow + 1][0] && ordinate != points[currRow + 1][1]){
                    time += abs(ordinate - points[currRow + 1][1]);
                    ordinate = points[currRow + 1][1];
                    continue;
                }else if(abscissa != points[currRow + 1][0] && ordinate == points[currRow + 1][1]){
                    time += abs(abscissa - points[currRow + 1][0]);
                    abscissa = points[currRow + 1][0];
                    continue;
                }
                while(((abscissa != points[currRow + 1][0] || ordinate != points[currRow + 1][1])) && currRow < n ){
                    if(abscissa > points[currRow + 1][0])abscissa--;
                    else if(abscissa < points[currRow + 1][0])abscissa++;
                    if(ordinate > points[currRow + 1][1])ordinate--;
                    else if(ordinate < points[currRow + 1][1])ordinate++;
                    time++;
                }
        }
        return time;
    }
};