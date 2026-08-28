class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()-1, n = matrix[0].size()-1;
        int l=0,r=m, row = -1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][n]){
                row = mid;
                break;
            }else if(target>=matrix[mid][n])l = mid+1;
            else r = mid-1;
        }

        if(row>=0){
  
            l=0, r = n;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(matrix[row][mid] == target) return true;
                else if(matrix[row][mid] > target) r = mid-1;
                else l = mid+1;
            } 
        }

        return false;
    }
};
