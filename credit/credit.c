#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool ccValidation(int ccLength, char ccFormat[]);
int main(void){
    
    bool invalid = true;
    bool validated = false;

    while(invalid){
        // Guardo el número que introduce el usuario
        long creditCard = get_long("Number: ");
        
        // Reservo espacio para hasta 16 caracteres de una tarjeta de credito
        char creditCardDigits[17];

        // Escribe en memoria un caracter por posición, devuelve un int con el número de caracteres escritos 
        sprintf(creditCardDigits, "%ld" ,creditCard);

        // Devuelve el número de posiciones escritas del char[]
        int creditCardLength = strlen(creditCardDigits);

        // Invalida
        if(creditCardLength != 16 && creditCardLength != 15 && creditCardLength != 13){
            printf("INVALID\n");

        // American Express    
        }else if(creditCardLength == 15){
            // American Express que empieza por 34 o 37 (Primera validación correcta)
            if(creditCardDigits[0] == '3' && (creditCardDigits[1] == '4' || creditCardDigits[1] == '7')){
                
                //Algoritmo de Luhn
                validated = ccValidation(creditCardLength, creditCardDigits);

                if(validated){
                    printf("American Express\n");
                    invalid = false;
                    
                }else{
                    printf("INVALID\n");
                }

            }else{
                printf("INVALID\n");
            }
        // Visa de 13 dígitos
        }else if(creditCardLength == 13){
            // Visa que empieza por 4(Primera validación correcta)
            if(creditCardDigits[0] == '4'){

                //Algoritmo de Luhn
                validated = ccValidation(creditCardLength, creditCardDigits);

                if(validated){
                    printf("Visa\n");
                    invalid = false;
                }else{
                    printf("INVALID\n");
                }

            }else{
                printf("INVALID\n");
            }
        // Visa de 16 dígitos 
        }else if(creditCardLength == 16 && creditCardDigits[0] == '4'){
            // Visa que empieza por 4(Primera validación correcta)
            if(creditCardDigits[0] == '4'){

                //Algoritmo de Luhn
                validated = ccValidation(creditCardLength, creditCardDigits);

                if(validated){
                    printf("Visa\n");
                    invalid = false;
                }else{
                    printf("INVALID\n");
                }

            }else{
                printf("INVALID\n");
            }
        //Mastercard
        }else{
            if(creditCardDigits[0] == '5' && (creditCardDigits[1] == '1' || creditCardDigits[1] == '2'||
            creditCardDigits[1] == '3'|| creditCardDigits[1] == '4'|| creditCardDigits[1] == '5')){

                validated = ccValidation(creditCardLength, creditCardDigits);

                if(validated){
                    printf("Mastercard\n");
                    invalid = false;
                }else{
                    printf("INVALID\n");
                }

            }else{
                printf("INVALID\n");
            }
        }

    }

}

// Metodo que aplica el algoritmo de Luhn para comprobar la validez de una tarjeta de credito 
bool ccValidation(int creditCardLength, char creditCardDigits[]){
    int impairDigits[9];
    int sum = 0;
    int counter = 0;
    bool valid = false;

    if(creditCardLength == 13 || creditCardLength == 15){
        for(int i = (creditCardLength - 2); i >= 1; i-=2){
            impairDigits[counter] = 2 * (creditCardDigits[i] - '0');
            sum += (creditCardDigits[(i + 1)] - '0');
            counter++;
        }
        sum += creditCardDigits[0] - '0';

        for(int i = 0; i < counter; i++){
            if(impairDigits[i] >= 10){
                sum += (impairDigits[i] % 10) + (impairDigits[i] / 10);
            }else{
                sum += (impairDigits[i]);
            }
        }

        if(sum % 10 == 0){
            valid = true;
        }else{
            valid = false;
        }

    }else{
        for(int i = (creditCardLength - 2); i >= 0; i -= 2){
            impairDigits[counter] = 2 * (creditCardDigits[i] - '0');
            sum += (creditCardDigits[(i + 1)] - '0');
            counter++;
        }

        for(int i = 0; i < counter; i++){
            if(impairDigits[i] >= 10){
                sum += (impairDigits[i] % 10) + (impairDigits[i] / 10);
            }else{
                sum += (impairDigits[i]);
            }
        }

        if(sum % 10 == 0){
            valid = true;
        }else{
            valid = false;
        }
    }
    
    return valid;
}