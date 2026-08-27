class Solution {
public:
    int trap(vector<int>& height) {
        int answer =0;
        vector<int> lmax(height.size(), 0);
        vector<int> rmax(height.size(), 0);

        for(int i=1;i<height.size();++i){
            lmax[i] = max(height[i-1], lmax[i-1]);
        }

        for(int i=height.size()-2; i>=0;--i){
            rmax[i] = max(height[i+1], rmax[i+1]);
        }

        for(int i=0;i<height.size();++i){
            int current = min(lmax[i],rmax[i])-height[i];
            answer += (current>0 ? current : 0);
        }
        return answer;
    }
};
