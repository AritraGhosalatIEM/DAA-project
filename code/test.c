#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<time.h>
#define INT_SIZE 4
int main(int argc,char** argv){
	const uint32_t low=atoi(argv[1]),max=atoi(argv[2]),jump=atoi(argv[3]),tests=atoi(argv[4]);
	int32_t* data=malloc(INT_SIZE*max);
	int32_t* data_slice=malloc(INT_SIZE*max);
	FILE* data_file=fopen("numbers.dat","r");
	fread(data,INT_SIZE,max,data_file);
	fclose(data_file);
	clock_t start;
	for(uint32_t numbers=low;numbers<max;numbers+=jump){
		clock_t total_ticks=0;
		for(uint32_t _=0;_<tests;_++){
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
