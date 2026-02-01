class Solution {
public:
    void reverseString(vector<char>& s) {
        //swap s[i] to s[n-1-i]
        int left = 0;
        int right = s.size()-1;
        while(right>left){
            swap(s[left],s[right]);
            left++;
            right--;
        }

    }
};