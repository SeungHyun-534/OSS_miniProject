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

int loadData(Fruit *f[],int count){
	int i = 0;
	FILE *fp;
	fp = fopen("product.txt","rt");

	if(fp == NULL){
		printf("=> 파일 없음\n");
		return 0;
	}

	for(;i<count;i++){
		fscanf(fp,"%s",f[i]->name);
		if(feof(fp)) break;
		fscanf(fp,"%d",f[i]->weight);
		fscanf(fp,"%d",f[i]->price);
		fscanf(fp,"%d",f[i]->stars);
		fscanf(fp,"%d",f[i]->starsCount);
	}
	fclose(fp);
	printf("=> 로딩 성공\n");
	return i;
}

void saveData(Fruit *f[],int count){
	FILE *fp;
	fp = fopen("product.txt","wt");

	for(int i=0;i<count;i++){
		if(f[i] == NULL) continue;
		fprintf(fp,"%s %d %d %d %d\n",f[i]->name,f[i]->weight,f[i]->price,f[i]-stars,f[i]->starsCount);
	}	
		fclose(fp);
		printf("=> 저장됨!");
}
