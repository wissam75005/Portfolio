#ifndef BIBLIOH_H
#define BIBLIOH_H

typedef struct livreH {
    int clef;
    int num;
    char *titre;
    char *auteur;
    struct livreH *suivant;
} LivreH;

typedef struct table {
    int nE;
    int m;
    LivreH **T;
} BiblioH;




LivreH* creer_livreH(int num, char* titre, char* auteur);
void liberer_livreH(LivreH* l);
BiblioH* creer_biblioH(int m);
void liberer_biblioH(BiblioH* b);
int fonctionClef(char* auteur);
int fonctionHachage(int cle, int m);
void inserer(BiblioH* b, int num, char* titre, char* auteur);
void afficher_biblioH(BiblioH* b);  // Ajoute cette ligne pour éviter l'erreur
#endif
