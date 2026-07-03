#include <stdio.h>
#include <cs50.h>

int main(void){


    int pounds25 = 0;
    int pounds10 = 0;
    int pounds5 = 0;
    int pounds1 = 0;
    int totalCoins = 0;

    int change = 0;
    
    while(change <= 0){
        change = get_int("Change owned: ");
        
    }

    int rest = 0;

    // Knowing wich are the first coins
    if(change >= 25){
        rest = change % 25;
        pounds25 = change / 25; 

    }else if((change >= 10 && change <= 25)){
        rest = change % 10;
        pounds10 = change / 10;

    }else if((change >= 5 && change <= 10)){
        rest = change % 5;
        pounds5 = change / 5;
    }else{
        pounds1 = change;
    }

    // If the rest is greater than 0 we know we need more coins than the 25 pounds or we have less than 5 pounds
    if(rest > 0){
        if(rest >= 10){
            pounds10 = rest / 10;
            rest %= 10;
        }     

        if(rest >= 5){
            pounds5 = rest / 5;
            rest %= 5;
        }

        pounds1 = rest;
    }

    totalCoins = pounds25 + pounds10 + pounds5 + pounds1;

    printf("Number of coins to return:%i\n ",totalCoins);
}