#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void menu(int i){
    char j[20];
    while( i != 0){
        printf("Bienvenue dans la Banque Picsou \nChoisissez votre action:\n1 - Gestion des Clients \n2 - Gestion des comptes \n3 - Gestion des operations \n4 - Administration \n0 - Partir de la Banque\n");
        scanf("%s",&j);
        i = atoi(j);
        if ( i == 1){
            gestion_client(i);
        }
        else if ( i == 2){
            gestion_compte(i);
        }
        else if ( i == 3){
            gestion_operation(i);
        }
        else if ( i == 4){
            administration(i);
        }
    }
    printf("Vous quittez la banque Picsou !");
}

void gestion_client(int i){
    char j[20];
    while( i != 0){
        printf("Gestion de clients \nChoisissez votre action: \n1 - Ajouter un client\n2 - Modifier un client \n3 - Supprimer un client \n4 - Rechercher un client \n0 - Retourner au menu principal\n");
        scanf("%s",&j);
        i = atoi(j);
        if ( i == 1){
            ajouter_client();
        }
        else if ( i == 2){
            modifier_client();
        }
        else if ( i == 3){
            supprimer_client();
        }
        else if ( i == 4){
            rechercher_client();
        }
    }
}

void ajouter_client(){
    srand(time(NULL));
    int id = rand()%(1000000-100000) +100000;
    char nom[50];
    char prenom[50];
    char profession[50];
    int telephone;
    printf("Veuillez entrez les informations concernant le client:\nLe nom : ");
    scanf("%s",&nom);
    printf("Le Prenom : ");
    scanf("%s",&prenom);
    printf("La profession : ");
    scanf("%s",&profession);
    printf("Le telephone : ");
    scanf("%d",&telephone);

    //Inscription du client dans le fichier CSV

    printf("\nLe client %s %s a bien ete ajoute avec comme identifiant : %d\n\n",nom,prenom,id);
}

void modifier_client(){
    int id;
    char nom[50];
    char prenom[50];
    char profession[50];
    int telephone;
    printf("Veuillez entrez l'id du client a modifier : ");
    scanf("%d",&id);

    // Sélection du clients dans le fichier CSV

    printf("Veuillez entrez maintenant les  nouvelles informations concernant le client:\nSon nom : ");
    scanf("%s",&nom);
    printf("Son Prenom : ");
    scanf("%s",&prenom);
    printf("Sa profession : ");
    scanf("%s",&profession);
    printf("Son telephone : ");
    scanf("%d",&telephone);

    // Modification du client dans le CSV

}

void supprimer_client(){
    int id;
    printf("Veuillez entrez l'id du client a supprimer : ");
    scanf("%d",&id);

    // Suppression du client dans le CSV

}

void rechercher_client(){
    char nom[50];
    printf("Veuillez entrez le nom du client a rechercher : ");
    scanf("%s",&nom);

    // Recherche du client dans le CSV

}

void gestion_compte(int i){
    char j[20];
    while( i != 0){
        printf("Gestion de comptes \nChoisissez votre action: \n1 - Creer un nouveau compte \n2 - consulter un compte \n3 - Fermer un compte \n0 - Retourner au menu principal\n");
        scanf("%s",&j);
        i = atoi(j);
        if ( i == 1){
            creer_compte();
        }
        else if ( i == 2){
            consulter_compte();
        }
        else if ( i == 3){
            fermer_compte();
        }
    }
}

void creer_compte(){
    srand(time(NULL));
    int id = rand()%(1000000-100000) +100000;
    char proprio[50];
    float solde;
    float taux;
    int duree;

    printf("Veuillez entrez les informations concernant le Compte:\nLe nom  du proprietaire: ");
    scanf("%s",&proprio);
    printf("Le solde : ");
    scanf("%f",&solde);
    printf("Le taux : ");
    scanf("%f",&taux);
    printf("La duree en heures : ");
    scanf("%d",&duree);

    //Inscription du compte dans le fichier CSV

    printf("\nLe Compte numero %d avec comme proprietaire %s a bien ete creer\n\n",id,proprio);
}

void consulter_compte(){
    int proprio;
    printf("Veuillez entrez le nom du proprietaire du compte a rechercher : ");
    scanf("%s",&proprio);

    // Recherche du compte dans le CSV

}

void fermer_compte(){
    int id;
    printf("Veuillez entrez l'id du compte a supprimer : ");
    scanf("%d",&id);

    // Suppression du client dans le CSV

}

void gestion_operation(int i){
    char j[20];
    while( i != 0){
        printf("Gestion des opérations \nChoisissez votre action: \n1 - Depot \n2 - Retrait \n3 - Virement \n0 - Retourner au menu principal\n");
        scanf("%s",&j);
        i = atoi(j);
        if ( i == 1){
            deposer_argent();
        }
        else if ( i == 2){
            retirer_argent();
        }
        else if ( i == 3){
            virer_argent();
        }
    }
}

void deposer_argent(){
    int id;
    float montant=0;
    printf("Veuillez entrez l'id du compte a crediter : ");
    scanf("%d",&id);
    printf("Veuillez entrez le montant a crediter : ");
    scanf("%f",&montant);

    // modification du compte dans le CSV
}

void retirer_argent(){
    int id;
    float montant=0;
    printf("Veuillez entrez l'id du compte a debiter : ");
    scanf("%d",&id);
    printf("Veuillez entrez le montant a debiter : ");
    scanf("%f",&montant);

    // modification du compte dans le CSV
}

void virer_argent(){
    int id_a;
    int id_b;
    float montant=0;
    printf("Veuillez entrez l'id du compte a debiter : ");
    scanf("%d",&id_a);
    printf("Veuillez entrez l'id du compte a crediter : ");
    scanf("%d",&id_b);
    printf("Veuillez entrez le montant a bouger : ");
    scanf("%f",&montant);

    // modification du compte dans le CSV
}

void administration(int i){
    char j[20];
    while( i != 0){
        printf("Administration \nChoisissez votre action: \n1 - Afficher la somme des montants de tous les comptes \n2 - Afficher la somme des montants par type de compte \n3 - Afficher le montant d'interets total et par type de compte que devra verser la banque a la fin de l'annee \n4 - Exporter l'ensemble des donnees de l'application \n5 - Importer des donnees dans l'application \n0 - Retourner au menu principal\n");
        scanf("%s",&j);
        i = atoi(j);
        if ( i == 1){
            afficher_somme_all();
        }
        else if ( i == 2){
            afficher_somme_type();
        }
        else if ( i == 3){
            afficher_montant_interets();
        }
        else if ( i == 4){
            exporter();
        }
        else if ( i == 5){
            importer();
        }
    }
}

void afficher_somme_all(){
    //la somme des montants de tous les comptes du CSV
}

void afficher_somme_type(){
    //la somme des montants par type de compte du CSV
}

void afficher_montant_interets(){
    //le montant d’intérêts total et par type de compte que devra verser la banque a la fin de l’année du CSV
}

void exporter(){
    //Exporter l’ensemble des données de l’application
}

void importer(){
    //Importer des données dans l’application (selon un format que vous définirez, il est fortement conseillé de se baser sur le format qui vous sert a exporter les données). Dans le cas où l’application contient déjà des données, les données importées devront fusionner avec les anciennes.
}


int main(void){
   menu(1);
   return 0;
}

