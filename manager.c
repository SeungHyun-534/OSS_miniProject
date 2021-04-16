#include  "manager.h"
#include <stdio.h>
void showFruits(Fruit* f[],int count){
	printf("=================================\n");
	for(int i=0;i<count;i++){
		if(f[i] == NULL) continue;
		printf("%2d. ",i+1);
		readFruit(f[i]);
	}
}
int selectDataNo(Fruit *f[],int count){
	showFruits(f,count);
	int no;
	printf("번호는?");
	scanf("%d",&no);
	return no;
}
