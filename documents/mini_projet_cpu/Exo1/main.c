#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

void menu() {
    printf("\nMenu:\n");
    printf("0 - Quitter\n");
    printf("1 - Afficher la bibliothèque\n");
    printf("2 - Insérer un ouvrage\n");
    printf("3 - Rechercher par numéro\n");
    printf("4 - Rechercher par titre\n");
    printf("5 - Rechercher par auteur\n");
    printf("6 - Supprimer un ouvrage\n");
    printf("7 - Fusionner deux bibliothèques\n");
    printf("8 - Afficher les livres avec plusieurs exemplaires\n");
    printf("Choisissez une option: ");
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <nom_fichier> <nombre_lignes>\n", argv[0]);
        return 1;
    }

    char* nom_fichier = argv[1];
    int n = atoi(argv[2]);
    Biblio* biblio = charger_n_entrees(nom_fichier, n);
    if (biblio == NULL) {
        fprintf(stderr, "Erreur lors du chargement des données.\n");
        return 1;
    }

    int rep;
    do {
        menu();

        // Assurer que l'utilisateur entre un entier valide pour l'option du menu
        if (scanf("%d", &rep) != 1) {
            printf("Entrée invalide. Essayez encore.\n");
            while (getchar() != '\n'); // Vider le buffer d'entrée
            continue; // Re-demander l'option
        }

        getchar(); // pour consommer le '\n' après le scanf

        switch (rep) {
            case 1:
                afficher_biblio(biblio);
                break;
            case 2: {
                int num;
                char titre[256], auteur[256];
                printf("Entrez le numéro (entier), le titre et l'auteur (sans espaces): ");
    
                // Vérification que l'entrée du numéro est un entier
                if (scanf("%d %255s %255s", &num, titre, auteur) != 3) {
                    printf("Entrée invalide. Assurez-vous que le format est : numéro titre auteur.\n");
                    while (getchar() != '\n');  // Vider le buffer d'entrée
                    break;
                }
                inserer_en_tete(biblio, num, titre, auteur);
                printf("Ouvrage ajouté.\n");
                break;
            }
            case 3: {
    int num;
    printf("Entrez le numéro à rechercher: ");
    if (scanf("%d", &num) != 1) {
        printf("Entrée invalide pour le numéro.\n");
        while (getchar() != '\n');  // Vider le buffer
        break;
    }

    printf("Recherche du livre avec numéro %d...\n", num); // Debug

    Livre* livre = recherche_num(biblio, num);
    if (livre) {
        afficher_livre(livre);
    } else {
        printf("Aucun livre trouvé avec ce numéro.\n");
    }
    break;
}


            case 4: {
                char titre[256];
                printf("Entrez le titre à rechercher: ");
                if (scanf("%255s", titre) != 1) {
                    printf("Entrée invalide pour le titre.\n");
                    while (getchar() != '\n');  // Vider le buffer
                    break;
                }
                Livre* livre = recherche_titre(biblio, titre);
                if (livre) {
                    afficher_livre(livre);
                } else {
                    printf("Aucun livre trouvé avec ce titre.\n");
                }
                break;
            }
            case 5: {
                char auteur[256];
                printf("Entrez l'auteur à rechercher: ");
                if (scanf("%255s", auteur) != 1) {
                    printf("Entrée invalide pour l'auteur.\n");
                    while (getchar() != '\n');  // Vider le buffer
                    break;
                }
                Biblio* result = recherche_auteur(biblio, auteur);
                afficher_biblio(result);
                break;
            }
            case 6: {
                int num;
                char titre[256], auteur[256];
                printf("Entrez le numéro, le titre et l'auteur du livre à supprimer: ");
                if (scanf("%d %255s %255s", &num, titre, auteur) != 3) {
                    printf("Entrée invalide pour la suppression du livre.\n");
                    while (getchar() != '\n');  // Vider le buffer
                    break;
                }
                supprimer_livre(biblio, num, titre, auteur);
                printf("Livre supprimé si existant.\n");
                break;
            }
            case 7: {
                char nom_fichier2[256];
                printf("Entrez le nom du fichier à fusionner: ");
                if (scanf("%255s", nom_fichier2) != 1) {
                    printf("Entrée invalide.\n");
                    break;
                }
                Biblio* biblio2 = charger_n_entrees(nom_fichier2, n);
                if (biblio2 == NULL) {
                    printf("Erreur lors du chargement du fichier à fusionner.\n");
                    break;
                }
                fusion_biblio(biblio, biblio2); // Implémentez fusionner_biblios pour combiner les deux bibliothèques
                printf("Bibliothèques fusionnées.\n");
                liberer_biblio(biblio2);
                break;
            }
            case 8:
                printf("Afficher les livres avec plusieurs exemplaires...\n");
    
                // Créez une liste ou une table de hachage pour suivre les doublons
                Livre* actuel = biblio->L;

                int trouve = 0;  // Flag pour vérifier si des doublons existent
    
                // Parcourez la bibliothèque pour afficher les livres avec plusieurs exemplaires
                while (actuel != NULL) {
                    if (actuel->exemplaires > 1) {  // Si un livre a plus d'un exemplaire
                        printf("Numéro: %d, Titre: %s, Auteur: %s, Exemplaires: %d\n", 
                            actuel->num, actuel->titre, actuel->auteur, actuel->exemplaires);
                        trouve = 1;
                    }
                    actuel = actuel->suiv;
                }

                // Si aucun livre avec plusieurs exemplaires n'est trouvé
                if (!trouve) {
                    printf("Aucun livre avec plusieurs exemplaires trouvé.\n");
                }
                break;


            case 0:
                printf("Merci et au revoir.\n");
                break;
            default:
                printf("Option invalide.\n");
        }
    } while (rep != 0);

    liberer_biblio(biblio);
    return 0;
}
