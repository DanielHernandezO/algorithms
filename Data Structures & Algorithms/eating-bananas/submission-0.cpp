class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=0;
        for(int i=0;i<piles.size();++i){
            r = max(r, piles[i]);
        }
        while(l<=r){
            int mid = l +(r-l)/2;
            int t = getTime(piles, mid);
            if(t>h)l = mid+1;
            else r = mid-1;
        }
        cout<<l<<" "<<r<<endl;
        return l;
    }

    int getTime(vector<int>& piles, int n){
        int amount =0;
        for(int i=0;i<piles.size();++i){
            amount += ceil(piles[i]/(1.0*n));
        }
        cout<<"n: "<<n<<" amount: "<<amount<<endl;
        return amount;
    }
};
