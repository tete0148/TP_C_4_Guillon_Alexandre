void lire_dossier(char *);
void lire_dossier_recursif(char* rep_name, int tree_value);
void lire_dossier_iteratif(char *);
typedef struct File File;
struct File{
	struct dirent* data;
	File* next;
};
typedef struct List List;
struct List{
	File* first;
};
