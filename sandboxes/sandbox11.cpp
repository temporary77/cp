//gcc -Og matsq.c -o matsq
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma GCC optimize ("Og")
#define ITER 10
#define SEED 2023
#define SIZE 1000

int arr[SIZE][SIZE];

int main(){
    srand(SEED);
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            arr[i][j] = rand()%100;
        }
    }

    clock_t begin, end;

    begin = clock();
    for(int i=0; i<ITER; i++){
        /*put your code here*/
        int ans[SIZE][SIZE];
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                ans[i][j] = 0;
                for(int k = 0; k < SIZE; k++){
                    ans[i][j] += arr[i][k] * arr[k][j];
                }
            }
        }
    }
    end = clock();
    double base_line = ((double) (end - begin)) / CLOCKS_PER_SEC;
    printf("base_line runtime = %lf sec.\n",base_line);

    begin = clock();
    int i0, i1, i2, i3, i4, j0, j1, j2, j3, j4;
    for(int i=0; i<ITER; i++){
        /*put your code here*/
    	int ans[SIZE][SIZE] = {0};
        for(int k = 0; k < SIZE; k++){
	        for(int i = 0; i < SIZE; i += 5){
                for(int j = 0; j < SIZE; j += 5){
                	i0 = arr[i][k];
                	i1 = arr[i+1][k];
                	i2 = arr[i+2][k];
                	i3 = arr[i+3][k];
                	i4 = arr[i+4][k];
                	j0 = arr[k][j];
                	j1 = arr[k][j+1];
                	j2 = arr[k][j+2];
                	j3 = arr[k][j+3];
                	j4 = arr[k][j+4];
                    ans[i][j] += i0 * j0;
                    ans[i][j+1] += i0 * j1;
                    ans[i][j+2] += i0 * j2;
                    ans[i][j+3] += i0 * j3;
                    ans[i][j+4] += i0 * j4;
                    ans[i+1][j] += i1 * j0;
                    ans[i+1][j+1] += i1 * j1;
                    ans[i+1][j+2] += i1 * j2;
                    ans[i+1][j+3] += i1 * j3;
                    ans[i+1][j+4] += i1 * j4;         
                    ans[i+2][j] += i2 * j0;
                    ans[i+2][j+1] += i2 * j1;
                    ans[i+2][j+2] += i2 * j2;
                    ans[i+2][j+3] += i2 * j3;
                    ans[i+1][j+4] += i2 * j4;
                    ans[i+3][j] += i3 * j0;
                    ans[i+3][j+1] += i3 * j1;
                    ans[i+3][j+2] += i3 * j2;
                    ans[i+3][j+3] += i3 * j3;
                    ans[i+1][j+4] += i3 * j4;
                    ans[i+4][j] += i4 * j0;
                    ans[i+4][j+1] += i4 * j1;
                    ans[i+4][j+2] += i4 * j2;
                    ans[i+4][j+3] += i4 * j3;
                    ans[i+4][j+4] += i4 * j4;
                }
            }
        }
    }
    end = clock();
    double cpu_time = ((double) (end - begin)) / CLOCKS_PER_SEC;
    printf("runtime = %lf sec.\n",cpu_time);
    printf("%lf percent faster\n",((base_line-cpu_time)/(cpu_time)*100));
}