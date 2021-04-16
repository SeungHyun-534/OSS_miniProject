#include "manager.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	int count = 0,index=0,menu;
	Fruit * fp[20];
	count = loadData(fp);
	index = count;

	while(1){
#ifdef DEBUG
		printf("index , count : %d, %d",index,count);
#endif
        	menu = selectMenu();
        	if(menu == 0) break;
        	if(menu == 1 || menu == 3 || menu ==4)
            	if(count == 0) continue;
        	if(menu == 1) showFruits(fp,count);
        	else if(menu == 2) {
			fp[index] = (Fruit*)malloc(sizeof(Fruit)); 
            		count += addFruit(fp[index++]);
        	}
        	else if(menu == 3){
			int no = selectDataNo(fp,index);
			if(no == 0) continue;
			editFruit(fp[no-1]);
		}
        	else if(menu == 4) {
			int no = selectDataNo(fp,index);
			if(no == 0) continue;
            		deleteFruit(fp[no-1]);
            		count--;
        	}
		else if(menu == 5) {
		       saveData(fp,index);
		}
 		else if(menu == 6){
			selectSearch(fp,index);
		}		
    	}	

    printf("종료됨!\n");

    return 0;
}
