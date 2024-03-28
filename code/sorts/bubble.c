#include<stdint.h>
#include<stdbool.h>
void sort(int32_t arr[],uint32_t len){
	bool sorted=false;
	int32_t t;
	do{
		sorted=true;
		for(uint32_t i=1;i<len;i++){
			if(arr[i]<(t=arr[i-1])){
				sorted=false;
				arr[i-1]=arr[i];
				arr[i]=t;
			}
		}
	}while(!sorted);
}
