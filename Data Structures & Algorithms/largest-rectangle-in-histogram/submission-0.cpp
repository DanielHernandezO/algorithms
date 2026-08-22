class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int maxArea=0;
        for(int i=0;i<heights.size();++i){
            if(s.empty()) {
                s.push({heights[i],i});
                continue;
            }   
            int index = i;
            while(!s.empty() && s.top().first>heights[i]){
                index = s.top().second;
                maxArea = max(maxArea, s.top().first * (i-index));
                s.pop();
            }
            s.push({heights[i],index});
        }

        while(!s.empty()){
            int currentArea = (s.top().first * (heights.size()-s.top().second));
            maxArea= max(maxArea, currentArea);
            s.pop();
        }

        return maxArea;
    }
};
