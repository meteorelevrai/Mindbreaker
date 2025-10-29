#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "time.h"

void writechar(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i++], 1);
    }
}

int main(void)
{
    srand((unsigned) time(NULL));
    int number = rand() % 100 + 1;
    int verif = 0;
    int ess = 0;
    int reponse;
    char restart[10];
    int verif_restart = 0;

    writechar("Je pense a un nombre entre 1 et 100...\n");
    writechar("Essaie de le deviner !\n\n");
    while (verif == 0) {
        scanf("%d", &reponse);
        ess++;
        if (reponse == number) {
            verif_restart = 0;
            reponse = -1;
            printf("\nBravo ! Tu as trouve le nombre en %d essais !\n\n", ess);
            while (verif_restart == 0)
            {
                writechar("Voulez vous rejouer ? ( oui / non ) : \n");
                scanf("%s", restart);
                if (strcmp(restart, "oui") == 0 || strcmp(restart, "Oui") == 0)
                {
                    writechar("\nJe pense a un nombre entre 1 et 100...\n");
                    writechar("Essaie de le deviner !\n\n");
                    ess = 0;
                    verif = 0;
                    verif_restart = 1;
                }
                if (strcmp(restart, "non") == 0 || strcmp(restart, "Non") == 0)
                {
                    verif = 1;
                    verif_restart = 1;
                }
                if (strcmp(restart, "Oui") != 0 && strcmp(restart, "oui") != 0
                    && strcmp(restart, "Non") != 0 && strcmp(restart, "non") != 0) 
                {
                    verif_restart = 0;
                }
            }
        }
        if (reponse > 100)
        {
            writechar("\nLa reponse doit etre entre 0 et 100 ! \n\n");
        }
        if (reponse > number && reponse >= 0 && reponse <= 100) 
        {
            writechar("\nC'est moins !\n\n");
        }
        if (reponse < number && reponse >= 0 && reponse <= 100) 
        {
            writechar("\nC'est plus !\n\n");
        }
    }

    return (0);
}
