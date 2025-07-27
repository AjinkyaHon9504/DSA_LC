class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        
        //base case
        if(n==0){
            return 1;
        }

        if(N<0){
           
            x=1/x;
             N=-N;
        }

        return power(x,N);
    }

    double power(double x, long long n) {

        //base case
         if(n==0){
            return 1;
        }
         if(n==1){
            return x;
        }
        int p = n/2;
        
        double half = power(x,p);
        if(n%2 == 0){  //even 
        return half * half;
        } 
        else{
            return half * half * x;
        }

    }

    //divide and conquer


};
