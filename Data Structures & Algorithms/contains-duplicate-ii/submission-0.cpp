class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> slice;
        for(int i=0;i< min(k+1, (int)nums.size());++i){
            if(slice.find(nums[i])!= slice.end()) return true;
            slice.insert(nums[i]);
        }

        for(int i=k+1;i<nums.size();++i){
            slice.erase(nums[i-k-1]);
            if(slice.find(nums[i])!= slice.end()) return true;
            slice.insert(nums[i]);
        }

        return false;
    }
};