#include <stdio.h>   // Pour printf, scanf
#include <stdlib.h>  // Pour atoi
#include "biblioH.h"
#include "entreeSortieH.h" // Pour charger_n_entrees

// Déclaration de la fonction menu
void menu() {
    printf("0 - Sortie du programme\n");
    printf("1 - Affichage de la bibliothèque\n");
    printf("2 - Inserer un ouvrage\n");
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <fichier> <nombre de lignes>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[2]);
    BiblioH* b = charger_n_entrees(argv[1], n);

    int rep;
    do {
        menu();  // Appel correct de la fonction
        printf("Choisissez une option : ");
        scanf("%d", &rep);

        switch (rep) {
            case 1:
                afficher_biblioH(b);
                break;
            case 2: {
                int num;
                char titre[256], auteur[256];
                printf("Numéro du livre: ");
                scanf("%d", &num);
                printf("Titre du livre: ");
                scanf(" %[^\n]", titre);  // Lire une ligne entière avec espaces
                printf("Auteur du livre: ");
                scanf(" %[^\n]", auteur);
                inserer(b, num, titre, auteur);
                printf("Livre inséré avec succès !\n");
                break;
            }
            case 0:
                printf("Merci et au revoir.\n");
                break;
            default:
                printf("Option non reconnue.\n");
                break;
        }
    } while (rep != 0);

    liberer_biblioH(b);
    return 0;
}
