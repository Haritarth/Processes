#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int N = 4;
int solve(int i, int j, int a[N][N]){
	if(i < 0 || j < 0 || i > N-1 || j > N-1 || a[i][j] == 1)
		exit(0);
	if(i == N-1 && j == N-1 && a[i][j] == 0){
		printf("(%d, %d) ->", i, j);
		exit(1);
	}
	int found_r, found_d;
	pid_t right, down;
	right = fork();
	if(right == 0){
		solve(i, j+1, a);
		printf("kaise??");
	}
	down = fork();
	if(down == 0){
		solve(i+1, j, a);
		printf("kaise??");
	}
	waitpid(right, &found_r, 0);
	waitpid(down, &found_d, 0);
	if(found_r || found_d){
		if(i == 0 && j == 0){
			printf("(%d, %d)", i, j);
			printf("\nMJ successfully rescued.");
			return 1;
		}
		printf("(%d, %d) ->", i, j);
		exit(1);
	} else {
		if(i == 0 && j == 0)
		printf("Spiderman cannot rescue MJ.");
		exit(0);
	}
}

int main(void) {
	int a[4][4]	 = {{0, 0, 1, 0},
					{1, 0, 0, 0},
					{1, 0, 1, 0},
					{1, 1, 0, 0}};

					
	solve(0, 0, a);
}
