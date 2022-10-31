#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
// Function to find the most efficient way to multiply
// a given sequence of matrices
int matrixChainMultiplication(vector<int> const &dims, int i, int j)
{
    // base case: one matrix
    if (j <= i + 1) {
        return 0;
    }

    int min = INT_MAX;
 
 
    for (int k = i + 1; k <= j - 1; k++)
    {
        // recur for `M[i+1]…M[k]` to get an `i × k` matrix
        int cost = matrixChainMultiplication(dims, i, k);
 
        // recur for `M[k+1]…M[j]` to get an `k × j` matrix
        cost += matrixChainMultiplication(dims, k, j);
 
        // cost to multiply two `i × k` and `k × j` matrix
        cost +=    dims[i] * dims[k] * dims[j];
 
        if (cost < min) {
            min = cost;
        }
    }
 
    
    return min;
}
 
// Matrix Chain Multiplication Problem
int main()
{
    
    vector<int> dims = { 30, 35, 15, 5, 10, 20, 25 };
    int n = dims.size();
 
    cout << "The minimum cost is " << matrixChainMultiplication(dims, 0, n - 1);
 
    return 0;
}