#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"

Livre* creer_livre(int num, char* titre, char* auteur) {
    Livre* l = (Livre*)malloc(sizeof(Livre));
    if (!l) {
        printf("Erreur d'allocation mémoire\n");
        return NULL;
    }
    l->num = num;
    l->titre = strdup(titre);  // Correct : utilise strdup pour copier le titre
    l->auteur = strdup(auteur);  // Correct : utilise strdup pour copier l'auteur
    l->suiv = NULL;
    return l;
}

void liberer_livre(Livre* l) {
    if (l) {
        free(l->titre);
        free(l->auteur);
        free(l);
    }
}

Biblio* creer_biblio() {
    Biblio* b = (Biblio*)malloc(sizeof(Biblio));
    if (!b) return NULL;
    b->L = NULL;
    return b;
}

void liberer_biblio(Biblio* b) {
    if (b) {
        Livre* courant = b->L;
        while (courant) {
            Livre* temp = courant;
            courant = courant->suiv;
            liberer_livre(temp);
        }
        free(b);
    }
}

void inserer_en_tete(Biblio* b, int num, char* titre, char* auteur) {
    Livre* nouveau = creer_livre(num, titre, auteur);
    if (nouveau) {
        nouveau->suiv = b->L;
        b->L = nouveau;
    }
}

void afficher_livre(Livre* l) {
    if (l) {
        printf("Numéro: %d, Titre: %s, Auteur: %s\n", l->num, l->titre, l->auteur);
    } else {
        printf("Livre non trouvé.\n");
    }
}


void afficher_biblio(Biblio* b) {
    Livre* courant = b->L;
    while (courant) {
        afficher_livre(courant);
        courant = courant->suiv;
    }
}

Livre* recherche_num(Biblio* b, int num) {
    Livre* courant = b->L;
    while (courant) {
        if (courant->num == num) {
            return courant;
        }
        courant = courant->suiv;
    }
    return NULL; // Retourne NULL si le livre n'est pas trouvé
}
Livre* recherche_titre(Biblio* b, char* titre) {
    Livre* courant = b->L;
    while (courant) {
        if (strcmp(courant->titre, titre) == 0) {
            return courant;
        }
        courant = courant->suiv;
    }
    return NULL;
}
Biblio* recherche_auteur(Biblio* b, char* auteur) {
    Biblio* resultat = creer_biblio();
    Livre* courant = b->L;
    while (courant) {
        if (strcmp(courant->auteur, auteur) == 0) {
            inserer_en_tete(resultat, courant->num, courant->titre, courant->auteur);
        }
        courant = courant->suiv;
    }
    return resultat;
}
void supprimer_livre(Biblio* b, int num, char* titre, char* auteur) {
    Livre* courant = b->L;
    Livre* precedent = NULL;

    while (courant) {
        if (courant->num == num && strcmp(courant->titre, titre) == 0 && strcmp(courant->auteur, auteur) == 0) {
            if (precedent) {
                precedent->suiv = courant->suiv;
            } else {
                b->L = courant->suiv;
            }
            liberer_livre(courant);
            printf("Livre supprimé.\n");
            return;
        }
        precedent = courant;
        courant = courant->suiv;
    }
    printf("Livre introuvable.\n");
}
void fusion_biblio(Biblio* b1, Biblio* b2) {
    if (!b1 || !b2) return;

    Livre* courant = b2->L;
    while (courant) {
        inserer_en_tete(b1, courant->num, courant->titre, courant->auteur);
        courant = courant->suiv;
    }
}
Biblio* livres_exemplaires(Biblio* b) {
    Biblio* resultat = creer_biblio();
    Livre* courant = b->L;

    while (courant) {
        Livre* cherche = recherche_titre(resultat, courant->titre);
        if (cherche) {
            inserer_en_tete(resultat, courant->num, courant->titre, courant->auteur);
        }
        courant = courant->suiv;
    }
    return resultat;
}




