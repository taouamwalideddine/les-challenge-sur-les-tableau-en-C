#include <stdio.h>
#include <string.h>
#include <time.h>

#define lesTache 100
#define lesTitre 100
#define lesDescr 256

typedef enum
{
  A_reliser,
  enCours,
  Done
  } Statut;

typedef struct
{
  int id;
  char titre[lesTitre];
  char description[lesDescr];
  struct tm deadLine;
  Statut statut_tache;
} Tache;

Tache taches[lesTache];
int nombre_taches = 0;

void afficher_menu()
{
  printf("\n*** Systeme de Gestion de Taches ***\n");
  printf("1. Ajouter une tache\n");
  printf("2. Afficher toutes les taches\n");
  printf("3. Modifier une tache\n");
  printf("4. Supprimer une tache\n");
  printf("5. Afficher les statistiques\n");
  printf("6. Quitter\n");
  printf("Choisissez une option : ");
}

void ajouter_tache()
{
  int n;

  if (nombre_taches >= lesTache)
  {
    printf("Nombre maximum de taches atteint.\n");
    return;
  }

  printf("Combien de taches voulez-vous ajouter? ");
  scanf("%d", &n);
  getchar();

  //Tache t = {.id = nombre_taches + 1};
  
  for(int i = 0; i < n; i++) {
    int Id = nombre_taches+1;
      printf("\nl'ID de la tache%d :%d\n",i+1,Id);
      taches[nombre_taches].id = Id;

      printf("Titre de la tache : ");
      getchar(); 
      fgets(taches[i].titre, lesTitre, stdin);
      taches[i].titre[strcspn(taches[i].titre, "\n")] = '\0';

      printf("Description de la tache : ");
      fgets(taches[i].description, lesDescr, stdin);
      taches[i].description[strcspn(taches[i].description, "\n")] = '\0';

      printf("deadline (JJ/MM/AAAA) : ");
      scanf("%d/%d/%d", &taches[i].deadLine.tm_mday, &taches[i].deadLine.tm_mon, &taches[i].deadLine.tm_year);
      taches[i].deadLine.tm_mon--;
      taches[i].deadLine.tm_year -= 1900;

      printf("Statut (0 = A realiser, 1 = En cours, 2 = done) : ");
      int s;
      scanf("%d", &s);
      taches[i].statut_tache = (Statut)s;

      //taches[nombre_taches++] = taches[i];
      printf("Tache ajoutee avec succes !\n");

      nombre_taches++;
  }
}

  
void RechercherTache() {
  char Titre[30];
  int choix, Id[30];

  printf("Coisissez l'option convenable: \n");
  printf("\t1. Rechercher par ID.\n");
  printf("\t1. Rechercher par Titre.\n");
  printf("Entrez votre choix: ");
  scanf("%d", &choix);

  switch (choix) {
    case 1:
      for (int i = 0; i < nombre_taches; i++) {
        if(taches[i].id == Id) {
          printf("Tache trouvée\n");
          for (int j = 0; j < nombre_taches; j++)
            printf("Tache: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadLine, taches[i].statut_tache);
        }
      }
  

    case 2:
      for (int i = 0; i < nombre_taches; i++) {
        if(strcmp(taches[i].titre, Titre) == 0) {
          printf("Tache trouvee\n");
          for (int j = 0; j < nombre_taches; j++)
            printf("Tache: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadLine, taches[i].statut_tache);
        }
      }
  }

}
  

/*void afficher_tache(int i, Tache taches[i])
{
  printf("ID: %d\nTitre: %s\nDescription: %s\n", taches[i].id, taches[i].titre, taches[i].description);
  printf("deadLine: %02d/%02d/%04d\n", taches[i].deadLine.tm_mday, taches[i].deadLine.tm_mon + 1, taches[i].deadLine.tm_year + 1900);
  printf("Statut: %s\n", taches[i].statut_tache == A_reliser ? "A realiser" : taches[i].statut_tache == enCours ? "En cours" : taches[i].statut_tache == Done ? "Done" : "Inconnu");
}*/

void afficher_toutes_les_taches()
{
  if (nombre_taches == 0)
  {
    printf("Aucune tache a afficher.\n");
    return;
  }
  for (int i = 0; i < nombre_taches; i++)
  {
    printf("\nTache %d :\n", i+1);
    //afficher_tache(i, &taches[i]);
    printf("ID: %d\nTitre: %s\nDescription: %s\n", taches[i].id, taches[i].titre, taches[i].description);
    printf("deadLine: %02d/%02d/%04d\n", taches[i].deadLine.tm_mday, taches[i].deadLine.tm_mon + 1, taches[i].deadLine.tm_year + 1900);
    printf("Statut: %s\n", taches[i].statut_tache == A_reliser ? "A realiser" : taches[i].statut_tache == enCours ? "En cours" : taches[i].statut_tache == Done ? "Done" : "Inconnu");

  }
}

void modifier_tache()
{
  int id;
  printf("Entrez l'identifiant de la tache a modifier : ");
  scanf("%d", &id);

  if (id < 1 || id > nombre_taches){
    printf("Tache avec cet identifiant introuvable.\n");
    return;
  }

  Tache *t = &taches[id - 1];
  printf("Modifier la description (Enter pour ne pas modifier) : ");
  getchar();
  fgets(t->description, lesDescr, stdin);
  if (strlen(t->description) > 1)
    t->description[strcspn(t->description, "\n")] = '\0';

  printf("Modifier le statut (0 = A realiser, 1 = En cours, 2 = done) : ");
  int s;
  scanf("%d", &s);
  t->statut_tache = (Statut)s;

  printf("Modifier l'deadLine (JJ/MM/AAAA, Enter pour ne pas modifier) : ");
  getchar();
  char input[11];
  fgets(input, 11, stdin);
  if (strlen(input) > 1)
  {
    sscanf(input, "%d/%d/%d", &t->deadLine.tm_mday, &t->deadLine.tm_mon, &t->deadLine.tm_year);
    t->deadLine.tm_mon--;
    t->deadLine.tm_year -= 1900;
  }

  printf("Tache modifiee avec succes !\n");
}

void supprimer_tache()
{
  int id;
  printf("Entrez l'identifiant de la tache a supprimer : ");
  scanf("%d", &id);

  if (id < 1 || id > nombre_taches)
  {
    printf("Tache avec cet identifiant introuvable.\n");
    return;
  }

  for (int i = id - 1; i < nombre_taches - 1; i++)
  {
    taches[i] = taches[i + 1];
  }
  nombre_taches--;
  printf("Tache supprimee avec succes !\n");
}

void afficher_statistiques()
{
  int a_reliser = 0;
  int en_cours = 0;
  int done = 0;

  for (int i = 0; i < nombre_taches; i++)
  {
    switch (taches[i].statut_tache)
    {
    case A_reliser:
      a_reliser++;
      break;
    case enCours:
      en_cours++;
      break;
    case Done:
      done++;
      break;
    default:
    
      printf("Statut inconnu : %d\n", taches[i].statut_tache);
      break;
    }
  }

  printf("\nStatistiques des taches :\n");
  printf("A realiser: %d\n", a_reliser);
  printf("En cours: %d\n", en_cours);
  printf("Fini: %d\n", done);
}

int main()
{
  int choix;
  do
  {
    afficher_menu();
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
      ajouter_tache();
      break;
    case 2:
      afficher_toutes_les_taches();
      break;
    case 3:
      modifier_tache();
      break;
    case 4:
      supprimer_tache();
      break;
    case 5:
      afficher_statistiques(); 
      break;
    case 6:
      printf("Au revoir !\n");
      break;
    default:
      printf("Choix invalide. Veuillez reessayer.\n");
      break;
    }
  } while (choix != 6);
  return 0;
}
