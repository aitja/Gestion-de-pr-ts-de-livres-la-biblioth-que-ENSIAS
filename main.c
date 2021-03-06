#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#define M 30
#define RETURNTIME 15



void faire_pause(void);
void menu_principal(void);
void ajouter_adherent(void);
void supprimer_adherent(void);
void modifier_adherent(void);
void rechercher_adherent(void);
void emprunter_livre(void);
void afficher_adherent(void);
void quitter_app(void);
int  getdata_adh();
int  checkid(int);
int t(void);



//list of global files that can be acceed form anywhere in program
FILE *f_adh,*ft,*fp;



char catagories[][15]= {"Literature","Science","Relegion","Historique","Architecture","Autre"};
void menu_principal(void);
void ajouter_livre(void);
void supprimer_livre(void);
void modifier_livre(void);
void rechercher_livre(void);
void emprunter_livre(void);
void afficher_livre(void);
void quitter_app(void);
int  getdata();
int  checkid(int);
//void show_mouse(void);
void Password();
void issuerecord();
void loaderanim();
void returnfunc(void);




int s;
char findbook;
char password[10]= {"123"};




COORD coord = {0, 0};
//list of global variable
int s;
char findbook;

struct adherent
{
    int num_adh;
char nom_adh[M];
char prenom_adh[M];
char email_adh[M];
char adress_adh[M];
int nbre_emprunts_adh;
};

struct adherent adh;




















void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct Auteur
{
    char nom_aut[20];
    char prenom_aut[20];
};
struct livre
{
    int num_liv;
    char titre_liv[20];
    struct Auteur auteur_liv;
    char *cat;
    int emprunteur_liv;

};

struct livre a;
int main()
{
    Password();
    getch();
    return 0;

}



void afficher_menu(){
      system("cls");
      system("color FC");

printf("\n\n\n");
printf("  --------------------\t\t\t\t           /\\                                      ----------------- \n");
printf("  | REALISATION       |\t\t\t\t          /  \\                                     |  ENCADREMENT  | \n");
printf("  ---------------------\t\t\t\t         /    \\                                    -----------------\n");
printf("  | Ilyas BENADDOU    |\t\t\t\t        /      \\                                   |  Mme.MOUMANE  | \n");
printf("  | Abdelilah AIT JA  |\t\t\t\t       /        \\                                  -----------------\n");
printf("  --------------------\t\t\t\t      /          \\ \n");
printf("\t\t\t\t\t\t     /____________\\ \n");
printf("\t\t\t\t\t\t     |E-N-S-I-A-S.| \n");
printf("\n\n");
printf("\t\t\t\t\t---------------------------------------\n");
printf("\t\t\t\t\t|1|\t  Gestion des adherents        |\n");
printf("\t\t\t\t\t---------------------------------------\n");
printf("\n\n");
printf("\t\t\t\t\t---------------------------------------\n");
printf("\t\t\t\t\t|2|\t   Gestion des Livres         |\n");
printf("\t\t\t\t\t---------------------------------------\n");
printf("\n\n");
printf("\t\t\t\t\t---------------------------------------\n");
printf("\t\t\t\t\t|3|\t Gestion des emprunts      |\n");
printf("\t\t\t\t\t---------------------------------------\n");
printf("\n\n");
printf("\t\t\t\t\t       VOTRE CHOIX :\t ");

    switch(getch())
    {
    case '1':
        menu_principal_adh();
        break;
    case '2':
        menu_principal();
        break;
    case '3':
        emprunter_livre();
        break;
    default:
    {

        printf("\n entree incorrecte, veuillez reesayer ");
        if(getch())
            afficher_menu();
    }

    }
}




void menu_principal_adh()
{
//loaderanim();
    system("cls");
    system("color FC");

//    textbackground(13);
    int i;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//    show_mouse();
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Ajouter adherent   ");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Supprimer adherent");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Chercher Adherent");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Afficher adherents");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Modifier adherent");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Retour au menu pricipal");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
    gotoxy(20,19);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,21);
    t();
    gotoxy(20,22);
    printf("\n\t\t\t entrer votre choix :");
    switch(getch())
    {
    case '1':
        ajouter_adherent();
        break;
    case '2':
        supprimer_adherent();
        break;
    case '3':
        rechercher_adherent();
        break;

    case '4':
        afficher_adherent();
        break;
    case '5':
        modifier_adherent();
        break;
    case '6':
        afficher_menu();
        break;
    case '8':
    {
        exit(0);
    }
    default:
    {
        gotoxy(10,23);
        printf("\n entree incorrecte, veuillez reesayer ");
        if(getch())
            menu_principal_adh();
    }

    }
}

/////////////////////////////////////////////////////////////////
///
///////////////////////////////////////////////////////////////////
void menu_principal()
{
//loaderanim();
    system("cls");
    	system("color FC");

//    textbackground(13);
    int i;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//    show_mouse();
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Ajouter livre   ");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Supprimer livre");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Rechercher livre");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Afficher livre");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Modifier livre");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Retour au menu pricipal");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Quitter application ");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 8. Ordonner par categorie ");
    gotoxy(20,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,23);
    t();
    gotoxy(20,24);
    printf("Entrez votre choix:");
    switch(getch())
    {
    case '1':
        ajouter_livre();
        break;
    case '2':
        supprimer_livre();
        break;
    case '3':
        rechercher_livre();
        break;

    case '4':
        afficher_livre();
        break;
    case '5':
        modifier_livre();
        break;
    case '6':
        afficher_menu();
        break;
    case '7':
    {
        exit(0);
    }
    case '8':
    	ordonner_livre();
    	break;
    default:
    {
        gotoxy(10,23);
        printf("choix incorrecte, veuillez reessayer ");
        if(getch())
            menu_principal();
    }

    }
}
void returnfunc(void)
{
    {
        printf("\n Appyuez sur ENTER pour revenir au menu principal");
    }
a:
    if(getch()==13) //allow only use of enter
        menu_principal();
    else
        goto a;
}

int rendre_livre(int livre)  //edit information about book / rendre unlivre
{
    system("cls");
    int c=0;
    int d,e;
    gotoxy(20,4);


            fp=fopen("Livre.dat","rb+");///// mn hna remplacer emprunteur par 0 lfo9 blast +1 -1
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(checkid(livre)==0)
                {
                    c=a.emprunteur_liv;
                    a.emprunteur_liv = 0;
                    fseek(fp,ftell(fp)-sizeof(a),0);
                    fwrite(&a,sizeof(a),1,fp);
                    fclose(fp);

                }
            }
        if(c!=0)
        {
         f_adh=fopen("adherent.dat","rb+");
        if (checkid_adh(c) == 0) {
            if (adh.nbre_emprunts_adh < 3) {
                adh.nbre_emprunts_adh = adh.nbre_emprunts_adh - 1;
                fseek(f_adh,ftell(f_adh)-sizeof(adh),0);
                fwrite(&adh,sizeof(adh),1,f_adh);
                fclose(f_adh);
            }
        }
        }
        if(c!=0) {
            printf("livre rendu !\n");
        }
    faire_pause_empr();
}

void emprunter_livre(void)  //function that issue books from library
{
    int t;

    system("cls");
    system("color FC");

    printf("********************************gestion de livre **************************");
    gotoxy(10,5);
    printf("\xDB\xDB\xDB\xDb\xB2 1. Emprunter un livre");
    gotoxy(10,7);
    printf("\xDB\xDB\xDB\xDb\xB2 2. Afficher liste des livres empruntes");
    gotoxy(10,9);
    printf("\xDB\xDB\xDB\xDb\xB2 3. Afficher la liste des adhérents emprunteurs de livre");
    gotoxy(10,11);
    printf("\xDB\xDB\xDB\xDb\xB2 4. Rendre un livre");
    gotoxy(10,13);
    printf("\xDB\xDB\xDB\xDb\xB2 5 Retour au menu principal");
    gotoxy(10,15);
    printf("Enter a Choice:");
    switch(getch())
    {
    case '1':  //issue book
    {
        system("cls");
        system("color FC");

        int c=0, d =0;
        char another='y';
        while(another=='y')
        {
            system("cls");
            system("color FC");

            gotoxy(15,4);
            printf("***emprunter un livre***");
            gotoxy(10,6);
            printf("entrer le numero du livre :");
            scanf("%d",&t);
            fp=fopen("Livre.dat","rb");
            if(checkid(t)==0) //issues those which are present in library
            {


                printf("livre en cour ---------------- %d", a.num_liv);

                printf("le titre du livre est  %s",a.titre_liv);
                gotoxy(10,11);
                printf("entrer le numero de l'emprunteur:");

                scanf("%d",&d);
                a.emprunteur_liv = d;


                        if (modifier_livre_1(a.num_liv, d) ==1 ) {
                                c=1;
                                printf("empreinte effectue avec succes");
                        }


            }
            if(c==0)
            {
                gotoxy(10,11);
                printf("emprente non effectue, veuillez verifier les identifiant de livre et empreinteur ");
            }
            gotoxy(10,15);
            printf("empreinter a nouveau (Y/N):");

            fflush(stdin);
            if(getch()=='y')
                rechercher_livre();
            else
                emprunter_livre();
            fclose(fp);
        }

        break;
    }
    case '2':  //show issued book list ///////////////afficher liste des livre empruntés
    {


      int i, j ;                                             //travail
    system("cls");
    system("color FC");

    gotoxy(1,1);
    printf("*********************************Liste des livres*****************************");
    gotoxy(2,2);
    printf(" CATEGORIE     NUMERO    TITRE                  EMPRUNTEUR_LIV  ");
    j=4;
    fp=fopen("Livre.dat","rb");
    int existe = 0;
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if (a.emprunteur_liv !=0) {
                existe = 1;

                    gotoxy(3,j);
                    printf("%s",a.cat);
                    gotoxy(16,j);
                    printf("   %d",a.num_liv);
                    gotoxy(24,j);
                    printf(" %s\t\t",a.titre_liv);
                    gotoxy(40,j);

                    //printf("\n");
                    f_adh=fopen("adherent.dat","rb+");
                    if (checkid_adh(a.emprunteur_liv) == 0) {
                            printf("  \t\t%d : %s %s", a.emprunteur_liv ,adh.nom_adh, adh.prenom_adh);
                    } else {
                        printf("  \t\t%d",a.emprunteur_liv);
                    }
                    gotoxy(50,j);



                j++;
                i++;
            }
    }
    gotoxy(3,25);
    fclose(fp);
    fclose(f_adh);
    gotoxy(35,25);

    if (existe == 0) printf("y'a aucun livre emprunte \n");
    faire_pause_empr();
    }
    break;
    case '3':   //search issued books by id
    {



      int i, j ;                                             //travail
    system("cls");
    system("color FC");

    gotoxy(1,1);
    printf("*********************************liste des livres*****************************");
    gotoxy(2,2);
    printf("*********************************Liste adherent ***************************** \n");
    printf("Identifiant            nom                           prenom                        Email                         Adresse                    nbr empr\n");

    j=4;
    fp=fopen("Livre.dat","rb");
    int existe = 0;
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if (a.emprunteur_liv !=0) {
                existe = 1;
                    f_adh=fopen("adherent.dat","rb+");
                    if (checkid_adh(a.emprunteur_liv) == 0) {
                            gotoxy(1,j);
                            printf("%d",adh.num_adh);
                            gotoxy(23,j);
                            printf("%s",adh.nom_adh);
                            gotoxy(53,j);
                            printf("%s",adh.prenom_adh);
                            gotoxy(83,j);
                            printf("%s",adh.email_adh);
                            gotoxy(113,j);
                            printf("%s",adh.adress_adh);
                            gotoxy(143,j);
                            printf("%d",adh.nbre_emprunts_adh);
                    }
                    gotoxy(50,j);



                j++;
                i++;
            }
    }
    gotoxy(3,25);
    fclose(fp);
    fclose(f_adh);
    gotoxy(35,25);

    if (existe == 0) printf("y'a aucun livre emprunte \n");
    faire_pause_empr();
    }
    break;
    case '4':  //remove issued books from list
    {
    system("cls");
        printf("entrer le numero du livre :"); ///////// rendre livre if(checkid(t)!=0
                                                                             //at
            scanf("%d",&t);
          rendre_livre(t);
    faire_pause_empr();

    }
    case '5':
        afficher_menu();
        break;
    default:
        gotoxy(10,18);
        printf("\aErreur!!");
        getch();
        emprunter_livre();
        break;

    }


    gotoxy(1,30);
}

void ajouter_livre(void)    //funtion that add books
{

     system("cls");
          system("color FC");

    int i;
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Literature");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Science");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Relegion");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Historique");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Architecture");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Autre ..");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Retour au menu");
    gotoxy(20,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,22);
    printf("Tapez votre choix:");
    scanf("%d",&s);
    if(s==7)

        menu_principal() ;
    system("cls");
    system("color FC");

    fp=fopen("Livre.dat","ab+");
    if(getdata()==1)
    {
        a.cat=catagories[s-1];
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(21,14);
        printf("ajoute avec succes !!");
        gotoxy(21,15);
        printf("Voulez vous ajouter un autre ?(Y / N):");
        if(getch()=='n')
            menu_principal();
        else {
            ajouter_livre();
        }
    }
}
void supprimer_livre()    //function that delete items from file fp
{
    system("cls");
    system("color FC");

    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
        system("cls");
        system("color FC");

        gotoxy(10,5);
        printf("Entrer le numero du livre à supprimer");
        scanf("%d",&d);
        fp=fopen("Livre.dat","rb+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.num_liv==d)
            {

                gotoxy(10,7);
                printf("le livre est disponible ");
                gotoxy(10,8);
                printf(" titre est : %s",a.titre_liv);
                gotoxy(10,9);
                findbook='t';
            }
        }
        if(findbook!='t')
        {
            gotoxy(10,10);
            printf("No record is found modify the search");
            if(getch())
                menu_principal();
        }
        if(findbook=='t' )
        {
            gotoxy(10,9);
            printf("etes vous sur de suprrimer ?(Y/N):");
            if(getch()=='y')
            {
                ft=fopen("test.dat","wb+");  //temporary file for delete
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.num_liv!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(ft);
                fclose(fp);
                remove("Livre.dat");
                rename("test.dat","Livre.dat"); //copy all item from temporary file to fp except that
                fp=fopen("Livre.dat","rb+");    //we want to delete
                if(findbook=='t')
                {
                    gotoxy(10,10);
                    printf("The record is sucessfully deleted");
                    gotoxy(10,11);
                    printf("Supprimer un autre ?(Y/N)");
                }
            }
            else
                menu_principal();

            fclose(fp);
            fflush(stdin);
            another=getch();
        }
    }
    gotoxy(10,15);
    menu_principal();
}

/////////////// rechercher livre
void rechercher_livre()
{
    system("cls");
    system("color FC");

    int d;
    printf("*****************************Rechercher livre*********************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Rechercher par Numero");
    gotoxy(20,14);
    fp=fopen("Livre.dat","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
        system("cls");
        system("color FC");

        gotoxy(25,4);
        printf("****Rechercher livre par numero****");
        gotoxy(20,5);
        printf("Entrez le numero de livre :");
        scanf("%d",&d);
        gotoxy(20,7);
        printf("le livre recherche n'existe pas");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.num_liv==d)
            {
                Sleep(2);
                gotoxy(20,7);
                printf("le livre recherche existe                                     ");
                printf("\n\xB2 Numero:%d",a.num_liv);

                printf("\n\xB2 Titre:%s",a.titre_liv);
                printf("\n\xB2 Nom de l'auteur':%s ",a.auteur_liv.nom_aut);
                 printf("\n\xB2 Prenom de l'auteur':%s ",a.auteur_liv.prenom_aut);
                findbook='t';
            }

        }
        if(findbook!='t')  //checks whether conditiion enters inside loop or not
        {
            gotoxy(20,8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,9);
            printf("\xB2");
            gotoxy(38,9);
            printf("\xB2");
            gotoxy(20,10);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22,9);
            printf("\aPas de livre");
        }
        gotoxy(20,17);
        printf("essayer une autre?(Y/N)");
        if(getch()=='y')
            rechercher_livre();
        else
            menu_principal();


    //}
    fclose(fp);
}
void afficher_livre(void)  //show the list of book persists in library
{
    int i=0,j;
    system("cls");
    system("color FC");

    gotoxy(1,1);
     printf("*********************************liste des livres*****************************");
    gotoxy(2,2);
    printf(" CATEGORIE     NUMERO    TITRE     NOM_AUT       PRENOM_AUT       EMPRUNTEUR_LIV  ");
    j=4;
    fp=fopen("Livre.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%s",a.cat);
        gotoxy(16,j);
        printf("   %d",a.num_liv);
        gotoxy(24,j);
        printf(" %s\t\t",a.titre_liv);
        gotoxy(36,j);
        printf("  %s\t\t",a.auteur_liv.nom_aut);
        //printf("\n");
        printf("  \t\t%d",a.emprunteur_liv);
        gotoxy(50,j);
         printf("   %s\t\t",a.auteur_liv.prenom_aut);
        gotoxy(57,j);

        j++;
        i=i++;
    }
    gotoxy(3,25);
    fclose(fp);
    gotoxy(35,25);
    returnfunc();


}
void modifier_livre(void)  //edit information about book
{
    system("cls");
    system("color FC");

    int c=0;
    int d,e;
    gotoxy(20,4);
    printf("****modification du livre****");
    char another='y';
    while(another=='y')
    {
        system("cls");
        system("color FC");

        gotoxy(15,6);
        printf("\xB2 entrez le numero du livre a modifier:");
        scanf("%d",&d);
        fp=fopen("Livre.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {

                printf("\n\t\t le livre est disponible !!");
                printf("\n\xB2 entrer le nouveau titre:");
                scanf("%s",a.titre_liv);
                printf("\n\xB2 entrer le nouveau nom auteur:");
                scanf("%s",a.auteur_liv.nom_aut);
                printf("\n\xB2 entrer le nouveau prenom auteur:");
                scanf("%s",a.auteur_liv.prenom_aut);
                printf("Modifie avec succes!!");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(15,9);
                printf("pas de livre avec le numero insere ");
            }
        }
        gotoxy(15,16);
        printf("Modifier un autre livre?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
    returnfunc();
}

int modifier_livre_1(int livre , int emprenteur)  //edit information about book
{
    system("cls");
    system("color FC");

    int c=0;
    int d,e;
    gotoxy(20,4);

        f_adh=fopen("adherent.dat","rb+");
        if (checkid_adh(emprenteur) == 0) {
            if (adh.nbre_emprunts_adh < 3) {
                adh.nbre_emprunts_adh = adh.nbre_emprunts_adh + 1;
                fseek(f_adh,ftell(f_adh)-sizeof(adh),0);
                fwrite(&adh,sizeof(adh),1,f_adh);
                fclose(f_adh);
                c = 1;
            }
        }
        if (c == 1) {
            fp=fopen("Livre.dat","rb+");
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(checkid(livre)==0)
                {
                    a.emprunteur_liv = emprenteur;
                    fseek(fp,ftell(fp)-sizeof(a),0);
                    fwrite(&a,sizeof(a),1,fp);
                    fclose(fp);
                    c=1;
                }
            }
        }
    faire_pause_empr();
}

int getdata()
{
    int t;
    gotoxy(20,3);
    printf("Entrez les informations suivantes");
    printf("\n\t\tCategory:");
    printf("%s",catagories[s-1]);
    printf("\n\n\t\tNumero de livre:\t");
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aLe numero deja existant\a");
        getch();
        menu_principal();
        return 0;
    }
    a.num_liv=t;
    printf("\n\t\tTitre:");
    scanf("%s",a.titre_liv);
    printf("\n\t\tAuteur nom:");
    scanf("%s",a.auteur_liv.nom_aut);
    printf("\n\t\tAuteur prenom:");
    scanf("%s",a.auteur_liv.prenom_aut);
    a.emprunteur_liv = 0;

    return 1;
}


int checkid(int t)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.num_liv==t)
            return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}
int t(void) //for time
{
    time_t t;
    time(&t);
    printf("Date et heure :%s\n",ctime(&t));

    return 0 ;
}

void Password(void) //for password option
{

    system("cls");
    system("color 4F");
    char d[29]="TAPEZ LE CODE";
    char ch,pass[10];
    int i=0,j;
//textbackground(WHITE);
//textcolor(RED);
    gotoxy(10,4);
    for(j=0; j<20; j++)
    {
        Sleep(20);
        printf("*");
    }
    for(j=0; j<20; j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }
    for(j=0; j<20; j++)
    {
        Sleep(50);
        printf("*");
    }
    gotoxy(10,10);
    gotoxy(15,7);
    printf("Entrer mot de passe:");

    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {

        gotoxy(15,9);

        printf("MOT DE PASSE CORRECT");
        sleep(1);
        gotoxy(17,10);

        //menu_principal

        afficher_menu();
    }
    else
    {
        gotoxy(15,16);
        printf("\a Attention! MOT DE PASSE INCORRECT");
        sleep(2);
        Password();
    }
}

/*void issuerecord()  //display issued book's information
{
    system("cls");
    gotoxy(10,8);
    printf("The Book has taken by Mr. %s",a.stname);
    gotoxy(10,9);
    /*printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
    gotoxy(10,10);
    printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}
*/
///////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////

void ajouter_adherent(void)    //funtion that add books
{
    system("cls");
    int i;
    f_adh=fopen("adherent.dat","ab+");
    //+++++++++++++++++++++++++++++++++++++++++++++++
    if(getdata_adh()==1)
    {
        //a.cat=catagories[s-1];
        fseek(f_adh,0,SEEK_END);
        fwrite(&adh,sizeof(adh),1,f_adh);
        fclose(f_adh);
        gotoxy(21,14);
        printf("adherent ajoute avec succes");
        gotoxy(21,15);
        printf("Ajouter un de plus ? (y/n):");
        if(getch()=='n')
            menu_principal_adh();
        else
            system("cls");
        ajouter_adherent();
    }
}
void supprimer_adherent()    //function that delete items from file fp
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
        system("cls");
        gotoxy(10,5);
        printf("entrer le numero adherent a supprimer :");
        scanf("%d",&d);
        f_adh=fopen("adherent.dat","rb+");
        rewind(f_adh);
        while(fread(&adh,sizeof(adh),1,f_adh)==1)
        {
            if(adh.num_adh==d)
            {

                gotoxy(10,7);
                printf("adherent trouve :");
                gotoxy(10,8);
                printf("Nom adherent %s %s",adh.nom_adh, adh.prenom_adh);
                findbook='t';
            }
        }
        if(findbook!='t')
        {
            gotoxy(10,10);
            printf("Aucun adherent avec ce numero ");
            if(getch())
                menu_principal_adh();
        }
        if(findbook=='t' )
        {
            gotoxy(10,9);
            printf("Etes vous sur de vouloir supprimer ?(Y/N):");
            if(getch()=='y')
            {
                ft=fopen("test.dat","wb+");  //temporary file for delete
                rewind(f_adh);
                while(fread(&adh,sizeof(adh),1,f_adh)==1)
                {
                    if(adh.num_adh!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&adh,sizeof(adh),1,ft); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(ft);
                fclose(f_adh);
                remove("adherent.dat");
                rename("test.dat","adherent.dat"); //copy all item from temporary file to fp except that
                f_adh=fopen("adherent.dat","rb+");    //we want to delete
                if(findbook=='t')
                {
                    gotoxy(10,10);
                    printf("adherent supprime");
                    gotoxy(10,11);
                    printf("Supprimer un autre ?(Y/N)");
                }
            }
            else
                menu_principal_adh();
            fclose(f_adh);
            fflush(stdin);

            another=getch();
        }
    }
    gotoxy(10,15);
    menu_principal_adh();
}
void rechercher_adherent()
{
    system("cls");
    printf("\n*****************************Recherche Adherent********************************* \n");

    f_adh=fopen("adherent.dat","rb+"); //open file for reading propose
    rewind(f_adh);   //move pointer at the begining of file

        int s;

        printf("Entrer le nom de l'adherent a chercher : \n");
        scanf("%d",&s);
        printf("*********************************Liste adherent ***************************** \n");
        printf("Identifiant            nom                           prenom                        Email                         Adresse                       nbr emprente\n");
        int d=0, j =6;
        while(fread(&adh,sizeof(adh),1,f_adh)==1)
        {

            if(adh.num_adh == s) //checks whether a.name is equal to s or not
            {
                gotoxy(1,j);
                printf("%d",adh.num_adh);
                gotoxy(23,j);
                printf("%s",adh.nom_adh);
                gotoxy(53,j);
                printf("%s",adh.prenom_adh);
                gotoxy(83,j);
                printf("%s",adh.email_adh);
                gotoxy(113,j);
                printf("%s",adh.adress_adh);
                gotoxy(143,j);
                printf("%d",adh.nbre_emprunts_adh);
                j++;
                d++;
            }

        }
        if(d==0)
        {

            printf(" \n Aucun adherent avec le nom entree !");
        }
        printf("\n Rechercher a nouveau ?(Y/N)");
        if(getch()=='y')
            rechercher_adherent();
        else
            menu_principal_adh();


    fclose(f_adh);
}

void afficher_adherent(void)  //show the list of book persists in library
{
    int i=0,j;
    system("cls");
    printf("*********************************Liste adherent ***************************** \n");
    printf("Numero            nom                           prenom                        Email                         Adresse                       nbr_liv_emp \n");
    j=4;
    f_adh=fopen("adherent.dat","rb");
    while(fread(&adh,sizeof(adh),1,f_adh)==1)
    {
        gotoxy(1,j);
        printf("%d",adh.num_adh);
        gotoxy(23,j);
        printf("%s",adh.nom_adh);
        gotoxy(53,j);
        printf("%s",adh.prenom_adh);
        gotoxy(83,j);
        printf("%s",adh.email_adh);
        gotoxy(113,j);
        printf("%s",adh.adress_adh);
        gotoxy(143,j);
        printf("%d",adh.nbre_emprunts_adh);

        j++;
        i++;
    }
    gotoxy(3,25);
    printf("Nombre d'adherent  =%d",i);
    fclose(f_adh);
    gotoxy(35,25);
    faire_pause();
}
void modifier_adherent(void)  //edit information about book
{
    system("cls");
    int c=0;
    int d,e;
    gotoxy(20,4);
    printf("****Modifier adherent **** \n");
    char another='y';
    while(another=='y')
    {
        system("cls");
        printf("\n\t\tEntrer l'identifiant de l'adherent a modifier : \t");
        scanf("%d",&d);
        f_adh=fopen("adherent.dat","rb+");
        while(fread(&adh,sizeof(adh),1,f_adh)==1)
        {
            if(checkid_adh(d)==0)
            {
                printf("\n\tAdherent valide !!\n \t");
                printf("\n\tEntrer le nom:");
                scanf("%s",adh.nom_adh);
                printf("\n\tEntrer prenom :");
                scanf("%s",adh.prenom_adh);
                printf("\n\tEntrer email :");
                scanf("%s",adh.email_adh);
                printf("\n\tentrer Adresse :");
                scanf("%s",adh.adress_adh);
                printf("\n\tadherent modifie !! \n");
                fseek(f_adh,ftell(f_adh)-sizeof(adh),0);
                fwrite(&adh,sizeof(adh),1,f_adh);
                fclose(f_adh);
                c=1;
            }

        }
        if(c==0)
            {
                gotoxy(15,9);
                printf("Aucun adherent avec le numero entre \n");
            }
        gotoxy(15,16);
        printf("Modifier un autre ?(Y/N)\n");
        fflush(stdin);
        another=getch() ;
    }
    faire_pause();
}
void faire_pause(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
a:
    if(getch()==13) //allow only use of enter
        menu_principal_adh();
    else
        goto a;
}
void faire_pause_empr(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
a:
    if(getch()==13) //allow only use of enter
        emprunter_livre();
    else
        goto a;
}
int getdata_adh()
{
    int t,i;

    printf("entrer les informations de l'adherent \n");

    printf("\nle numero de adherent :\t");
    scanf("%d",&t);

    //+++++++++++++++++++++++++++++++++++
    if(checkid_adh(t) == 0)
    {
            system("cls");
printf("Un adherent existant deja avec ce numero, veuillez saisir un autre numero \a \n");

        return getdata_adh();
    }
    adh.num_adh = t;

    printf("Nom adherent :");
    scanf("%s",adh.nom_adh);
     for (i = 0; adh.nom_adh[i]!='\0'; i++)
{ if(adh.nom_adh[i] >= 'a' && adh.nom_adh[i] <= 'z') {adh.nom_adh[i] = adh.nom_adh[i] -32;}}
    printf("Prenom adherent :");
    scanf("%s",adh.prenom_adh);
    printf("email adherent :");
    scanf("%s",adh.email_adh);
    printf("Adresse adherent :");
    scanf("%s",adh.adress_adh);
    adh.nbre_emprunts_adh = 0;
    return 1;
}
int checkid_adh(int t)  //check whether the book is exist in library or not
{
    rewind(f_adh);
    while(fread(&adh,sizeof(adh),1,f_adh)==1)
        if(adh.num_adh ==t)
            return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}
void ordonner_livre()
{
    system("cls");
    printf("\n*****************************Ordonner livre********************************* \n");
       fp=fopen("Livre.dat","rb+"); //open file for reading propose
       rewind(fp);   //move pointer at the begining of file

        char s[30];
        int i;

        printf("Entrer la categorie souhaite: \n");
        scanf("%s",s);
      
        printf("*********************************Liste des livres ***************************** \n");
        printf("Numero            Titre                        nom_aut                       Prenom_aut  \n");
        int d=0, j =6;
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.cat,(s))==0) //checks whether a.name is equal to s or not
            {
                gotoxy(1,j);
                printf("%d",a.num_liv);
                gotoxy(23,j);
                printf("%s",a.titre_liv);
                gotoxy(53,j);
                printf("%s",a.auteur_liv.nom_aut);
                gotoxy(83,j);
                printf("%s",a.auteur_liv.prenom_aut);
                gotoxy(113,j);
                j++;
                d++;
            }

        }
        if(d==0)
        {

            printf(" \n Aucun livre dans cette categorie !");
        }
        printf("\n choisir une autre categorie ?(Y/N)");
        if(getch()=='y')
            rechercher_livre();
        else
            menu_principal();


    fclose(fp);
}

//End of program


