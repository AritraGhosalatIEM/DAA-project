#include<string.h>
#include<stdint.h>
#define SIZE 4
void sort(int32_t arr[],uint32_t len){
	if(len==1)
		return;
	uint32_t mid=len/2;
	uint32_t rest=len-mid;
	int32_t left[mid],right[rest];
	memcpy(left,arr,mid*SIZE);
	memcpy(right,&arr[mid],rest*SIZE);
	sort(left,mid);sort(right,rest);
	uint32_t i=0,j=0,k=0;
	for(;i<mid && j<rest;k++)
		if(left[i]<right[j])
			arr[k]=left[i++];
		else
			arr[k]=right[j++];
	for(;j<rest;j++)
		arr[k++]=right[j];
	for(;i<mid;i++)
		arr[k++]=left[i];
}
