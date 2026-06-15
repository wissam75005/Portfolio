#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblioH.h"

// Fonction pour créer un livre
LivreH* creer_livreH(int num, char* titre, char* auteur) {
    LivreH* livre = (LivreH*)malloc(sizeof(LivreH));
    if (!livre) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return NULL;
    }
    livre->num = num;
    livre->titre = strdup(titre);
    livre->auteur = strdup(auteur);
    livre->clef = fonctionClef(auteur);
    livre->suivant = NULL;
    return livre;
}

// Fonction pour libérer un livre
void liberer_livreH(LivreH* l) {
    if (l) {
        free(l->titre);
        free(l->auteur);
        free(l);
    }
}

// Fonction pour créer une bibliothèque
BiblioH* creer_biblioH(int m) {
    BiblioH* b = (BiblioH*)malloc(sizeof(BiblioH));
    if (!b) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return NULL;
    }
    b->nE = 0;
    b->m = m;
    b->T = (LivreH**)calloc(m, sizeof(LivreH*));
    if (!b->T) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        free(b);
        return NULL;
    }
    return b;
}

// Fonction pour libérer une bibliothèque
void liberer_biblioH(BiblioH* b) {
    if (b) {
        for (int i = 0; i < b->m; i++) {
            LivreH* courant = b->T[i];
            while (courant) {
                LivreH* temp = courant;
                courant = courant->suivant;
                liberer_livreH(temp);
            }
        }
        free(b->T);
        free(b);
    }
}

// Fonction pour calculer la clé à partir du nom de l'auteur
int fonctionClef(char* auteur) {
    int clef = 0;
    for (int i = 0; auteur[i] != '\0'; i++) {
        clef += auteur[i];
    }
    return clef;
}

// Fonction de hachage (améliorée)
int fonctionHachage(int cle, int m) {
    double A = (sqrt(5) - 1) / 2;
    return (int)(m * (cle * A - floor(cle * A)));
}

// Fonction pour insérer un livre
void inserer(BiblioH* b, int num, char* titre, char* auteur) {
    if (!b) return;
    LivreH* livre = creer_livreH(num, titre, auteur);
    if (!livre) return;
    
    int index = fonctionHachage(livre->clef, b->m);
    livre->suivant = b->T[index];
    b->T[index] = livre;
    b->nE++;
}


// Fonction pour afficher la bibliothèque
void afficher_biblioH(BiblioH* b) {
    if (!b) {
        printf("Bibliothèque vide ou inexistante.\n");
        return;
    }
    
    for (int i = 0; i < b->m; i++) {
        LivreH* courant = b->T[i];
        if (courant) {
            printf("Index %d:\n", i);
            while (courant) {
                printf("  [%d] Titre: %s, Auteur: %s (Clé: %d)\n", 
                       courant->num, courant->titre, courant->auteur, courant->clef);
                courant = courant->suivant;
            }
        }
    }
}
