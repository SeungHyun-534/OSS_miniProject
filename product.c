#include "product.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	printf("삭제됨\n");
	return 1;
}	

int selectMenu(){
	int menu;
    	printf("\nproduct manger\n");
    	printf("1. 조회\n");
    	printf("2. 추가\n");
    	printf("3. 수정\n");
    	printf("4. 삭제\n");
	printf("5. 저장\n");
	printf("6. 검색\n");
    	printf("0. 종료\n\n");
    	printf("=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
    	return menu;
}

int loadData(Fruit *f[]){
	int i = 0;
	FILE *fp;
	fp = fopen("product.txt","rt");

	if(fp == NULL){
		printf("=> 파일 없음\n");
		return 0;
	}

	for(;i<20;i++){
		f[i] = (Fruit*)malloc(sizeof(Fruit));
		fscanf(fp,"%s",f[i]->name);
		if(feof(fp)) break;
		fscanf(fp,"%d",&f[i]->weight);
		fscanf(fp,"%d",&f[i]->price);
		fscanf(fp,"%d",&f[i]->stars);
		fscanf(fp,"%d",&f[i]->starsCount);
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
		fprintf(fp,"%s %d %d %d %d\n",f[i]->name,f[i]->weight,f[i]->price,f[i]->stars,f[i]->starsCount);
	}	
		fclose(fp);
		printf("=> 저장됨!");
}

void searchName(Fruit* f[],int count){
	
	int scnt =0;
	char search[20];

	printf("검색할 이름?");
	scanf("%s", search);
	printf("==================================\n");
	for(int i=0;i <count;i++){
		if(f[i]==NULL) continue;
		if(strstr(f[i]->name,search)){
			printf("%2d. ",i+1);
			readFruit(f[i]);
		scnt++;
		}
	}
	if(scnt == 0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}

void searchWeight(Fruit* f[],int count){
	
	int scnt =0;
	int search;

	printf("검색할 중량?");
	scanf("%d",&search);
	printf("==================================\n");
	for(int i=0;i <count;i++){
		if(f[i]==NULL) continue;
		if(search == f[i]->weight){
			printf("%2d. ",i+1);
			readFruit(f[i]);
		scnt++;
		}
	}
	if(scnt == 0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}



void searchStars(Fruit* f[],int count){
	
	int scnt =0;
	int search;

	printf("검색할 별점?");
	scanf("%d",&search);
	printf("==================================\n");
	for(int i=0;i <count;i++){
		if(f[i]==NULL) continue;
		if(search == f[i]->stars){
			printf("%2d. ",i+1);
			readFruit(f[i]);
		scnt++;
		}
	}
	if(scnt == 0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}

void searchI(Fruit* f[],int count){
	
	int scnt =0;
	char name[20];
	int weight;
	int price;

	printf("검색할 이름?");
	scanf("%s",name);
	printf("검색할 중량?");
	scanf("%d",&weight);
	printf("검색할 가격?");
	scanf("%d",&price);
	printf("==================================\n");
	for(int i=0;i <count;i++){
		if(f[i]==NULL) continue;
		if(strstr(f[i]->name,name)&& weight == f[i]->weight && price == f[i]->price){
			printf("%2d. ",i+1);
			readFruit(f[i]);
		scnt++;
		}
	}
	if(scnt == 0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}

void selectSearch(Fruit*f[],int count){
	printf("어떤 검색을 원하세요?\n");
	printf("1. 이름으로 검색\n");
	printf("2. 중량으로 검색\n");
	printf("3. 별점으로 검색\n");
	printf("4. 통합검색\n");

	int whichSearch;
	scanf("%d",&whichSearch);

	switch(whichSearch){
		case 1: searchName(f,count);
			break;
		case 2: searchWeight(f,count);
			break;
		case 3: searchStars(f,count);
			break;
		case 4: searchI(f,count);
			break;
		default: printf("잘못된 입력입니다!!!\n");
	}
}
		


	
