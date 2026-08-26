class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int bestArea=0;
        while(l<r){
            int currentArea = min(heights[l],heights[r])*(r-l);
            bestArea = max(bestArea, currentArea);
            if(heights[l]>heights[r])r--;
            else l++;
        }
        return bestArea;
    }
};
