class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(),0);
        stack<pair<int,int>> s;
        for(int i=0;i<temperatures.size();++i){
            while(!s.empty() && s.top().first<temperatures[i]){
                pair<int,int> top = s.top();
                answer[top.second] = i-top.second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return answer;
    }
};

