#include <stdio.h>

int main() {
    int n; 
    int somme = 0; 

    printf("Entrez le nombre d'element du tableau : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Le nombre d'element doit être positif.\n");
        return 1; 
    }

    int tableau[n];

    printf("Entrez les %d element du tableau :\n", n);
    for (int i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    for (int i = 0; i < n; i++) {
        somme += tableau[i];
    }


    printf("La somme des element du tableau est : %d\n", somme);

    return 0; 
}