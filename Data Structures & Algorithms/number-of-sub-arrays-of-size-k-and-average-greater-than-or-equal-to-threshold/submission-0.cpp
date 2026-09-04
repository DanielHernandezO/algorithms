class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int answer =0;
        int sum =0;
        for(int i=0;i<k;++i){
            sum+= arr[i];
        }
    
        if((static_cast<double>(sum)/k)>=threshold) answer++;
        
        for(int i=k;i<arr.size();++i){
            sum-= arr[i-k];
            sum+=arr[i];
            if((static_cast<double>(sum)/k)>=threshold) answer++;
        }

        return answer;
    }
};