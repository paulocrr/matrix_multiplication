#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <ctime>
#include <chrono>

using namespace std;

#define MAX 400

void fillMatrix(int a[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            a[i][j] = rand()%10;
        }
    }
}

void printMatrix(int a[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cout << a[i][j] << "-";
        }
        cout << endl;
    }
    cout << endl;
}

void matrixProduct(int a[MAX][MAX],int b[MAX][MAX]){
    int res[MAX][MAX] = {0};
    for(int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            for(int k = 0; k < MAX; ++k){
                res[i][j] += a[i][k] * b[k][j];
            }
        }   
            
    }
        
    //printMatrix(res);
}

void matrixBlockProduct(int a[MAX][MAX],int b[MAX][MAX]){
    int res[MAX][MAX] = {0};
    int step = MAX/2;
    for (int jj=0; jj<MAX; jj+=step) {
        for (int i=0; i<MAX; i++)
			for (int j=jj; j < min(jj+step,MAX); j++)
				res[i][j] = 0.0;
		for (int kk=0; kk<MAX; kk+=step) {
			for (int i=0; i<MAX; i++) {
				for (int j=jj; j < min(jj+step,MAX); j++) {
					for (int k=kk; k < min(kk+step,MAX); k++) {
						res[i][j] += a[i][k] * b[k][j];
					}
				}
			}
		}
	}
    //printMatrix(res);
}


int main(){
    srand(time(NULL));
    int a[MAX][MAX];
    int b[MAX][MAX];
    fillMatrix(a);
    fillMatrix(b);
    unsigned t0, t1;
	  t0 = clock();
    matrixProduct(a,b);
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout<<"Multiplicacion de Matrices: " << time << endl;
    t0 = clock();
    matrixBlockProduct(a,b);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout<< "Multiplicacion de Matrices por Bloques: " << time << endl;
    return 0;
}
