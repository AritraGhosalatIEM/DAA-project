#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define INT_SIZE 4
#define LOW 2
#define TESTS 100
int main(int argc,char** argv){
	uint32_t max=atoi(argv[1]);
	int32_t* data=malloc(INT_SIZE*max);
	int32_t* data_slice=malloc(INT_SIZE*max);
	for(uint32_t numbers=LOW;numbers<max;numbers++){
		memcpy(data,data_slice,INT_SIZE*numbers);
		sort(data_slice,numbers);//TODO: macro loop
	}
	return 0;
}
