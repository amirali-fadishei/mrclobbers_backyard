#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randomplace(int num, int value, char array[15][15]) {
    int i, j, k;
    for (k = 0; k < num; k++) {
        do {
            i = rand() % 15;
            j = rand() % 15;
        } while (array[i][j] != 0);
        array[i][j] = value;
    }
}

int main() {
    // متغیرها
    char area[15][15];
    int tale = 13;
    int fish = 14;
    int chocolate = 15;
    int mouse1 = 9;
    int mouse2 = 10;
    int mouse3 = 11;
    int player1 = 1;
    int player2 = 2;
    int player3 = 3;
    int player4 = 4;
    int dog1 = 5;
    int dog2 = 6;
    int dog3 = 7;
    int dog4 = 8;
    char house = 'H';
    srand(time(NULL));
    //نقشه اولیه
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            area[i][j] = 0;
        }
    }
    //مکان های ثابت
    area[7][7] = house;
    area[6][7] = player1;
    area[7][8] = player2;
    area[8][7] = player3;
    area[7][6] = player4;
    area[2][12] = dog1;
    area[6][3] = dog2;
    area[11][2] = dog3;
    area[12][11] = dog4;
    //مکان های متغیر
    randomplace(8, mouse1, area);
    randomplace(6, mouse2, area);
    randomplace(6, mouse3, area);
    randomplace(8, tale, area);
    randomplace(6, chocolate, area);
    randomplace(8, fish, area);
    //چاپ مکان ها
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if(i==7&&j==7){
               printf("%c ", area[i][j]);
            }else printf("%d ", area[i][j]);
        }
        printf("\n");
    }

    //منطق
    return 0;
}
