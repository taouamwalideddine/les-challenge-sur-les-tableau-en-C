#include <stdio.h>

int main() {
    int n, i;
    int min;

    printf("Combien d'elements voulez-vous entrer ?: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Le nombre d'element doit etre positif.\n");
        return 1;
    }

    int tableau[n];

    for (i = 0; i < n; i++) {
        printf("element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    min = tableau[0];
    for (i = 1; i < n; i++) {
        if (tableau[i] < min) {
            min = tableau[i];
        }
    }

    printf("Le plus petit element est : %d\n", min);

    return 0;
}