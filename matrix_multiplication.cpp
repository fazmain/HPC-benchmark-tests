// matrix_multiplication.cpp

#include <iostream>
#include <vector>
#include <chrono>  // for measuring time

using namespace std;

// Function to multiply two 500x500 matrices
void multiply_matrices(const vector<vector<double> >& A,
                       const vector<vector<double> >& B,
                       vector<vector<double> >& C) {
    int N = 500;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
}

int main() {
    const int N = 500;

    // Step 1: Initialize matrices A and B with dummy values
    vector<vector<double> > A(N, vector<double>(N, 1.0));  // All elements = 1.0
    vector<vector<double> > B(N, vector<double>(N, 5.0));  // All elements = 2.0
    vector<vector<double> > C(N, vector<double>(N, 0.0));  // To store result

    // Step 2: Measure runtime
    auto start = chrono::high_resolution_clock::now();

    multiply_matrices(A, B, C);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    // Step 3: Output time taken
    cout << "Matrix multiplication took " << elapsed.count() << " seconds." << endl;
    


    return 0;
}
