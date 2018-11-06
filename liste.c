#include<stdio.h>
#include<stdlib.h>
#include"liste.h"


void insertion (liste_couleurs* liste_couleurs,couleur* couleur){
   struct couleur* nouveau;
   nouveau = malloc(sizeof(couleur));
   	if(nouveau == NULL) exit(EXIT_FAILURE);
   nouveau->R = couleur->R;
   nouveau->G = couleur->G;
   nouveau->B = couleur->B;
   nouveau->A = couleur->A;
   nouveau->precedent = liste_couleurs->lastElement;
   nouveau->suivant = NULL;      
   	if(liste_couleurs->lastElement) liste_couleurs->lastElement->suivant = nouveau;
   	else liste_couleurs->firstElement = nouveau;
   liste_couleurs->lastElement = nouveau;

}

void parcours (liste_couleurs *liste_couleurs ){
	couleur *c= liste_couleurs->firstElement;
	if(liste_couleurs->firstElement==NULL || liste_couleurs->lastElement==NULL){
		puts("Il n'y a pas d'élément dans ta liste");
	}
	else{
		while(c != NULL){
		printf("R : %u | G : %u | B : %u | A : %u \n",c->R,c->G,c->B,c->A);	
		c= c->suivant;
		}
	}
}

int main(){
liste_couleurs* liste=malloc(sizeof(liste_couleurs));
liste->firstElement=NULL;
liste->lastElement=NULL;
couleur tab[10]={{0xef,0x78,0xA0,0xff,NULL,NULL},{0xF2,0x61,0x69,0xff,NULL,NULL},{0x45,0x65,0xB0,0xff,NULL,NULL},{0x78,0x01,0x69,0xff,NULL,NULL},{0xff,0xff,0xff,0xff,NULL,NULL},{0xef,0x78,0xA0,0xff,NULL,NULL},{0xef,0x78,0xA0,0xff,NULL,NULL},{0xef,0x78,0xA0,0xff,NULL,NULL},{0xef,0x78,0xA0,0xff,NULL,NULL},{0xef,0x78,0xA0,0xff,NULL,NULL}};
insertion(liste,&tab[0]);
insertion(liste,&tab[1]);
insertion(liste,&tab[2]);
insertion(liste,&tab[3]);
insertion(liste,&tab[4]);
insertion(liste,&tab[5]);
insertion(liste,&tab[6]);
insertion(liste,&tab[7]);
insertion(liste,&tab[8]);
insertion(liste,&tab[9]);
parcours(liste);
return 0;
}
