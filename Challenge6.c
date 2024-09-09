#include <stdio.h>

int main() {
    int n, i, f;

    printf("Combien d'element voulez-vous entrer ?: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Le nombre d'element doit être positif.\n");
        return 1;
    }

    int tableau[n];

    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    printf("Entrez le facteur de multiplication : ");
    scanf("%d", &f);

    printf("Le tableau après multiplication est :\n");
    for (i = 0; i < n; i++) {
        tableau[i] *= f;
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}