#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//I chose a buffer size of 318 because that is the total amount of bytes of the headers.
#define BUFFER_SIZE 318

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
            //It checks first if the pointer (tok) isn't nullptr (pointing to nothing), 
            //then if the pointer isn't nullptr, it checks if it points to memory where the value (*tok) isn't '\0'.
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        //my assumption is that this is checking if num is an actual number.  But why wait until after?
        if (!--num)
            return tok;
    }
    //why return NULL is what we want is an actual char?
    return NULL;
}