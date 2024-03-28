#include<stdint.h>
void selectionsort(int32_t arr[],uint32_t len){
	int32_t min;uint32_t min_index;
	for(uint32_t i=0;i<len;i++){
		min=arr[i];
		min_index=i;
		for(uint32_t j=i;j<len;j++)
			if(arr[j]<min){
				min_index=j;
				min=arr[j];
			}
		arr[min_index]=arr[i];
		arr[i]=min;
	}
}
