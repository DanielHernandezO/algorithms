class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int answer =0;

        for(int i=0;i<nums.size();++i){
            s.insert(nums[i]);
        }

        for(int i=0;i<nums.size();++i){
            if(s.count(nums[i]-1))continue;
            int head=nums[i]+1;
            int count=1;
            while(s.count(head)){
                count+=1;
                head+=1;
            }
            answer = max(answer, count);
        }
        return answer;
    }
};
