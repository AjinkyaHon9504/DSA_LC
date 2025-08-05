class Solution {
public:
 vector<vector<string>> result; 

  bool isPalindrome(const string &s, int left, int right) {
    while(right>left){
        if(s[left]!=s[right]) return false;
        left++;
        right--;
    }
    return true;
  }
    void backtrack(string &s,vector<string> &current,int index){
      if (index == s.size()) {
            result.push_back(current); 
            return;
        }
       for (int end = index; end < s.size(); ++end) {
            if (isPalindrome(s, index, end)) {
                current.push_back(s.substr(index, end - index + 1));
                backtrack(s,current,end + 1);
                current.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtrack(s,current,0);
        return result;
    }
};




