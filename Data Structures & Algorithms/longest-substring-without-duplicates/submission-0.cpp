class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int maxi =0;
        for(int l=0,r=0;r<s.size();r++){
            if(m[s[r]]){
                while(m[s[r]]!=0){
                    m[s[l]]--;
                    l++;
                }
            }
            m[s[r]]++;
            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};
