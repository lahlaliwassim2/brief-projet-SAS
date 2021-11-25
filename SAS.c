#include <stdio.h>
#include <stdbool.h>
#include <string.h>

      //////////////////////-----------------STRUCTURES-------------///////////////////////////////
     /////////////////----------------- les donnes de clien----/////////////////////////////////////
struct client
{
         	    char cin[10]; 			
	      	 	char nom[20];
	            char prenom[20];
	            float montant;
};
////////////////////////////--------declaration de tableau---------//////////////////////////////////////////////
struct client Tab[100];
                int comptes = 0;

/////////////////////////-------------fonction :creation de compte--------------/////////////////////////
int crationcpt(int n){
  	
	           int i ;

	for (i = 0 ; i < n; i++)
	{               //////////////////compteur avec la boucle for
		  printf("Veilez entrer votre nom : ");
		  scanf("%s", Tab[i].nom);
		  
		  printf("Veillez entrer votre prenom : ");
		  scanf("%s", Tab[i].prenom);


		  printf("Confirmer avec votre CIN : ");
		  scanf("%s", Tab[i].cin);

	     
		  printf(" Veillez entrer le montant : ");
		  scanf("%f", &Tab[i].montant);
		  
  	      printf("bien,vous avez creer votre compte correctement!!\n");
	                     	////////// incrimentation de creation de compte///////
	comptes++;                     
	}

	return 1;
}
//////////////////////////----------fonction pour vider le consol---------------//////////////
void cleanCls(){
	system("cls||clear");
}

///////////////////////////////------fonction:les operations a efectuer-----////////////////////////
bool operations()
{
	int _choix, i;
	char cin[10];
	float solde;

	printf("Entrer le CIN du client : ");
	scanf("%s", cin);

	cleanCls();
	do {
	            printf("\n\n\n\n\n\n");
	          	printf("1-->. Depot \n \n \n");
		        printf("2-->Retrait \n \n \n");
		        printf("00--> Menu principale \n");
		        printf("Entrer un choix : ");
		        scanf("%d", &_choix);

		switch (_choix) {
			   case 1 :
			   	
			                    	cleanCls();                       ////////////////////----vider le consol---------////////      
			       for(i = 0; i < comptes; i++)
				    {
						if (strcmp(cin, Tab[i].cin) == 0)
						 {          ////////// recherche de compte client  a laide de la CIN
				          printf("Entrer la valeur de depot : ");
			              scanf("%f", &solde);
							           /////////////////// relation depot
                          Tab[i].montant += solde;
                                        //////////////////affichage resultat
							printf("Le montant est : %g", Tab[i].montant);
						}
					}
		    	break;
			   case 2 :
				cleanCls();                   ////////////vider le consol 
			       for(i = 0; i < comptes; i++)
				   {
				      	if (strcmp(cin, Tab[i].cin) == 0) 
					   {  
							printf("Entrer la valeur de retrait : ");
							scanf("%f", &solde);
					    if (Tab[i].montant >= solde)
				                         	  /////////////relation de retrait
								Tab[i].montant -= solde;         
				      	else
							printf("Votre solde est inferieur à %g \n", solde);
							printf("Le montant est : %g \n \n \n", Tab[i].montant);
						}
			    	}
		    	break;
			   default :
			                printf("Votre choix n exist pas \n");
		}
	}
	while (_choix  != 0);
	
                         	cleanCls();
}
////////////////////////////////////////----------------------affichage---------------------------////////////////////////////////////////////////////// 

void afichage(){

   int choix1, choix2;
    int  i, j;
    struct client vraide;
	
	    do {
        printf("\t  1--> trier par montant \n \n \n");
        printf("\t  2--> trier par nom \n \n \n");
        printf("\t 3--> chercher par CIN \n \n \n");
        printf("\t  0 Main Menu \n \n \n");
        printf("taper votre choix : \n");
        scanf("%d", &choix1);

        switch (choix1) {
       case 1 :
                printf("\t  1: Ascend \n \n \n");
                printf("\t 2 :Descend \n \n \n");
                printf("taper votre choix : ");
                scanf("%d", &choix2);
         switch (choix2) {
           case 1 :
                printf("//////////////////// MONTANT ASENDANT\\\\\\\\\\\\\\\\\\\\\\\\ \n");
                        struct client vraide;
                        for(i = 0 ; i < comptes ; i++)
                        {
                            for(j = 0 ; j < comptes-i-1 ; j++)
                            {
                                if(Tab[j].montant > Tab[j+1].montant)
                                {
                                    vraide = Tab[j+1];
                                    Tab[j+1]=Tab[j];
                                    Tab[j]=vraide;
                                }
                            }
                        }
                        for (i = 0 ; i < comptes; i++) {
                            printf("%s \t %s \t %s \t %g \n", Tab[i].nom, Tab[i].prenom, Tab[i].cin, Tab[i].montant);
                        }
                        break;
                   case 2 :
                        printf(" ///////////////////MONTANT DESENDENT \n");
                        
                        for(i = 0 ; i < comptes ; i++)
                        {
                            for(j = 0 ; j < comptes-i-1 ; j++)
                            {
                                if(Tab[j].montant < Tab[j+1].montant)
                                {
                                    vraide = Tab[j+1];
                                    Tab[j+1]=Tab[j];
                                    Tab[j]=vraide;
                                }
                            }
                        }
                        for (i = 0 ; i < comptes ; i++) {
                            printf("%s \t %s \t %s \t %g \n", Tab[i].nom, Tab[i].prenom, Tab[i].cin, Tab[i].montant);
                        }
                        break;
                    }
          }
          
}while(choix1 !=0);

}
//////////////////////---------------FONCTION PRINCIPALE
int main(){
	             int choix, nbrNewAccount, i;
	             char data[50], cin[10];



/////////////////////------------------MENU----------////////////////////
	do {
	               	printf("\n\n\n\n\n\n");
	               	printf("\t\t\t\t\t***********************\n");
		            printf("\t\t\t\t\t bienvenu chez ycdbank\t\t\t");
		            printf("\t\t\t\t\t\t\t\t\t***********************\n");
		            printf("\n\n\n");
		            printf(" 1.--->Introduction de  compte                             2.---> Introduction de plusieurs comptes\n\n\n\n " );
	              	printf(" 3.---> Operations a effectuer                             4.---> Consultation \n\n\n\n");
		            printf(" 5.---> Fidelisation                                        0.---> Quitter \n\n\n\n");
		            printf("\t\t\t\t Entrer votre choix : ");
		            scanf("%d", &choix);

	      switch (choix)
  {
		   	case 1 :
			                	cleanCls();
	     	  if(crationcpt(1))
			 {
					printf("felicitation!!!! ");
			 }  
			  else
		    {
					printf("Erreur !");	    
	     	}
				break;
			case 2 :
				printf("Entrer le nombre des comptes que vous voulez cree : ");
				scanf("%d", &nbrNewAccount);
				crationcpt(nbrNewAccount);
				break;
			case 3 :
				operations();
				break;
			case 4 :
				cleanCls();
				afichage();
				break;
			case 6 :
				cleanCls();
				break;
	}


	   }    
	   while(choix != 0);


	return 0;
}

