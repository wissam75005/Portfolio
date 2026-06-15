#include <stdio.h>
#include <stdlib.h>
#include "biblioH.h"

BiblioH* charger_n_entrees(char* nomfic, int n) {
    FILE* fichier = fopen(nomfic, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    BiblioH* b = creer_biblioH(100);  // Taille de la table de hachage
    int num;
    char titre[256];
    char auteur[256];

    for (int i = 0; i < n; i++) {
        if (fscanf(fichier, "%d %s %s", &num, titre, auteur) == 3) {
            inserer(b, num, titre, auteur);
        } else {
            break;
        }
    }

    fclose(fichier);
    return b;
}
