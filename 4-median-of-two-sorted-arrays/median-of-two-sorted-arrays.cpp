class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int low = 0;
        vector<int>vec;
        for (int x : nums1) vec.push_back(x);
        for (int x : nums2) vec.push_back(x);
        sort(vec.begin(),vec.end());
        int p = vec.size();
        int median;
        if(p%2==1){ //odd numbers 
        return vec[p/2];
        }
        else{
            return ((vec[p/2] + vec[p/2 - 1] )/2.0);
        }
        return median;
    }
};