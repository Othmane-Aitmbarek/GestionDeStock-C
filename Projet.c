#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Commande {
    char nom[50];
    char prenom[50];
    char adresse[100];
    char tel[20];
    int numero;
    char date[20];
};

struct CommandeAchat {
    int numero;
    char date[20];
    char referenceFournisseur[50];
};

struct Produit {
    char libelle[50];
    float prixUnitaire;
    int stock;
};

void ajouterCommande(struct Commande *commande) {
    printf("Ajouter une commande\n");

    printf("Nom: ");
    fgets(commande->nom, 50, stdin);
    commande->nom[strcspn(commande->nom, "\n")] = '\0';  // Supprimer le saut de ligne

    printf("Prenom: ");
    fgets(commande->prenom, 50, stdin);
    commande->prenom[strcspn(commande->prenom, "\n")] = '\0';

    printf("Adresse: ");
    fgets(commande->adresse, 100, stdin);
    commande->adresse[strcspn(commande->adresse, "\n")] = '\0';

    printf("Telephone: ");
    fgets(commande->tel, 20, stdin);
    commande->tel[strcspn(commande->tel, "\n")] = '\0';

    printf("Numero de commande: ");
    scanf("%d", &(commande->numero));

    printf("Date de commande: ");
    getchar();  // Vider le tampon du caractère précédent
    fgets(commande->date, 20, stdin);
    commande->date[strcspn(commande->date, "\n")] = '\0';

    printf("La commande a ete ajoutee avec succes.\n");
}

void modifierCommande(struct Commande *commande) {
    printf("Modifier une commande\n");

    printf("Numero de commande: ");
    int numero;
    scanf("%d", &numero);

    if (commande->numero == numero) {
        getchar();  // Vider le tampon du caractère précédent

        printf("Nouveau numero de commande: ");
        scanf("%d", &(commande->numero));

        printf("Nouvelle date de commande: ");
        getchar();  // Vider le tampon du caractère précédent
        fgets(commande->date, 20, stdin);
        commande->date[strcspn(commande->date, "\n")] = '\0';

        printf("La commande a ete modifiee avec succes.\n");
    } else {
        printf("Aucune commande correspondant au numero saisi n'a ete trouvee.\n");
    }
}

void afficherListeCommandes(struct Commande *commande) {
    printf("Liste des articles commandes\n");

    // Afficher les informations de la commande
    printf("Nom: %s\n", commande->nom);
    printf("Prenom: %s\n", commande->prenom);
    printf("Adresse: %s\n", commande->adresse);
    printf("Telephone: %s\n", commande->tel);
    printf("Numero de commande: %d\n", commande->numero);
    printf("Date de commande: %s\n", commande->date);
}

void ajouterCommandeAchat(struct CommandeAchat *commandeAchat) {
    printf("Ajouter une commande d'achat\n");

    printf("Numero de commande: ");
    scanf("%d", &(commandeAchat->numero));

    printf("Date de commande: ");
    getchar();  // Vider le tampon du caractère précédent
    fgets(commandeAchat->date, 20, stdin);
    commandeAchat->date[strcspn(commandeAchat->date, "\n")] = '\0';

    printf("Reference fournisseur: ");
    fgets(commandeAchat->referenceFournisseur, 50, stdin);
    commandeAchat->referenceFournisseur[strcspn(commandeAchat->referenceFournisseur, "\n")] = '\0';

    printf("La commande d'achat a ete ajoutee avec succes.\n");
}

void afficherListeArticlesCommandes() {
    printf("Afficher la liste des articles commandes\n");

    // Afficher la liste des articles commandés
    // Code à implémenter

    printf("Liste des articles commandes affichee avec succes.\n");
}

void ajouterProduit(struct Produit *produit) {
    printf("Ajouter un produit\n");

    printf("Libelle: ");
    fgets(produit->libelle, 50, stdin);
    produit->libelle[strcspn(produit->libelle, "\n")] = '\0';  // Supprimer le saut de ligne

    printf("Prix unitaire: ");
    scanf("%f", &(produit->prixUnitaire));

    printf("Stock: ");
    scanf("%d", &(produit->stock));

    printf("Le produit a ete ajoute avec succes.\n");
}

void afficherProduitsSeuilCritique(struct Produit *produits, int taille, int seuilCritique) {
    printf("Afficher les produits atteignant le seuil critique de quantite\n");

    int i;
    int count = 0;  // Compter le nombre de produits atteignant le seuil critique

    for (i = 0; i < taille; i++) {
        if (produits[i].stock <= seuilCritique) {
            printf("Produit: %s\n", produits[i].libelle);
            printf("Prix unitaire: %.2f\n", produits[i].prixUnitaire);
            printf("Stock: %d\n", produits[i].stock);
            count++;
        }
    }

    if (count == 0) {
        printf("Aucun produit n'a atteint le seuil critique de quantite.\n");
    }
}

int main() {
    struct Commande commande;
    struct CommandeAchat commandeAchat;
    struct Produit produits[5];

    int choix;

    do {
        printf("------------------Menu:------------------\n");
        printf("I. Gestion des ventes\n");
        printf("1. Ajouter une commande\n");
        printf("2. Modifier une commande\n");
        printf("3. Afficher la liste des articles commandes\n");
        printf("\n");
        printf("II. Gestion des achats\n");
        printf("1. Ajouter une commande d'achat\n");
        printf("2. Afficher la liste des articles commandes\n");
        printf("\n");
        printf("III. Gestion des stocks\n");
        printf("1. Ajouter un produit\n");
        printf("2. Afficher les produits atteignant le seuil critique de quantite\n");
        printf("\n");
        printf("0. Quitter\n");
        printf("\nFaites votre choix: ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1:
                ajouterCommande(&commande);
                break;
            case 2:
                modifierCommande(&commande);
                break;
            case 3:
                afficherListeCommandes(&commande);
                break;
            case 4:
                ajouterCommandeAchat(&commandeAchat);
                break;
            case 5:
                afficherListeArticlesCommandes();
                break;
            case 6:
                ajouterProduit(&produits[0]);
                break;
            case 7:
                afficherProduitsSeuilCritique(produits, 5, 10);
                break;
            case 0:
                printf("Programme termine.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
