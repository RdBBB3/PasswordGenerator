#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

char* generatePassword(int size, bool specs)
{
    if (size <= 0) {
        return NULL;
    }
				
    char *result = malloc((size + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
				
		// Définition de tout les caractères utilisables
    const char majuscules[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char minuscules[26] = "abcdefghijklmnopqrstuvwxyz";
    const char specials[12] = "#{}[]&%*$)!(";

		// On rajoute un caractère au hasard selon la taille donnée par l'utilisateur
    for (int i = 0; i < size; i++)
    {
        int random = rand() % (specs ? 3 : 2); // Si specs est True, on choisit au hasard entre une minuscule, une 
																							 // majuscule ou un caractère spécial . 
        if (random == 0)
        {
            result[i] = majuscules[rand() % 26];
        }
        else if (random == 1)
        {
            result[i] = minuscules[rand() % 26];
        }
        else if (random == 2 && specs)
        {
            result[i] = specials[rand() % 12];
        }
    }

    result[size] = '\0';
    return result;
}

int main(void)
{
    srand(time(0));
    int size = 0;
    bool specs = true;
    char answer;

    printf("What size do you want your password to be? \n");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Password size must be greater than zero characters.\n");
        return 1;
    }

    printf("\nDo you want to add random special characters? [y/n]\n");
    scanf(" %c", &answer);// " %c" Espace avant le % car cela "réinitialise" les inputs précédent, l'inverse cause des bugs

		// Si l'utilisateur répond "y" ou "Y" alors les carctères spéciaux sont "true", le contraire si l'utilisateur rentre
		// "n" ou "N" .
		if (answer == 'y' || answer == 'Y')
		{
				specs = true;
		}
		else if (answer == 'n' || answer == 'N'){
				specs = false;
		}
		else {
				printf("Enter y or n");
				return 1;
		}
				
    char* password = generatePassword(size, specs);
    
		if (password != NULL)
    {
        printf("Generated password: %s\n", password);
        free(password);
    }

    return 0;
}

