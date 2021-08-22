#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//I chose a buffer size of 318 because that is the total amount of bytes of the headers.
#define BUFFER_SIZE 318

//Data structure I may/may not be working with in the future
struct Elements{
    char name[14];
    char symbol[13];
    int atomicNumber;
    float firstIonizationEnergy;
    char electronConfiguration[16];
    signed int oxidationStates;
    float atomicMass;
    float electroNegativity;
    int group;
    int period;
    char state[18];
};

const char* getfield(char* line, int num);

int main(){

    char buffer[BUFFER_SIZE];
    char* record;
    int i;

    FILE* periodic;

    periodic = fopen("periodic_table.csv", "r");

    while(fgets(buffer, BUFFER_SIZE, periodic) != NULL){
        //printf("%s", buffer);

        //record = strtok(buffer, ",");

        //while(record != NULL){
        //    printf("Record: %s\n", record);
        //    record = strtok(NULL, ",");
        //}

        char* tmp = strdup(buffer);
        printf("%s", tmp);
        if(strcmp(getfield(tmp, 1), "3") == 0){
            printf("Lithium\n%s\n", tmp);
            break;
        }
        //else {
        //    printf("Field 3 would be %s\n", getfield(tmp, 3));
        //}
        free(tmp);

    }




    //printf("\n");

    //struct Elements element;

    //strcpy(element.name, "Hydrogen");
    //strcpy(element.symbol, "H");
    //element.atomicNumber = 1;

    //printf("The first element on the periodic table is %s\n", element.name);
    //printf("Its symbol is %s\n", element.symbol);
    //printf("Its Atomic Number is %d\n", element.atomicNumber);

    fclose(periodic);
};

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}