class Solution {
public:
   /*
   encode("neet","love") = stereter;
   decode(stereter) = "ne3et","love"; -> "3*ne3et4love"
   */
    string encode(vector<string>& strs) {
        string s="";
        for(int i=0;i<strs.size();++i){
            string a = to_string(strs[i].size());
            s += a;
            s += '*';
            s += strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        for(int i=0;i<s.size();){
            string num = "";
            while(s[i]!='*'){
                num+=s[i];
                ++i;
            }
            ++i;
            int limit = stoi(num);
            string aux = "";
            for(int k=0;k<limit;++k){
                aux+=s[i];
                ++i;
            }
            answer.push_back(aux);
        }
        return answer;
    }
};
