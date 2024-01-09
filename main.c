#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define SCREEN_WIDTH 750
#define SCREEN_HEIGHT 850
#define CELL_SIZE 50
#define NUM_MICE1 8
#define NUM_MICE2 6
#define NUM_MICE3 6
#define NUM_CHOCOLATES 6
#define NUM_FISH 10
#define NUM_TALE 6

typedef struct {
    int x;
    int y;
} Mouse;

typedef struct {
    int x;
    int y;
} Chocolate;

typedef struct {
    int x;
    int y;
} Fish;

typedef struct {
    int x;
    int y;
} Tale;

void shuffle(Mouse array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap array[i] and array[j]
        Mouse temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int containsObjectOrAnimal(int x, int y, Mouse mice1[], Mouse mice2[], Mouse mice3[], Chocolate chocolates[], Fish fishes[], Tale tales[], int numMice1, int numMice2, int numMice3, int numChocolates, int numFishes, int numTales) {
    for (int i = 0; i < numMice1; i++) {
        if (mice1[i].x == x && mice1[i].y == y) {
            return 1;
        }
    }
    for (int i = 0; i < numMice2; i++) {
        if (mice2[i].x == x && mice2[i].y == y) {
            return 1;
        }
    }
    for (int i = 0; i < numMice3; i++) {
        if (mice3[i].x == x && mice3[i].y == y) {
            return 1;
        }
    }
    for (int i = 0; i < numChocolates; i++) {
        if (chocolates[i].x == x && chocolates[i].y == y) {
            return 1;
        }
    }
    for (int i = 0; i < numFishes; i++) {
        if (fishes[i].x == x && fishes[i].y == y) {
            return 1;
        }
    }
    for (int i = 0; i < numTales; i++) {
        if (tales[i].x == x && tales[i].y == y) {
            return 1;
        }
    }
    if ((x == 12 && y == 2) || (x == 3 && y == 6) || (x == 2 && y == 11) || (x == 11 && y == 12) || (x == 7 && y == 6) || (x == 8 && y == 7) || (x == 7 && y == 8) || (x == 6 && y == 7)) {
        return 1;
    }

    if (x == 7 && y == 7) {
        return 1;
    }
    return 0;
}

void drawMice(ALLEGRO_BITMAP *mouseImage, Mouse mice[], int numMice) {
    for (int i = 0; i < numMice; i++) {
        int mouseX = mice[i].x * CELL_SIZE;
        int mouseY = mice[i].y * CELL_SIZE;
        al_draw_bitmap(mouseImage, mouseX, mouseY, 0);
    }
}

void drawChocolates(ALLEGRO_BITMAP *chocolateImage, Chocolate chocolates[], int numChocolates) {
    for (int i = 0; i < numChocolates; i++) {
        int chocolateX = (chocolates[i].x * CELL_SIZE)-10;
        int chocolateY = chocolates[i].y * CELL_SIZE;
        al_draw_bitmap(chocolateImage, chocolateX, chocolateY, 0);
    }
}

void drawTales(ALLEGRO_BITMAP *taleImage, Tale Tales[], int numTales) {
    for (int i = 0; i < numTales; i++) {
        int taleX = (Tales[i].x * CELL_SIZE)-20;
        int taleY = (Tales[i].y * CELL_SIZE)-10;
        al_draw_bitmap(taleImage, taleX, taleY, 0);
    }
}

void drawFishs(ALLEGRO_BITMAP *fishImage, Fish fishes[], int numFishes) {
    for (int i = 0; i < numFishes; i++) {
        int fishX = (fishes[i].x * CELL_SIZE)-20;
        int fishY = (fishes[i].y * CELL_SIZE)-15;
        al_draw_bitmap(fishImage, fishX, fishY, 0);
    }
}

int main() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *houseImage;
    ALLEGRO_BITMAP *mouse1Image;
    ALLEGRO_BITMAP *mouse2Image;
    ALLEGRO_BITMAP *mouse3Image;
    ALLEGRO_BITMAP *chocolateImage;
    ALLEGRO_BITMAP *taleImage;
    ALLEGRO_BITMAP *fishImage;
    ALLEGRO_BITMAP *cat1Image;
    ALLEGRO_BITMAP *cat2Image;
    ALLEGRO_BITMAP *cat3Image;
    ALLEGRO_BITMAP *cat4Image;
    ALLEGRO_BITMAP *dog1Image;
    ALLEGRO_BITMAP *dog2Image;
    ALLEGRO_BITMAP *dog3Image;
    ALLEGRO_BITMAP *dog4Image;

    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

    houseImage = al_load_bitmap("./images/home.png");
    mouse1Image = al_load_bitmap("./images/mouse1.png");
    mouse2Image = al_load_bitmap("./images/mouse2.png");
    mouse3Image = al_load_bitmap("./images/mouse3.png");
    cat1Image = al_load_bitmap("./images/cat1.png");
    cat2Image = al_load_bitmap("./images/cat2.png");
    cat3Image = al_load_bitmap("./images/cat3.png");
    cat4Image = al_load_bitmap("./images/cat4.png");
    dog1Image = al_load_bitmap("./images/dog1.png");
    dog2Image = al_load_bitmap("./images/dog2.png");
    dog3Image = al_load_bitmap("./images/dog3.png");
    dog4Image = al_load_bitmap("./images/dog4.png");
    chocolateImage = al_load_bitmap("./images/shokol.png");
    taleImage = al_load_bitmap("./images/tale.png");
    fishImage = al_load_bitmap("./images/fish.png");

    al_clear_to_color(al_map_rgb(255, 200, 200));
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            int x = i * CELL_SIZE;
            int y = j * CELL_SIZE;
            al_draw_filled_rectangle(x, y, x + CELL_SIZE, y + CELL_SIZE, al_map_rgb(255, 255, 255));
            al_draw_rectangle(x, y, x + CELL_SIZE, y + CELL_SIZE, al_map_rgb(0, 0, 0), 2);
        }
    }
    int centerX = ((SCREEN_WIDTH - al_get_bitmap_width(houseImage)) / 2) - 5;
    int centerY = ((SCREEN_HEIGHT - al_get_bitmap_height(houseImage)) / 2) - 60;
    al_draw_bitmap(houseImage, centerX, centerY, 0);

    srand(time(NULL));

    Mouse mice1[NUM_MICE1];
    Mouse mice2[NUM_MICE2];
    Mouse mice3[NUM_MICE3];
    Chocolate chocolates[NUM_CHOCOLATES];
    Fish fishes[NUM_FISH];
    Tale tales[NUM_TALE];

    for (int i = 0; i < NUM_MICE1; i++) {
        mice1[i].x = -1;
        mice1[i].y = -1;
    }
    for (int i = 0; i < NUM_MICE2; i++) {
        mice2[i].x = -1;
        mice2[i].y = -1;
    }
    for (int i = 0; i < NUM_MICE3; i++) {
        mice3[i].x = -1;
        mice3[i].y = -1;
    }

for (int i = 0; i < NUM_MICE1; i++) {
    int x, y;

    do {
        x = rand() % 15;
        y = rand() % 15;
    } while ((x == 7 && y == 7) || containsObjectOrAnimal(x, y, mice1,mice2,mice3, chocolates, fishes, tales, NUM_MICE1,NUM_MICE2,NUM_MICE3, NUM_CHOCOLATES, NUM_FISH, NUM_TALE));

    mice1[i].x = x;
    mice1[i].y = y;
}
for (int i = 0; i < NUM_MICE2; i++) {
    int x, y;

    do {
        x = rand() % 15;
        y = rand() % 15;
    } while ((x == 7 && y == 7) || containsObjectOrAnimal(x, y, mice1,mice2,mice3, chocolates, fishes, tales, NUM_MICE1,NUM_MICE2,NUM_MICE3, NUM_CHOCOLATES, NUM_FISH, NUM_TALE));

    mice2[i].x = x;
    mice2[i].y = y;
}
for (int i = 0; i < NUM_MICE3; i++) {
    int x, y;

    do {
        x = rand() % 15;
        y = rand() % 15;
    } while ((x == 7 && y == 7) || containsObjectOrAnimal(x, y, mice1,mice2,mice3, chocolates, fishes, tales, NUM_MICE1,NUM_MICE2,NUM_MICE3, NUM_CHOCOLATES, NUM_FISH, NUM_TALE));

    mice3[i].x = x;
    mice3[i].y = y;
}
    int cat1X = 7;
    int cat1Y = 6;
    int cat2X = 8;
    int cat2Y = 7;
    int cat3X = 7;
    int cat3Y = 8;
    int cat4X = 6;
    int cat4Y = 7;
    int dog1X = 12;
    int dog1Y = 2;
    int dog2X = 3;
    int dog2Y = 6;
    int dog3X = 2;
    int dog3Y = 11;
    int dog4X = 11;
    int dog4Y = 12;

    for (int i = 0; i < NUM_CHOCOLATES; i++) {
    int x, y;
    do {
        x = rand() % 15;
        y = rand() % 15;
    } while ((x == 7 && y == 7) || containsObjectOrAnimal(x, y, mice1,mice2,mice3, chocolates, fishes, tales, NUM_MICE1,NUM_MICE2,NUM_MICE3, NUM_CHOCOLATES, NUM_FISH, NUM_TALE));
      chocolates[i].x = x;
      chocolates[i].y = y;
    }
    for (int i = 0; i < NUM_FISH; i++) {
    int x, y;
    do {
        x = rand() % 15;
        y = rand() % 15;
    } while ((x == 7 && y == 7) || containsObjectOrAnimal(x, y, mice1,mice2,mice3, chocolates, fishes, tales, NUM_MICE1,NUM_MICE2,NUM_MICE3, NUM_CHOCOLATES, NUM_FISH, NUM_TALE));
    fishes[i].x = x;
    fishes[i].y = y;
    }
    for (int i = 0; i < NUM_TALE; i++) {
    int x, y;
    do {
        x = rand() % 15;
        y = rand() % 15;
    } while ((x == 7 && y == 7) || containsObjectOrAnimal(x, y, mice1,mice2,mice3, chocolates, fishes, tales, NUM_MICE1,NUM_MICE2,NUM_MICE3, NUM_CHOCOLATES, NUM_FISH, NUM_TALE));
    tales[i].x = x;
    tales[i].y = y;
    }

    shuffle(mice1, NUM_MICE1);
    shuffle(mice2, NUM_MICE2);
    shuffle(mice3, NUM_MICE3);

    drawMice(mouse1Image, mice1, NUM_MICE1);
    drawMice(mouse2Image, mice2, NUM_MICE2);
    drawMice(mouse3Image, mice3, NUM_MICE3);
    drawChocolates(chocolateImage, chocolates, NUM_CHOCOLATES);
    drawFishs(fishImage, fishes, NUM_FISH);
    drawTales(taleImage, tales, NUM_TALE);
    al_draw_bitmap(cat1Image, (cat1X * CELL_SIZE)-25, (cat1Y * CELL_SIZE)-20, 0);
    al_draw_bitmap(cat2Image, (cat2X * CELL_SIZE)-25, (cat2Y * CELL_SIZE)-20, 0);
    al_draw_bitmap(cat3Image, (cat3X * CELL_SIZE)-25, (cat3Y * CELL_SIZE)-20, 0);
    al_draw_bitmap(cat4Image, (cat4X * CELL_SIZE)-25, (cat4Y * CELL_SIZE)-20, 0);
    al_draw_bitmap(dog1Image, (dog1X * CELL_SIZE)-25, (dog1Y * CELL_SIZE)-10, 0);
    al_draw_bitmap(dog2Image, (dog2X * CELL_SIZE)-25, (dog2Y * CELL_SIZE)-10, 0);
    al_draw_bitmap(dog3Image, (dog3X * CELL_SIZE)-25, (dog3Y * CELL_SIZE)-10, 0);
    al_draw_bitmap(dog4Image, (dog4X * CELL_SIZE)-25, (dog4Y * CELL_SIZE)-10, 0);
    al_flip_display();

    al_rest(5);

    al_destroy_bitmap(houseImage);
    al_destroy_bitmap(mouse1Image);
    al_destroy_bitmap(mouse2Image);
    al_destroy_bitmap(mouse3Image);
    al_destroy_display(display);

    return 0;
}
