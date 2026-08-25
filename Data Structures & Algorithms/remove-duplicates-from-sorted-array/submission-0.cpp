class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter=1;
        int index=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[index])continue;
            index++;
            nums[index]=nums[i];
            counter++;
        }
        return counter;
    }
};