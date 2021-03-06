#include<stdio.h>
#include <stdlib.h>
#define N 64
#define BLOCK_DIM 16


#define BLK_ROWS 2
#define BLK_COLS 2
//size of the share memory tile in the device
#define TILE_SIZE BLK_ROWS
__global__ void matrixmul (int *a, int *b, int *c,int a_rows, int a_columns, int b_columns);
void printArray(int a[N][N], int b[N][N], int c[N][N]);

int main() {
    int a[N][N], b[N][N], c[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = i+j;
            b[i][j] = i-j;
            c[i][j] = 0;
        }
    }
    int *dev_a, *dev_b, *dev_c;
    int size = N * N * sizeof(int);
    clock_t t;
	double time_taken;

    FILE *fp;
    fp = fopen ("output.txt","a");

    t = clock();

    // initialize a and b with real values (NOT SHOWN)
    cudaMalloc((void**) &dev_a, size);
    cudaMalloc((void**) &dev_b, size);
    cudaMalloc((void**) &dev_c, size);

    cudaMemcpy (dev_a, a, size, cudaMemcpyHostToDevice) ;
    cudaMemcpy (dev_b, b, size, cudaMemcpyHostToDevice) ;

    dim3 dimBlock(BLK_COLS,BLK_ROWS);
    dim3 dimGrid((int)ceil(N/BLK_COLS),(int)ceil(N/BLK_ROWS));
    
    matrixmul<<<dimGrid, dimBlock>>> (dev_a,dev_b,dev_c,N,N,N);

    cudaMemcpy(c, dev_c, size, cudaMemcpyDeviceToHost) ;
    cudaFree(dev_a); 
    cudaFree(dev_b); 
    cudaFree(dev_c);

    t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Matrix multiplication for 2-D array of size %dx%d and block size 16x16 and tile size 2x2 took %lf seconds to execute \n", N, N, time_taken); 

	fprintf (fp, "%d %lf\n", N, time_taken);

    fclose(fp);

    // printArray(a,b,c);

    exit (0);
}

__global__ void matrixmul (int *a, int *b, int *c,int a_rows, int a_columns, int b_columns) {
    //declare shared memory matrices for A and B matrices
	__shared__ int shared_a_tile[TILE_SIZE][TILE_SIZE];
	__shared__ int shared_b_tile[TILE_SIZE][TILE_SIZE];

	int tx = threadIdx.x;
	int ty = threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;
	int row = blockIdx.y * blockDim.y + threadIdx.y;

	//check if thread directly maps to the dimensions of the resulting matrix
	if (row < a_rows && col < b_columns)
	{
		int result = 0;
		int k;
		int phase;
		
		//calculate C matrix indexes in phases. Each phase shares 
		//TILE_SIZE * TILE_SIZE data copied to the shared matrix A 
		//and matrix B.
		for (phase = 0; phase <= a_columns/TILE_SIZE; phase++)
		{
			shared_a_tile[ty][tx] = a[row * a_columns + phase * TILE_SIZE + tx];
			shared_b_tile[ty][tx] = b[(phase * TILE_SIZE + ty) * b_columns + col];
			__syncthreads();
			
			for (k = 0; k < TILE_SIZE; k++)
			{
				if (k + (phase * TILE_SIZE) < a_columns) 
				{
					result += (shared_a_tile[ty][k] * shared_b_tile[k][tx]);
				}
			}
			__syncthreads();
		}	
		c[row * b_columns + col] = result;
	}
}

void printArray(int a[N][N], int b[N][N], int c[N][N]) {

    printf("Array a:\n");
	for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\nArray b:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n\nArray c:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}