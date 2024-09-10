#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nb = 0;
char T[100][30];
char A[100][20];
float P[100];
int Q[100];

void AfficherLivre() {
    for (int i = 0; i < nb; i++)
        printf("livre %d: titre: %s, auteur: %s, prix: %.2f, quantite: %d\n", i+1, T[i], A[i], P[i], Q[i]);
}

void AfficherNtotal() {
  int count = 0, s = 0;
  
  for (int i = 0; i < nb; i++) {
    if (Q[i] == 0) 
      continue;
    else {
      count++;
      s += Q[i];
    }
  }
  printf("Le nombre de livres en tock est %d", count);
  printf("La quantite total de tous les livres en tock est %d", s);
}

void AjouterLivre() {
    int n, quantite;
    char titre[30], auteur[20];
    float prix;

    printf("Combien de livres souhaitez vous ajouter: ");
    scanf("%d", &n);
    getchar(); //consommer le caractère "\n"

    for (int i = 0; i < n; i++) {
        printf("le livre %d:\n", i+1);
        printf("Enter le titre: ");
        scanf("%[^\n]", titre);
        getchar();
        printf("Entrer l'auteur: ");
        scanf("%[^\n]", auteur);
        getchar();
        printf("Entrer le prix: ");
        scanf("%f", &prix);
        getchar();
        printf("Entrer la quantite: ");
        scanf("%d", &quantite);
        getchar();
        printf("\ttitre: %s, auteur: %s, prix: %.2f, quantite: %d\n", titre, auteur, prix, quantite);

        strcpy(T[nb], titre);
        strcpy(A[nb], auteur);
        P[nb] = prix;
        Q[nb] = quantite;
        nb++;
    }
}

void MiseAjour() {
    char titre[20];
    int q;
    
    printf("Entrer le titre du livre pour modifier sa quantite: ");
    scanf("%[^\n]", titre);
    getchar();
    
    for (int i = 0; i < nb; i++) {
        if (strcmp(T[i], titre) == 0) {
            printf("Entrer la nouvelle quantite: ");
            scanf("%d", &q);
            
            Q[i] = q;
            
            printf("Quantite mise a jour:\n\t%s, %s, %f, %d\n", T[i], A[i], P[i], Q[i]);
        }
    }
}

void RechercherLivre() {
    char titre[20];

    printf("Entrer le titre du livre: ");
    scanf("%[^\n]", titre);
    getchar();

    for (int i = 0; i < nb; i++) {
        if (strcmp(T[i], titre) == 0) {
            printf("Livre trouve:\n\t%s, %s, %f, %d\n", titre, A[i], P[i], Q[i]);
            break;
        }
    }
}

void SupprimerLivre() {
    char titre[20];
    
    printf("Entrer le titre du livre que vous voulez supprimer: ");
    scanf("%[^\n]", titre);
    
    for (int i = 0; i < nb; i++) {
        if (strcmp(titre, T[i]) == 0) {
            for (int j = i; j < nb; j++) {
                strcpy(T[j], T[j+1]);
                strcpy(A[j], A[j+1]);
                P[j] = P[j+1];
                Q[j] = Q[j+1];
            }
            nb--;
            printf("livre supprime\n");
            break;
        }
    }
}

void Menu() {
    int choix;

    printf("MENU:\n");
    printf("\t1. Ajouter un livre\n");
    printf("\t2. Afficher les livres en stock\n");
    printf("\t3. Rechercher un livre\n");
    printf("\t4. Mise a jour la quantite d'un livre\n");
    printf("\t5. Supprimer un livre\n");
    printf("\t6. Quitter le programme\n");

    printf("Quel est votre choix: ");
    scanf("%d", &choix);
    getchar();

    switch (choix) {
        case 1:
            AjouterLivre();
            Menu();
            break;
        case 2:
            AfficherLivre();
            Menu();
            break;
        case 3:
            RechercherLivre();
            Menu();
            break;
        case 4:
            MiseAjour();
            Menu();
            break;
        case 5:
            SupprimerLivre();
            Menu();
            break;
        case 6:
            exit(0);
        default:
            printf("choix invalide");
    }
}

int main() {
    Menu();

    return 0;
}