#include <stdio.h>

int main() {
    int n;


    printf("Combien d'elements tu veut entrer ? ");
    scanf("%d", &n);

    int ar[n];

    for (int i = 0; i < n; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &ar[i]);
    }

    printf("Les elements sont : ");
    for (int i = 0; i < n; i++) {
        printf("\n%d\n ", ar[i]);
    }
    printf("\n");

    return 0;
}