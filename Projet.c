#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>



void ajouter_client(){
    srand(time(NULL));
    int id = rand()%(1000000-100000) +100000;
    char nom[50];
    char prenom[50];
    char profession[50];
    char telephone[13];
    printf("Veuillez entrez les informations concernant le client:\nLe nom : ");
    scanf("%s",nom);
    printf("Le Prenom : ");
    scanf("%s",prenom);
    printf("La profession : ");
    scanf("%s",profession);
    printf("Le telephone : ");
    scanf("%s",telephone);

    //Inscription du client dans le fichier CSV

    FILE *fichier= fopen("clients.csv","a");

    if(fichier!=NULL){
        fprintf(fichier,"%d;%s;%s;%s;%s;\n",id,nom,prenom,profession,telephone);
        fclose(fichier);
    }
    else{
        printf("Echec de l'ouverture");
    }

    printf("\nLe client %s %s a bien ete ajoute avec comme identifiant : %d\n\n",nom,prenom,id);
}

void modifier_client(){

    int idseek;
    char nom[50];
    char prenom[50];
    char profession[50];
    char telephone[13];

    char tmpString[2000] = "";

    printf("Veuillez entrez l'id du client a modifier : ");
    scanf("%d",&idseek);

    printf("Veuillez entrez maintenant les  nouvelles informations concernant le client:\nSon nom : ");
    scanf("%s",nom);
    printf("Son Prenom : ");
    scanf("%s",prenom);
    printf("Sa profession : ");
    scanf("%s",profession);
    printf("Son telephone : ");
    scanf("%s",telephone);

    // Modification du client dans le CSV
    FILE *fichier= fopen("clients.csv", "r");

    if(fichier!=NULL){

        char ligne[300];

        int id;
        char strId[8];
        char tmpLine[150];

        while(fgets(ligne, 300, fichier) != NULL) {

            sscanf(ligne, "%d;%s", &id, tmpLine);

            if(id != idseek){
                strcat(tmpString, ligne);
            } else {
                sprintf(strId, "%d", id);
                strcat(strId, ";");

                strcat(tmpString, strId);
                strcat(tmpString, nom);
                strcat(tmpString, ";");
                strcat(tmpString, prenom);
                strcat(tmpString, ";");
                strcat(tmpString, profession);
                strcat(tmpString, ";");
                strcat(tmpString, telephone);
                strcat(tmpString, ";");
                strcat(tmpString, "\n");
            }
        }

        fclose(fichier);
    }
    else{
        printf("Echec de l'ouverture");
    }

    // replace file content
    fichier= fopen("clients.csv", "w");

    if(fichier!=NULL){
        fputs(tmpString, fichier);

        fclose(fichier);

        printf("\nLe client %s %s a bien été mis à jour\n\n", prenom, nom);
    }
    else{
        printf("Echec de l'ouverture");
    }
}

void supprimer_client(){

    int idseek;
    char tmpString[2000] = "";

    printf("Veuillez entrez l'id du client à supprimer : ");
    scanf("%d", &idseek);

    // Suppression du client dans le CSV
    FILE *fichier= fopen("clients.csv", "r");

    if(fichier!=NULL){

        char ligne[300];

        int id;
        char tmpLine[150];

        while(fgets(ligne, 300, fichier) != NULL) {

            sscanf(ligne, "%d;%s", &id, tmpLine);

            if(id != idseek){
                strcat(tmpString, ligne);
            }
        }

        fclose(fichier);
    }
    else{
        printf("Echec de l'ouverture");
    }

    // replace file content
    fichier= fopen("clients.csv", "w");

    if(fichier!=NULL){
        fputs(tmpString, fichier);

        fclose(fichier);

        printf("\nLe client ayant pour id %d a bien été supprimé\n\n", idseek);
    }
    else{
        printf("Echec de l'ouverture");
    }
}

void rechercher_client(){
    char nomseek[50];
    char nom[50];

    printf("Veuillez entrez le nom du client a rechercher : ");
    scanf("%s",nomseek);

    FILE *fichier= fopen("clients.csv","r");

    if(fichier!=NULL){

        int id;
        char ligne[200];

        while(fscanf(fichier, "%d;%s;", &id, ligne) > 0){

            char *name;
            char *search = ";";
            name = strtok(ligne, search);

            strcpy(nom , name);

            if(strcmp(nom,nomseek) == 0){
                printf("\nUn client avec comme nom %s a bien ete trouve : \n",nom);
                printf("\tId : %d\n",id);
                name = strtok(NULL, search);
                printf("\tPrenom : %s\n",name);
                name = strtok(NULL, search);
                printf("\tProfession : %s\n",name);
                name = strtok(NULL, search);
                printf("\tTelephone : %s\n",name);
            }
        }

    fclose(fichier);

    }
    else{
        printf("Echec de l'ouverture");
    }

}

char* rechercher_client_by_id(int proprio){
    static char nom[50];

    FILE *fichier= fopen("clients.csv","r");

    if(fichier!=NULL){

        int id;
        char ligne[200];

        while(fscanf(fichier,"%d;%s;",&id,ligne)>0){

            char *name;
            char *search = ";";
            name = strtok(ligne, search);

            if(id == proprio){
                strcpy(nom , name);
            }
        }

    fclose(fichier);

    }
    else{
        printf("Echec de l'ouverture");
    }
    return nom;
}


void creer_compte(){
    srand(time(NULL));
    int id = rand()%(1000000-100000) +100000;
    int proprio;
    float solde;
    float taux;
    int duree;

    printf("Veuillez entrez les informations concernant le Compte:\nL'Id client du proprietaire : ");
    scanf("%d",&proprio);
    printf("Le solde : ");
    scanf("%f",&solde);
    printf("Le taux : ");
    scanf("%f",&taux);
    printf("La duree en jours avant activation : ");
    scanf("%d",&duree);

    FILE *fichier= fopen("comptes.csv","a");

    if(fichier!=NULL){
        fprintf(fichier,"%d;%f;%f;%d;%d;\n",id,solde,taux,duree,proprio);
        fclose(fichier);
    }
    else{
        printf("Echec de l'ouverture");
    }

    printf("\nLe Compte numero %d avec comme proprietaire %s a bien ete creer\n\n",id,rechercher_client_by_id(proprio));

}

void consulter_compte(){
    int idseek;

    printf("Veuillez entrez l'id du proprietaire du compte a rechercher : ");
    scanf("%d",&idseek);

    FILE *fichier= fopen("comptes.csv","r");

    if(fichier!=NULL){

        int id;
        int proprio;
        float solde;
        float taux;
        int duree;

        while(fscanf(fichier,"%d;%f;%f;%d;%d;",&id,&solde,&taux,&duree,&proprio)>0){

            if(proprio == idseek){
                printf("\nUn compte avec comme propietaire %s a bien ete trouve : \n\tId : %d\n\tSolde : %f\n\tTaux : %f\n\tDuree : %d\n",rechercher_client_by_id(proprio),id,solde,taux,duree);
            }
        }

    fclose(fichier);

    }
    else{
        printf("Echec de l'ouverture");
    }

}

void fermer_compte(){
    int idseek;
    char tmpString[2000] = "";

    printf("Veuillez entrez l'id du compte a supprimer : ");
    scanf("%d", &idseek);

    // Suppression du client dans le CSV
    FILE *fichier= fopen("comptes.csv", "r");

    if(fichier!=NULL){

        char ligne[300];

        int id;
        char tmpLine[150];

        while(fgets(ligne, 300, fichier) != NULL) {

            sscanf(ligne, "%d;%s", &id, tmpLine);

            if(id != idseek){
                strcat(tmpString, ligne);
            }
        }

        fclose(fichier);
    }
    else{
        printf("Echec de l'ouverture");
    }

    // replace file content
    fichier= fopen("comptes.csv", "w");

    if(fichier!=NULL){
        fputs(tmpString, fichier);

        fclose(fichier);

        printf("\nLe compte ayant pour id %d a bien été supprimé\n\n", idseek);
    }
    else{
        printf("Echec de l'ouverture");
    }
}

void gestion_compte(int i){
    char j[20];
    while( i != 0){
        printf("Gestion de comptes \nChoisissez votre action: \n1 - Creer un nouveau compte \n2 - consulter un compte \n3 - Fermer un compte \n0 - Retourner au menu principal\n");
        scanf("%s",j);
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

void deposer_argent(){

    int idseek;
    float newMontant=0;

    char tmpString[2000] = "";

    printf("Veuillez entrez l'id du compte a crediter : ");
    scanf("%d",&idseek);
    printf("Veuillez entrez le montant a crediter : ");
    scanf("%f",&newMontant);

    // Modification du compte dans le CSV
    FILE *fichier= fopen("comptes.csv", "r");

    if(fichier!=NULL){

        char ligne[300];

        int id;
        char strInt[20];
        char strFloat[20];

        float montant;
        float taux;
        int delais;
        int clientId;

        while(fgets(ligne, 300, fichier) != NULL) {

            sscanf(ligne, "%d;%f;%f;%d;%d", &id, &montant, &taux, &delais, &clientId);

            if(id != idseek){
                strcat(tmpString, ligne);
            } else {
                sprintf(strInt, "%d", id);
                strcat(strInt, ";");
                strcat(tmpString, strInt);

                montant += newMontant;
                sprintf(strFloat, "%f", montant);
                strcat(strFloat, ";");
                strcat(tmpString, strFloat);

                sprintf(strFloat, "%f", taux);
                strcat(strFloat, ";");
                strcat(tmpString, strFloat);

                sprintf(strInt, "%d", delais);
                strcat(strInt, ";");
                strcat(tmpString, strInt);

                sprintf(strInt, "%d", clientId);
                strcat(strInt, ";");
                strcat(tmpString, strInt);

                strcat(tmpString, "\n");
            }
        }

        fclose(fichier);
    }
    else{
        printf("Echec de l'ouverture");
    }

    // replace file content
    fichier= fopen("comptes.csv", "w");

    if(fichier!=NULL){
        fputs(tmpString, fichier);

        fclose(fichier);

        printf("\nLe montant %f a bien été ajouté sur le compte %d\n\n", newMontant, idseek);
    }
    else{
        printf("Echec de l'ouverture");
    }
}

void retirer_argent(){

    int idseek;
    float newMontant=0;

    char tmpString[2000] = "";

    printf("Veuillez entrez l'id du compte a debiter : ");
    scanf("%d",&idseek);
    printf("Veuillez entrez le montant a debiter : ");
    scanf("%f",&newMontant);

    // Modification du compte dans le CSV
    FILE *fichier= fopen("comptes.csv", "r");

    if(fichier!=NULL){

        char ligne[300];

        int id;
        char strInt[20];
        char strFloat[20];

        float montant;
        float taux;
        int delais;
        int clientId;

        while(fgets(ligne, 300, fichier) != NULL) {

            sscanf(ligne, "%d;%f;%f;%d;%d", &id, &montant, &taux, &delais, &clientId);

            if(id != idseek){
                strcat(tmpString, ligne);
            } else {
                sprintf(strInt, "%d", id);
                strcat(strInt, ";");
                strcat(tmpString, strInt);

                montant -= newMontant;
                sprintf(strFloat, "%f", montant);
                strcat(strFloat, ";");
                strcat(tmpString, strFloat);

                sprintf(strFloat, "%f", taux);
                strcat(strFloat, ";");
                strcat(tmpString, strFloat);

                sprintf(strInt, "%d", delais);
                strcat(strInt, ";");
                strcat(tmpString, strInt);

                sprintf(strInt, "%d", clientId);
                strcat(strInt, ";");
                strcat(tmpString, strInt);

                strcat(tmpString, "\n");
            }
        }

        fclose(fichier);
    }
    else{
        printf("Echec de l'ouverture");
    }

    // replace file content
    fichier= fopen("comptes.csv", "w");

    if(fichier!=NULL){
        fputs(tmpString, fichier);

        fclose(fichier);

        printf("\nLe montant %f a bien été débité du compte %d\n\n", newMontant, idseek);
    }
    else{
        printf("Echec de l'ouverture");
    }
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

void gestion_operation(int i){
    char j[20];
    while( i != 0){
        printf("Gestion des opérations \nChoisissez votre action: \n1 - Depot \n2 - Retrait \n3 - Virement \n0 - Retourner au menu principal\n");
        scanf("%s",j);
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

void afficher_somme_all(){

    float total = 0;

    FILE *fichier= fopen("comptes.csv","r");

    if(fichier!=NULL){

        int id;
        char proprio[50];
        float solde;
        float taux;
        int duree;

        while(fscanf(fichier,"%d;%f;%f;%d;%s;",&id,&solde,&taux,&duree,proprio)>0){
            total +=solde;
        }

    fclose(fichier);

    }
    else{
        printf("Echec de l'ouverture");
    }

    printf("La somme de tout les comptes est %f\n",total);
}

void afficher_somme_type(){
    float total = 0;
    int type;

    printf("Un Type de compte est defini par sa duree.\nVeuillez entrez la duree en heure des comptes : ");
    scanf("%d",&type);

    FILE *fichier= fopen("comptes.csv","r");

    if(fichier!=NULL){

        int id;
        char proprio[50];
        float solde;
        float taux;
        int duree;

        while(fscanf(fichier,"%d;%f;%f;%d;%s;",&id,&solde,&taux,&duree,proprio)>0){
                if(duree == type){
                    total +=solde;
                }
        }

    fclose(fichier);

    }
    else{
        printf("Echec de l'ouverture");
    }

    printf("La somme de tout les comptes de duree %d est %f\n",type,total);
}

void afficher_montant_interets(){
    float total = 0;
    int type;

    printf("Un Type de compte est defini par sa duree.\nVeuillez entrez la duree en heure des comptes : ");
    scanf("%d",&type);

    FILE *fichier= fopen("comptes.csv","r");

    if(fichier!=NULL){

        int id;
        char proprio[50];
        float solde;
        float taux;
        int duree;

        while(fscanf(fichier,"%d;%f;%f;%d;%s;",&id,&solde,&taux,&duree,proprio)>0){
                if(duree == type){
                    total +=solde*taux;
                }
        }

    fclose(fichier);

    }
    else{
        printf("Echec de l'ouverture");
    }

    printf("La somme de tout les comptes de duree %d est %f\n",type,total);
}

void exporter(){
    //Exporter l�ensemble des donn�es de l�application
}

void importer(){
    //Importer des donn�es dans l�application (selon un format que vous d�finirez, il est fortement conseill� de se baser sur le format qui vous sert a exporter les donn�es). Dans le cas o� l�application contient d�j� des donn�es, les donn�es import�es devront fusionner avec les anciennes.
}

void administration(int i){
    char j[20];
    while( i != 0){
        printf("Administration \nChoisissez votre action: \n1 - Afficher la somme des montants de tous les comptes \n2 - Afficher la somme des montants par type de compte \n3 - Afficher le montant d'interets total et par type de compte que devra verser la banque a la fin de l'annee \n4 - Exporter l'ensemble des donnees de l'application \n5 - Importer des donnees dans l'application \n0 - Retourner au menu principal\n");
        scanf("%s",j);
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

void gestion_client(int i){
    char j[20];
    while( i != 0){
        printf("Gestion de clients \nChoisissez votre action: \n1 - Ajouter un client\n2 - Modifier un client \n3 - Supprimer un client \n4 - Rechercher un client \n0 - Retourner au menu principal\n");
        scanf("%s",j);
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

void menu(int i){
    char j[20];
    while( i != 0){
        printf("Bienvenue dans la Banque Picsou \nChoisissez votre action:\n1 - Gestion des Clients \n2 - Gestion des comptes \n3 - Gestion des operations \n4 - Administration \n0 - Partir de la Banque\n");
        scanf("%s", j);
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

int main(void){
    menu(1);

    return 0;
}

