#include<stdint.h>
#define SWAP(i1,i2) t=arr[i1];arr[i1]=arr[i2];arr[i2]=t;
void build_heap(int32_t arr[],uint32_t len){
	uint32_t current,swap_index,right_child,left_child;
	int32_t t;
	for(int32_t i=(len-1)/2;i>=0;i--){
		current=i;
		do{
			left_child=2*current+1;
			right_child=2*current+2;
			swap_index=(right_child<len && arr[right_child]>arr[left_child])?right_child:left_child;
			if(arr[swap_index]<=arr[current])
				break;
			SWAP(current,swap_index);
			current=swap_index;
		}while(current<=(len-1)/2);
	}
}
void poll(int32_t arr[],uint32_t len){
	uint32_t swap_index=0,left_child,right_child,current=--len;
	int32_t t;
	do{//bubble down
		SWAP(current,swap_index);
		current=swap_index;
		left_child=2*current+1;
		right_child=2*current+2;
		swap_index=(right_child<len && arr[right_child]>arr[left_child])?right_child:left_child;
	}while(swap_index<len && arr[current]<arr[swap_index]);
}
void sort(int32_t arr[],uint32_t len){
	build_heap(arr,len);
	for(uint32_t i=0;i<len;i++)poll(arr,len-i);
}
