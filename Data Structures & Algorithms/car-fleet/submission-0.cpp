class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();++i){
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(),v.end());

        stack<double> s;
        int counter=1;
        s.push((target-v[v.size()-1].first)/(1.0*v[v.size()-1].second));
        for(int i=v.size()-2;i>=0;--i){
            double current = ((target-v[i].first)/(1.0*v[i].second));
            while(!s.empty() && current>s.top()){
                s.pop();
            }

            if(s.empty()){
                counter++;
                s.push(current);
            } 
        }

        return counter;
    }
};
