#include<stdint.h>
void quicksort(int32_t arr[],uint32_t begin,uint32_t len){
	if(begin==len)return;
	uint32_t from_left=begin,from_right;
	int32_t pivot=arr[from_right=len-1],t;
	while(from_left<from_right){
		for(;arr[from_left]<pivot && from_left<from_right;from_left++);
		for(;arr[from_right]>=pivot && from_left<from_right;from_right--);
		t=arr[from_left];
		arr[from_left]=arr[from_right];
		arr[from_right]=t;
	}
	arr[len-1]=arr[from_left];
	arr[from_left]=pivot;
	quicksort(arr,begin,from_right);
	quicksort(arr,from_right+1,len);
}
void sort(int32_t arr[],uint32_t begin,uint32_t len){
	quicksort(arr,0,len);
}
