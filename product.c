#include "product.h"
#include <stdio.h>
#include <stdlib.h>
int addFruit(Fruit* f){
	printf("과일 이름은 ?");
	scanf("%s",f->name);
	printf("중량은 ?");
	scanf("%d",&f->weight);
	printf("가격은 ?");
	scanf("%d",&f->price);
	printf("별점(1~5)은 ?");
	scanf("%d",&f->stars);
	printf("별점 수는 ?");
	scanf("%d",&f->starsCount);
	
	return 1;
}	

void readFruit(Fruit *f){
	printf("%s  %d  %d  %d  %d\n",f->name,f->weight,f->price,f->stars,f->starsCount);
}

void editFruit(Fruit* f){
	printf("과일 이름은 ?");
	scanf("%s",f->name);
	printf("중량은 ?");
	scanf("%d",&f->weight);
	printf("가격은 ?");
	scanf("%d",&f->price);
	printf("별점(1~5)은 ?");
	scanf("%d",&f->stars);
	printf("별점 수는 ?");
	scanf("%d",&f->starsCount);
	
}

int deleteFruit(Fruit* f){
	free(f);
	f = NULL;
	return 1;
}	

int selectMenu(){
	int menu;
    	printf("\nproduct manger\n");
    	printf("1. 조회\n");
    	printf("2. 추가\n");
    	printf("3. 수정\n");
    	printf("4. 삭제\n");
    	printf("0. 종료\n\n");
    	printf("=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
    	return menu;
}

