class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;
        while(n>0){
            int m = n%10;
            arr.push_back(m);
            n/=10;
        }
        sort(arr.begin(),arr.end());
        int size = arr.size();
        int ans = arr[size-1]*arr[size-2];
        return ans;
    }
};