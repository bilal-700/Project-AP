#include <iostream>
#include </tmp/eigen-git-mirror-master/Eigen/Dense>
#include <algorithm>	
#include <time.h>
#include <cstdlib>

using namespace Eigen;
using namespace std;
//Efficiency of program increased by using dynamic memory allocation. Because heap is easy to implement, size not fixed like stack.
int** initializeMatrix(int n) {
    int** temp = new int*[n];//int **temp is such a pointer that can store memory address of another pointer. *[n] declaring an array of n pointers on heap.In short making 2D arrays on heap
    for(int i=0; i<n; i++)
        temp[i] = new int[n]; 
    return temp;
}

int** add(int** M1, int** M2, int n) {
    int** temp = initializeMatrix(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

int** subtract(int** M1, int** M2, int n) {
    int** temp = initializeMatrix(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}
int** strassenMultiply(int** A, int** B, int n) {
    if (n == 1) {//Base case_ when the dimension of the matrix is of dimension 1 x 1 and the product of two elements is returned.
        int** C = initializeMatrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    //Declaring C and calculating dimension of sub-matrices
    int** C = initializeMatrix(n);
    int k = n/2;
    //Initializing sub-matrices and defining sub-matrices
    int** A11 = initializeMatrix(k);
    int** A12 = initializeMatrix(k);
    int** A21 = initializeMatrix(k);
    int** A22 = initializeMatrix(k);
    int** B11 = initializeMatrix(k);
    int** B12 = initializeMatrix(k);
    int** B21 = initializeMatrix(k);
    int** B22 = initializeMatrix(k);

    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k+j];
            A21[i][j] = A[k+i][j];
            A22[i][j] = A[k+i][k+j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k+j];
            B21[i][j] = B[k+i][j];
            B22[i][j] = B[k+i][k+j];
        }
    //Calculating the product P1 to P7 and the resulting matrix C using formulas
    //P1 = A11 . (B12-B22)
    //P2 = (A11+A12) . B22
    //P3 = (A21+A22) . B11
    //P4 = A22 . (B21-B11)
    //P5= (A11+A22).(B11+B22)
    //P6 = (A12 -A22).(B21+B22)
    //P7 = (A11-A21).(B11+B12)
    int** P1 = strassenMultiply(A11, subtract(B12, B22, k), k);
    int** P2 = strassenMultiply(add(A11, A12, k), B22, k);
    int** P3 = strassenMultiply(add(A21, A22, k), B11, k);
    int** P4 = strassenMultiply(A22, subtract(B21, B11, k), k);
    int** P5 = strassenMultiply(add(A11, A22, k), add(B11, B22, k), k);
    int** P6 = strassenMultiply(subtract(A12, A22, k), add(B21, B22, k), k);
    int** P7 = strassenMultiply(subtract(A11, A21, k), add(B11, B12, k), k);

    //C11 = P5 + P4 + P6 - P2
    //C12 = P1 + P2
    //C13 = P3 + P4
    //C14 = P5 + P1 -P3 - P7 
    int** C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
    int** C12 = add(P1, P2, k);
    int** C21 = add(P3, P4, k);
    int** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);
    
    //Copying values to C and returning C
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++) {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[k+i][j] = C21[i][j];
            C[k+i][k+j] = C22[i][j];
        }
    }
    //'new' operator is used for dynamic memory allocation which puts variables on heap memory.
    //Does not destroy the pointer, rather the memory space used by the pointer gets deleted.
    for(int i=0; i<k; i++) {//Delete operator deallocates memory from heap
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] P1[i];
        delete[] P2[i];
        delete[] P3[i];
        delete[] P4[i];
        delete[] P5[i];
        delete[] P6[i];
        delete[] P7[i];
        delete[] C11[i];
        delete[] C12[i];
        delete[] C21[i];
        delete[] C22[i];
    }
        
    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] P1;
    delete[] P2;
    delete[] P3;
    delete[] P4;
    delete[] P5;
    delete[] P6;
    delete[] P7;
    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;

    return C;
}
//Strassen algorithm_ Recursive method for matrix multiplication. We divide the matrix into 4 sub-matrices of dimensions n/2 x n/2 in each recursive step.
//divide and conquer approach
//Strassen’s algorithm has a few disadvantages:
//Recursion stack consumes more memory.
//The recursive calls add latency.
int main() {
    srand(time(NULL));
    int max;
    max = 100;
    int size[] = { 2, 4, 8, 16, 32, 64, 128};

    cout << "\n\t    ********* Strassen's Algorithm *********" << endl;
    cout << "Conditions:\n\t1)Both input matrices should be of dimensions n x n." << endl;
    cout << "\t2)n should be a power of 2.\n";
   
    for(int l = 0; l < 7; l++) { // for each size from 2^1 to 2^7
	    int n = size[l];
	    //Initializing Eigen Matrices
	    Eigen::MatrixXd a_E(n,n);
	    Eigen::MatrixXd b_E(n,n);
	    Eigen::MatrixXd c_E(n,n);
	    
	    int** A = initializeMatrix(n);
	    int** B = initializeMatrix(n);
	    
	    for(int i = 0; i < n; i++){//randomly generating values for matrix A
		for(int j = 0; j < n; j++){
		    int r = rand() % max;
		    A[i][j] = r;
		    a_E(i,j) = A[i][j];
		}
            }		
	    
	    for(int i=0; i < n; i++){//randomly generating values for matrix B
		for(int j = 0; j<n; j++){
		    int g = rand() % max;
		    B[i][j] = g;
		    b_E(i,j) = B[i][j];
		}
	    } 
	    
	    double CPS  =   CLOCKS_PER_SEC;
	    clock_t start, end;
	    int** C = initializeMatrix(n);
	    
	    cout << endl << "Running test for size = " << n << " by " << n << endl;
	    start = clock();
	    C = strassenMultiply(A, B, n);
	    end = clock();
	    cout << "Time taken by Strassen's Algo is: " << (end-start)/CPS << endl;
	    
	    start = clock();
	    c_E = a_E * b_E;
	    end = clock();
	    cout << "Time taken by Eigen is: " << (end-start)/CPS << endl;
	    
	    for(int i=0; i<n; i++)
		delete[] A[i];
	    delete[] A;

	    for(int i=0; i<n; i++)
		delete[] B[i];
	    delete[] B;

	    for(int i=0; i<n; i++)
		delete[] C[i];
	    delete[] C;
	}
    cout << endl << "Eigen is faster because:\n\t1) Dynamic memory allocation is avoided.\n\t2) Loops unroll when makes sense.\n\nFor large matrices, eigen pays attention to cache-friendliness.";
    cout << endl;
    return 0;
}
//Loops unroll Example:
//for (int i=0; i<n; i++)
//{
//  sum += data[i];
//}

//for (int i=0; i<n; i+=4)
//{
//  sum1 += data[i+0];
//  sum2 += data[i+1];
//  sum3 += data[i+2];
//  sum4 += data[i+3];
//}
//sum = sum1 + sum2 + sum3 + sum4;
