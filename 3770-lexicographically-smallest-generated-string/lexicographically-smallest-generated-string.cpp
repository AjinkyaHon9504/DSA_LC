class Solution {
public:
    bool isSame(string &word, string &str2, int i, int m){
        for(int j = 0; j < m; j++){
            if(word[i + j] != str2[j]){  // FIXED
                return false;
            }
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;

        string word(N, '$');
        vector<bool> canChange(N, false);

        // Step 1: force 'T'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(word[i + j] != '$' && word[i + j] != str2[j]){
                        return "";
                    }
                    word[i + j] = str2[j];
                }
            }
        }

        // Step 2: fill remaining with 'a'
        for(int i = 0; i < N; i++){
            if(word[i] == '$'){
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        // Step 3: process 'F'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                if(isSame(word, str2, i, m)){
                    bool changed = false;

                    // try to break from right side
                    for(int a = i + m - 1; a >= i; a--){
                        if(canChange[a]){
                            word[a] = 'b';  // change to break equality
                            changed = true;
                            break;
                        }
                    }

                    if(!changed){
                        return "";
                    }
                }
            }
        }

        return word;  // FIXED (missing return)
    }
};