#include <stdio.h>
#include <cs50.h>

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

        for(int i = 0; i < counter; i++){
            printf("#");
        }
        
        printf("\n");
    }

}