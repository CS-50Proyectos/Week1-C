#include <stdio.h>
#include <cs50.h>

void pyramHeights(int counter);

int main (void){

    int pyramHeight = 0;

    while(pyramHeight <= 0 || pyramHeight >= 9){
        pyramHeight = get_int("Height:");
    }

    int counter = 0;

    while(pyramHeight != counter){
        counter++;

        for(int i = (pyramHeight - counter); i > 0; i--){
            printf(" ");
        }

        pyramHeights(counter);

        printf("  ");

        pyramHeights(counter);

        printf("\n");
    }
}


void pyramHeights(int counter){
        for(int i = 0; i < counter; i++){
            printf("#");
        }
    }