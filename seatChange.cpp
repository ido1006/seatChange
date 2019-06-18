#include <random>
#include <algorithm>
#include <vector>
#include <iostream>

#define STU_NUM 37
#define DEPTH 5
#define WIDTH 8
using namespace std;

void fisherYatesShuffle(int array[]);

int main(){
	int students[STU_NUM];
	int mem=0;
	for(int i=0;i<STU_NUM;i++){
		mem++;
		if(mem==7||mem==29){
			mem++;
		}
		students[i] = mem;
	}

	fisherYatesShuffle(students);

	int seats[DEPTH][WIDTH]={0,1,1,1,1,1,1,1,
                           1,1,1,1,1,1,1,1,
                           1,1,1,1,1,1,1,0,
                           1,1,1,1,1,1,1,0,
                           1,1,1,1,1,1,1,1};
	mem = 0;
	for(int i=0;i<DEPTH;i++){
		for(int j=0;j<WIDTH;j++){
			if(seats[i][j]==1){
				printf("[%2d] ",students[mem]);
				mem++;
			}
			else{
				printf("[  ] ");
			}
		}
		printf("\n");
	}
	printf("----------------[教卓]----------------\n");
	return 0;
}

void fisherYatesShuffle(int array[]){
	int a,b;
	random_device rnd;
	for(int i=STU_NUM;i>1;--i){
		a=i-1;
		b=rnd()%i;
		int tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}

