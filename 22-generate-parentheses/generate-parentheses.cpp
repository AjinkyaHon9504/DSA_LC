class Solution {
public:

vector<string> result;
void backtrack(string current, int open, int close){

        if (open == 0 && close == 0) {
            result.push_back(current);  // valid complete combination
            return;
        }

        if(open>0){
            //open
            backtrack(current + "(", open - 1, close);
        }
        if(close>open){
            //then close
           backtrack(current + ")", open, close - 1);
        }
}
    vector<string> generateParenthesis(int n) {
        //well formed means closed

        // base layer ()
        // second layer 1.add ( to start and ) to end  && 2.add() in start of couple /end
        // next layer 1.add ( to start and ) to end of each sub layer && 2.add() in start of couple /end
        backtrack("", n, n);
        return result;


    }
};



// recurssion tree
