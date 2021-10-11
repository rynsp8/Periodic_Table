#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_struct.h"

//I chose a buffer size of 318 because that is the total amount of bytes of the headers.
#define BUFFER_SIZE 318

const char* getfield(char* line, int num);

int main(){

    struct table element[118];
    char buffer[BUFFER_SIZE];
    int row_count = 0;
    int field_count = 0;
    int i = 0;

    FILE* periodic;

    periodic = fopen("periodic_table.csv", "r");

    while(fgets(buffer, BUFFER_SIZE, periodic) != NULL){
        row_count++;

        if(row_count == 1){
            continue;
        }

        printf("row - %d\n", row_count);

        char* tmp = strdup(buffer);
        char* token = strtok_r(tmp, ",", &tmp);

        while(token != NULL){
            field_count++;

            //printf("field - %d\n", field_count);

            if(field_count == 1){
                element[i].atomicNumber = atoi(token);
            }

            if(field_count == 2){
                strcpy(element[i].element, token);
            }

            if(field_count == 3){
                strcpy(element[i].symbol, token);
            }

            if(field_count == 4){
                element[i].atomicMass = atof(token);
            }

            if(field_count == 5){
                element[i].neutrons = atoi(token);
            }
            if(field_count == 6){
                element[i].protons = atoi(token);
            }

            if(field_count == 7){
                element[i].electrons = atoi(token);
            }

            if(field_count == 8){
                element[i].period = atoi(token);
            }

            if(field_count == 9){
                element[i].group = atoi(token);
            }

            if(field_count == 10){
                strcpy(element[i].phase, token);
            }

            if(field_count == 11){
                element[i].radioactive = atoi(token);
            }

            if(field_count == 12){
                element[i].natural = atoi(token);
            }

            if(field_count == 13){
                element[i].metal = atoi(token);
            }

            if(field_count == 14){
                element[i].nonmetal = atoi(token);
            }

            if(field_count == 15){
                element[i].metalloid = atoi(token);
            }

            if(field_count == 16){
                element[i].type = atoi(token);
            }

            if(field_count == 17){
                element[i].atomicRadius = atof(token);
            }

            if(field_count == 18){
                element[i].electronGravity = atof(token);
            }

            if(field_count == 19){
                element[i].firstIonization = atof(token);
            }

            if(field_count == 20){
                element[i].density = atof(token);
            }

            if(field_count == 21){
                element[i].meltingPoint = atof(token);
            }

            if(field_count == 22){
                element[i].boilingPoint = atof(token);
            }

            if(field_count == 23){
                element[i].isotopes = atoi(token);
            }

            if(field_count == 24){
                strcpy(element[i].discoverer, token);
            }

            if(field_count == 25){
                element[i].year = atoi(token);
            }

            if(field_count == 26){
                element[i].specificHeat = atof(token);
            }

            if(field_count == 27){
                element[i].shells = atoi(token);
            }

            if(field_count == 28){
                element[i].valence = atoi(token);
            }

            //printf("%s\n", token);
            token = strtok_r(NULL, ",", &tmp);
        }
        field_count = 0;
        i++;
        free(tmp);
    }

    printf("i - %d\n", i);

    for(int j = 0; j < 118; j++){
        printf("element[%d] - atomicNumber: %d\telement: %s\t\t\tsymbol: %s\tatomicMass: %.4f\n", j, element[j].atomicNumber, element[j].element, element[j].symbol, element[j].atomicMass);
    }

    fclose(periodic);
};

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            //It checks first if the pointer (tok) isn't nullptr (pointing to nothing), 
            //then if the pointer isn't nullptr, it checks if it points to memory where the value (*tok) isn't '\0'.
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        //my assumption is that this is checking if num is an actual number.  But why wait until after?
        if (!--num)
            return tok;
    }
    //why return NULL if what we want is an actual char?
    return NULL;
}