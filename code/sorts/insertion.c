#include<stdint.h>
void sort(int32_t arr[],uint32_t len){
	int e;int j;
	for(uint32_t i=1;i<len;i++){
		e=arr[i];
		for(j=i-1;j>=0;j--){
			if(arr[j]<e)
				break;
			arr[j+1]=arr[j];
		}
		arr[j+1]=e;
	}
}
