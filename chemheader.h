//I chose a buffer size of 318 because that is the total amount of bytes of the headers
#define BUFFER_SIZE 318

typedef struct table{
    int atomicNumber;
    char element[14];
    char symbol[13];
    float atomicMass;
    int neutrons;
    int protons;
    int electrons;
    int period;
    int group;
    char phase[11];
    int radioactive;
    int natural;
    int metal;
    int nonMetal;
    int metalloid;
    char type[21];
    float atomicRadius;
    float electronNegativity;
    float firstIonization;
    float density;
    float meltingPoint;
    float boilingPoint;
    int isotopes;
    char discoverer[31];
    int year;
    float specificHeat;
    int shells;
    int valence;
} table;

table *buildTable(char* file){

    table *element = malloc(118 * sizeof(table));
    char buffer[BUFFER_SIZE];
    int row_count = 0;
    int field_count = 0;
    int i = 0;

    FILE* periodic;

    periodic = fopen(file, "r");

    while(fgets(buffer, BUFFER_SIZE, periodic) != NULL){
        row_count++;

        if(row_count == 1){
            continue;
        };

        char* tmp = strdup(buffer);
        char* token = strtok_r(tmp, ",", &tmp);

        while(token != NULL){
            field_count++;

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
                element[i].nonMetal = atoi(token);
            }

            if(field_count == 15){
                element[i].metalloid = atoi(token);
            }

            if(field_count == 16){
                strcpy(element[i].type, token);
            }

            if(field_count == 17){
                element[i].atomicRadius = atof(token);
            }

            if(field_count == 18){
                element[i].electronNegativity = atof(token);
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
    }

    return element;
    fclose(periodic);
};