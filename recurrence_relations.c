////////////////1. Recursive approach function: /////////////////

int fibonacciRecursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return fibonacciRecursive(n - 3) + fibonacciRecursive(n - 2);
}

/////ADVANTAGES ADN DISADVANTAGES OF THE RECURSIVE APPROACH//////
/*

-> Advantages 
    Simple and easy to understand.
-> Disadvantages
    Inefficient for larger values of n due to repeated computations (exponential time complexity).


*/


///////////////2. Iterative approach: ///////////////////////

int fibonacciIterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    return dp[n];
}

/////////////ADVANTAGES AND DISADVANTAGES OF THE ITERATIVE APPROACH///////////////////////////
/*
    Also Bottom-up Dynamic Programming

-> Advantages 
    More efficient than the recursive approach for larger values of n. Avoids repeated computations (linear time complexity).
-> Disadvantages 
    Requires additional memory for the DP array.

*/



////////////////3. top -down approach - Memoization://///////////////

int memo[1000]; // Assuming the maximum value of n is 1000

int fibonacciMemo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacciMemo(n - 3) + fibonacciMemo(n - 2);
    return memo[n];
}

///////ADVANTAGES AND DISADVANTAGES OF MEMOIZATION APPROACH//////////////////////////////
/*
Also Top-down Dynamic Programming
-> Advantages 
    Similar to the bottom-up approach but avoids unnecessary computations using memoization.
-> Disadvantages 
    Requires additional memory for memoization array.

*/
