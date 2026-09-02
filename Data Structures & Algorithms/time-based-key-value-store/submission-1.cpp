class TimeMap {
public:
    map<string, vector<pair<int, string>>> store;

    TimeMap() {   }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l=0, r= store[key].size()-1;
        string result="";

        while(l<=r){
            int m = l+(r-l)/2;
            if(store[key][m].first<=timestamp){
                result = store[key][m].second;
                l = m+1;
            }else r = m-1;
        }
        return result;
    }
};
