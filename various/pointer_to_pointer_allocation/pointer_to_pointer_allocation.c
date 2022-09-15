#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int is_sup(const void * val1, const void * val2) {
	return ( *((int*)val1) > *((int*)val2));
}


int main(){

	int **mat = NULL;

	float rand_limit = 100.f;

	const size_t size = 5;
	// allocate for a square matrix whitout checking

	mat = (int **) malloc(size * sizeof(int *));

	for(int i = 0; i < size;++i){
		mat[i] = (int *) malloc(size * sizeof(int));
	}
	srand(time(NULL));
	for(int i = 0; i < size;++i){
		for(int j = 0; j < size;++j){
			mat[i][j] = rand() * rand_limit / RAND_MAX + 1;
		}
	}

	printf("Before sort begin\n");
	for(int i = 0; i < size;++i){
		for(int j = 0; j < size;++j){
			printf("%3d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("Before sort end\n");

	for(int i = 0; i < size;++i){
		qsort(mat[i], size, sizeof(int), is_sup);
	}

	printf("After sort begin\n");
	for(int i = 0; i < size;++i){
		for(int j = 0; j < size;++j){
			printf("%3d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("After sort end\n");

	return EXIT_SUCCESS;
}

