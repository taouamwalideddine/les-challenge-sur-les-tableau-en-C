#include <stdio.h>

int main() { int arr[30]; int n, i, j, temp;

printf("Entrez le nombre d'entiers (max est %d): ", 30);
scanf("%d", &n);

if (n > 30) {
    printf("Le nombre d'entiers depasser la taille maximale autoriser.\n");
    return 0;
}

printf("Entrez %d entiers:\n", n);
for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
}

for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {

            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

printf("Tableau trie en ordre croissant:\n");
for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
}
printf("\n");

return 0;
