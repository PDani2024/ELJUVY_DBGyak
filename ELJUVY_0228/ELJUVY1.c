#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toUppercase(char *str);

int main(){
    char filename[20];
    char name[30];
    char neptun[7];
    char end_input[10];
    FILE *file;

    // Adatok be //

    //Fájlnév bekérése
    printf("Adja meg a fajl nevet: ");
    fgets(filename, 10, stdin);
    filename[strcspn(filename, "\n")] = 0;
    strcat(filename,".txt");
    //Név bekérése
    printf("\nAdja meg a hallgato nevet: ");
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = 0;
    //Neptun-kód bekérése
    printf("Adja meg a Neptun-kodot: ");
    fgets(neptun, 7, stdin);
    neptun[strcspn(neptun, "\n")] = 0;
    //Lezáró karakter bekérése
    printf("A bevitel befejezesehez irjon '#'-t es nyomjon Entert: ");
    do {
        fgets(end_input, 10, stdin);
        end_input[strcspn(end_input, "\n")] = 0;
    } while (strcmp(end_input, "#") != 0);

    // Adatok ki //

    //Fájl megnyitása írásra
    file = fopen(filename, "w");
    if (file == NULL) 
    {
        perror("Hiba a fajl megnyitasakor!");
        return 1;
    }
    //Adatok fájlba írása
    fprintf(file, "%s / %s\n", name, neptun);
    fclose(file);
    //Fájl megnyitása olvasásra
    file = fopen(filename, "r");
    if (file == NULL) 
    {
        perror("Hiba a fajl megnyitasakor");
        return 1;

    }
    
    //Fájl tartalmának kiírása
    printf("\nA fajl tartalma nagybetus formaban:\n");
    char sor[30];
    while (fgets(sor, 30, file)) 
    {
        toUppercase(sor);
        printf("%s", sor);
    }

    fclose(file);
    system("pause");
    return 0;
}

//Nagybetű függvény
void toUppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}