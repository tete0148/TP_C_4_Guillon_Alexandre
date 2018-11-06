#include<stdio.h>

typedef struct couleur couleur;
typedef struct liste_couleurs liste_couleurs;

struct couleur {
// Remplissez ça pour gérer une liste (simplement chainée) decouleurs.

   unsigned char R;
   unsigned char G;
   unsigned char B;
   unsigned char A;
   couleur *suivant;
   couleur *precedent;
};



struct liste_couleurs
{
    struct couleur *lastElement;
    struct couleur *firstElement;
};



void insertion (struct liste_couleurs *,struct couleur *);
void parcours (struct liste_couleurs *);

