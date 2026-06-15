#ifndef BIBLIO_LC_H
#define BIBLIO_LC_H
#define _POSIX_C_SOURCE 200809L
#include <string.h>

typedef struct livre {
    int num;
    char *titre;
    char *auteur;
    struct livre *suiv;
    int exemplaires;
} Livre;

typedef struct {
    Livre *L; 
} Biblio;

// Fonctions à implémenter dans biblioLC.c
Livre* creer_livre(int num, char* titre, char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio* b, int num, char* titre, char* auteur);
void afficher_livre(Livre* l);
void afficher_biblio(Biblio* b);
Livre* recherche_num(Biblio* b, int num);
Livre* recherche_titre(Biblio* b, char* titre);
Biblio* recherche_auteur(Biblio* b, char* auteur);
void supprimer_livre(Biblio* b, int num, char* titre, char* auteur);
void fusion_biblio(Biblio* b1, Biblio* b2);
Biblio* livres_exemplaires(Biblio* b);

#endif
