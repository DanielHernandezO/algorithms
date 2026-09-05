class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=0;
        int maxi = 0;
        while(r<prices.size()){
            if(prices[r]<=prices[l]){
                l=r;r++;
            }else{
                maxi = max(maxi, prices[r]-prices[l]);
                r++;
            }
        }
        return maxi;
    }
};
