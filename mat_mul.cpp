#include <iostream>   
#include <time.h>
#include <string.h>
#include <math.h>
using namespace std;   

#define MATRIX_SIZE 1024

int main() {
    clock_t start, finish;
    clock_t start_new, finish_new;

    register int i, j, k;

    int (*a)[MATRIX_SIZE], (*b)[MATRIX_SIZE];
    a = new int[MATRIX_SIZE][MATRIX_SIZE];
    b = new int[MATRIX_SIZE][MATRIX_SIZE];


    for(i = 0; i < MATRIX_SIZE; i ++) {
        for(j = 0; j < MATRIX_SIZE; j ++) {
            a[i][j] = i % (j + 1);
            b[i][j] = i / (j + 1);
        }
    }

    int (*c)[MATRIX_SIZE], (*d)[MATRIX_SIZE];
    c = new int[MATRIX_SIZE][MATRIX_SIZE];
    d = new int[MATRIX_SIZE][MATRIX_SIZE];

    // initialize
    memset(d, 0, MATRIX_SIZE * MATRIX_SIZE * sizeof(int));

    start_new = clock();

    // TODO: Your optimized code:
    //======================================================

    for (i = 0; i < MATRIX_SIZE; i ++)
        for (k = 0; k < MATRIX_SIZE; k++) {
            int x = a[i][k];
            for (j = 0; j < MATRIX_SIZE; j += 32) {
                int *d1 = &d[i][j];
                int *b1 = &b[k][j];
                d1[0] += x * b1[0];
                d1[1] += x * b1[1];
                d1[2] += x * b1[2];
                d1[3] += x * b1[3];
                d1[4] += x * b1[4];
                d1[5] += x * b1[5];
                d1[6] += x * b1[6];
                d1[7] += x * b1[7];
                d1[8] += x * b1[8];
                d1[9] += x * b1[9];
                d1[10] += x * b1[10];
                d1[11] += x * b1[11];
                d1[12] += x * b1[12];
                d1[13] += x * b1[13];
                d1[14] += x * b1[14];
                d1[15] += x * b1[15];
                d1[16] += x * b1[16];
                d1[17] += x * b1[17];
                d1[18] += x * b1[18];
                d1[19] += x * b1[19];
                d1[20] += x * b1[20];
                d1[21] += x * b1[21];
                d1[22] += x * b1[22];
                d1[23] += x * b1[23];
                d1[24] += x * b1[24];
                d1[25] += x * b1[25];
                d1[26] += x * b1[26];
                d1[27] += x * b1[27];
                d1[28] += x * b1[28];
                d1[29] += x * b1[29];
                d1[30] += x * b1[30];
                d1[31] += x * b1[31];
            }
        }
    
    // Stop here.
    //======================================================

    finish_new = clock();

    int (*a_)[MATRIX_SIZE], (*b_)[MATRIX_SIZE];
    a_ = new int[MATRIX_SIZE][MATRIX_SIZE];
    b_ = new int[MATRIX_SIZE][MATRIX_SIZE];


    for (i = 0; i < MATRIX_SIZE; i ++) {
        for (j = 0; j < MATRIX_SIZE; j ++) {
            a_[i][j] = i % (j + 1);
            b_[i][j] = i / (j + 1);
        }
    }

    // initialize
    memset(c, 0, MATRIX_SIZE * MATRIX_SIZE * sizeof(int));

    start = clock();
    for (i = 0; i < MATRIX_SIZE; i ++)
        for (j = 0; j < MATRIX_SIZE; j ++)
            for (k = 0; k < MATRIX_SIZE; k ++)
                c[i][j] += a_[i][k] * b_[k][j];
    finish = clock();


    // compare
    for(i = 0; i < MATRIX_SIZE; i++) {
        for(j = 0; j < MATRIX_SIZE; j++) {
            if (c[i][j] != d[i][j]) {
                cout << "you have got an error in algorithm modification!" << endl;
                exit(1);
            }
        }
    }

    cout << "time spent for original method : " << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
    cout << "time spent for new method : " << (double)(finish_new - start_new) / CLOCKS_PER_SEC << " s" << endl;
    cout << "time ratio of performance optimization : " << (double)(finish - start) / (finish_new - start_new) << endl;
    return 0;
}
