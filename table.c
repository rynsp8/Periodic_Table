#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chemheader.h"

int main()
{

    table *element = buildTable("periodic_table.csv");

    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", prefix[i]);
    }
    // printtable(element);

    // printElement("Hydrogen");

    /*for(int j = 0; j < 118; j++){
        if(strcmp(element[j].element, "Sodium") == 0){
            printf("Sodium was discovered in %d by %s\n", element[j].year, element[j].discoverer);
        }
    }*/

    // Add le Cahtelier's Principle, equilibirum equation

    // free(element);
};
