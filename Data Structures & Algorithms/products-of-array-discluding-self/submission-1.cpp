class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        vector<int> pre(nums.size()+1,1), suf(nums.size()+1,1);
        for(int i=1;i<=nums.size();++i){
            pre[i] = pre[i-1]*nums[i-1];
        }

        for(int i=nums.size()-1;i>=0;--i){
            suf[i] = suf[i+1]*nums[i];
        }

        for(int i=0;i<pre.size()-1;++i){
            answer.push_back(pre[i]*suf[i+1]);
        }
        return answer;
    }
};
