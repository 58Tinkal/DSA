//C[i][j] = iCj % Q
const int Q = 1e9 + 7;  
const int N = 1e5 + 9;  / Max rows
const int M = 109;      // Max columns (k)

int C[N][M];

// Build Pascal's triangle up to n rows and k columns
void buildPascal(int n, int k) {
    C[0][0] = 1;
    C[1][0] = 1;
    C[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        C[i][0] = 1;
        if (i < M) C[i][i] = 1;
        for (int j = 1; j <= k && j < i; j++) {
            int val = C[i-1][j] + C[i-1][j-1];
            if (val >= Q) val -= Q; 
            C[i][j] = val;
        }
    }
}
