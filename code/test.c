#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<time.h>
#define INT_SIZE 4
#define LOW 100
#define JUMP 500
#define TESTS 10
#define MAX 10000
int main(int argc,char** argv){
	int32_t* data=malloc(INT_SIZE*MAX);
	int32_t* data_slice=malloc(INT_SIZE*MAX);
	FILE* data_file=fopen("numbers.dat","r");
	fread(data,INT_SIZE,MAX,data_file);
	fclose(data_file);
	clock_t start;
	for(uint32_t numbers=LOW;numbers<MAX;numbers+=JUMP){
		clock_t total_ticks=0;
		for(uint32_t _=0;_<TESTS;_++){
			memcpy(data_slice,data,INT_SIZE*numbers);
			start=clock();
			sort(data_slice,numbers);
			total_ticks+=(clock()-start);
		}
		printf("%d,",(int)total_ticks);//output csv
	}
	printf("\n");
	return 0;
}
