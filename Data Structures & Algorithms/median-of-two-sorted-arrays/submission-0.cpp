class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int amount  = nums1.size()+nums2.size();
        int half = amount/2;

        int l=0, r=nums1.size();
        while(l<=r){
            int i = l+(r-l)/2;
            int j = half-i;
            cout<<"l: "<<l<<" r: "<<r<<endl;
            cout<<"i: "<<i<<" j: "<<j<<endl;

            int n1R = i<nums1.size() ? nums1[i]: INT_MAX;
            int n1L = i>0 ? nums1[i-1]: INT_MIN;
            int n2R = j<nums2.size() ? nums2[j]: INT_MAX;
            int n2L = j>0 ? nums2[j-1]: INT_MIN;

            cout<<"n1L: "<<n1L<<" n1R: "<<n1R<<endl;
            cout<<"n2L: "<<n2L<<" n2R: "<<n2R<<endl;

            if(n2R>=n1L && n1R>=n2L){
                if(amount%2){
                    return min(n1R, n2R);
                }
                return (max(n1L, n2L)+min(n1R, n2R))/2.0;
            }else if(n2R<n1L) r = i-1;
            else l = i+1;
        }
        return -1;
    }
};
