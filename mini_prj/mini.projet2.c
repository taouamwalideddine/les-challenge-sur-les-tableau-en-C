#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char nom[50];
    char numero[15];
    char email[50];
};


void ajouterContact(struct Contact contacts[], int* n) {
    if (*n >= MAX_CONTACTS) {
        printf("La liste des contacts est pleine.\n");
        return;
    }

    printf("Entrer le nom : ");
    scanf("%49s", contacts[*n].nom); 

    printf("Entrer le numero de telephone: ");
    scanf("%14s", contacts[*n].numero);  

    printf("Entrer l'adresse e-mail: ");
    scanf("%49s", contacts[*n].email);  

    (*n)++; 
    printf("Contact ajoute avec succes!\n");
}

void modifierContact(struct Contact contacts[], int n) {
    char nom[50];
    printf("Entrer le nom du contact a modifier: ");
    scanf("%49s", nom); 

    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i].nom, nom) == 0) {
            printf("Entrer le nouveau numero de telephone: ");
            scanf("%14s", contacts[i].numero);
            printf("Entrer la nouvelle adresse e-mail: ");
            scanf("%49s", contacts[i].email);  
            printf("Contact modifie.\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
}

void supprimerContact(struct Contact contacts[], int* n) {
    char nom[50];
    printf("Entrer le nom du contact a supprimer: ");
    scanf("%49s", nom);  

    for (int i = 0; i < *n; i++) {
        if (strcmp(contacts[i].nom, nom) == 0) {
            contacts[i] = contacts[*n - 1]; 
            
            (*n)--; 
            printf("Contact supprime.\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
}

void afficherContacts(struct Contact contacts[], int n) {
    if (n == 0) {
        printf("Aucun contact a afficher.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < n; i++) {
        printf("Nom: %s\nTelephone: %s\nEmail: %s\n\n", contacts[i].nom, contacts[i].numero, contacts[i].email);
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int nombreContacts = 0;
    int choix;

    do {
      
        printf("Menu:\n");
        printf("1. Ajouter un contact\n");
        printf("2. Modifier un contact\n");
        printf("3. Supprimer un contact\n");
        printf("4. Afficher les contacts\n");
        printf("5. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterContact(contacts, &nombreContacts);
                break;
            case 2:
                modifierContact(contacts, nombreContacts);
                break;
            case 3:
                supprimerContact(contacts, &nombreContacts);
                break;
            case 4:
                afficherContacts(contacts, nombreContacts);
                break;
            case 5:
                printf("Quitter le programme.\n");
                break;
            default:
                printf("Option invalide. Veuillez reessayer.\n");
        }
    } while (choix != 5);

    return 0;
}