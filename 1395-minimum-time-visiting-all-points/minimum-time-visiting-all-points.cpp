class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int abscissa = points[0][0];
        int ordinate = points[0][1];
        // int currRow = 0;
        int n = points.size();
        int time = 0;
        for(int currRow = 0 ; currRow<n-1 ; currRow++){
            time += max(abs(points[currRow][0] - points[currRow + 1][0]) , abs(points[currRow][1] - points[currRow + 1][1]));
        }
        return time;
    }
};