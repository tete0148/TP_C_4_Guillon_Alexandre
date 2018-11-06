#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "repertoire.h"

List* initialisation(){
	List *list = malloc(sizeof(*list));
  File *file = malloc(sizeof(*file));
	struct dirent* data = malloc(sizeof(*data));
	 if (list == NULL || file == NULL)
	 {
			 exit(EXIT_FAILURE);
	 }
	 file->data=data;
	 file->next = NULL;
	 list->first = file;

	 return list;
}

void insertion(List* list, struct dirent* file){
	File* new = malloc(sizeof(*new));
	if(list==NULL || new == NULL){
		exit(EXIT_FAILURE);
	}
  if(file->d_type == DT_DIR){

	}
	else{
	new->data = file;
	new->next = list->first;
	list->first = new;
  }
}

void afficherListe(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    File *actual = list->first;

    while (actual != NULL)
    {
        printf("-%s\n", actual->data->d_name);
        actual = actual->next;
    }
}

void lire_dossier(char* rep_name){
	struct dirent* lecture;
        DIR *rep;
        rep = opendir(rep_name);
	printf("Contenu du repertoire \"%s\" :\n",rep_name);
        while ((lecture = readdir(rep))) {//On lit chaque fichier du repertoire
	    if(lecture->d_name[0]!='.'){//Permet de ne pas afficher les dossiers cachés
            	printf("	- %s\n", lecture->d_name);
	    }
        }
        closedir(rep);
}

void lire_dossier_recursif(char* rep_name, int tree_value){
	struct dirent* lecture;
	DIR *rep;
  rep = opendir(rep_name);
	tree_value++;//On incremente la valeur de l'arborescence a chaque fois qu'on parcourt un sous repertoire
  while ((lecture = readdir(rep))) { //On lit chaque fichier du repertoire
		if(lecture->d_name[0]!='.'){ //Permet de ne pas afficher les dossiers cachés
			int i;
			for(i=0;i<tree_value;i++){//Indente en fonction de l'arborescence du fichier
				printf("   ");
			}
		printf("- %s\n", lecture->d_name);
		if(lecture->d_type == DT_DIR){//Si le fichier est un sous-repertoire
			char* dir_path = (char *) malloc(2 + strlen(rep_name)+ strlen(lecture->d_name));
			strcpy(dir_path, rep_name);
			strcat(dir_path,"/");
			strcat(dir_path, lecture->d_name);//On stocke le chemin du sous-repertoire dans une variable et on rappelle la fonction de manière récursive
			lire_dossier_recursif(dir_path,tree_value);
		}
	    }
        }
        closedir(rep);
}

void lire_dossier_iteratif(char* rep_name){
	List* list = initialisation();
	struct dirent* lecture;
	DIR *rep;
	rep = opendir(rep_name);
	while ((lecture = readdir(rep))) {//On lit chaque fichier du repertoire
		 insertion(list, lecture);
	}
	afficherListe(list);
	closedir(rep);
}

int main(int argc, char* argv[]){
   (void) argc;
   //lire_dossier_recursif(argv[1],-1);//On commence à -1 pour que l'arborescence commence à 0 quand on commence la récursivité
	 lire_dossier_iteratif(argv[1]);
	 return 0;
}
