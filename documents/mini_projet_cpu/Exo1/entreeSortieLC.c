#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"

Biblio* charger_n_entrees(char* nomfic, int n) {
    FILE* f = fopen(nomfic, "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return NULL;
    }

    Biblio* b = creer_biblio();
    char ligne[256];
    int num, count = 0;
    char titre[256], auteur[256];

    while (fgets(ligne, sizeof(ligne), f) && count < n) {
        if (sscanf(ligne, "%d %s %s", &num, titre, auteur) == 3) {
            inserer_en_tete(b, num, titre, auteur);
            count++;
        }
    }

    fclose(f);
    return b;
}

void enregistrer_biblio(Biblio* b, char* nomfic) {
    FILE* f = fopen(nomfic, "w");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    Livre* courant = b->L;
    while (courant) {
        fprintf(f, "%d %s %s\n", courant->num, courant->titre, courant->auteur);
        courant = courant->suiv;
    }

    fclose(f);
}