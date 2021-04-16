#ifndef PRODUCT
#define PRODUCT
typedef struct{

    char name[20];
    int weight;
    int price;
    int stars;
    int starsCount;

} Fruit;

int addFruit(Fruit* f); // 하나의 제품 추가 함수
void readFruit(Fruit* f); // 하나의 제품 정보 출력 함수
void editFruit(Fruit* f); // 하나의 제품 정보 수정 함수
int deleteFruit(Fruit*f); //하나의 제품 정보 삭제 함수

void searchName(Fruit* f[],int count); // 이름으로 검색하는 함수
void searchWeight(Fruit* f[],int count); // 중량으로 검색하는 함수 
void searchStars(Fruit* f[],int count); // 별점으로 검색하는 함수
void searchI(Fruit* f[],int count); // 통합검색 기능 함수

void saveData(Fruit *f[],int count); // File 저장함수
int loadData(Fruit *f[]); // File에서 정보를 받아오는 함수

int selectMenu(); // 사용자 메뉴 선택 함수 
#endif
