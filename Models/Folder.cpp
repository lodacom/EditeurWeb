#include "Folder.h"

Folder::Folder(string name, string parentPath){
    this->name = name;
    this->parentPath = parentPath;
    folders = vector<Folder>();
    files = vector<File>();
}

Folder::~Folder(){}

bool Folder::isEmpty(){
    if(files.empty() && folders.empty())
	return true;
    else
	return false;
}


void Folder::sort(){
	std::sort(files.begin(), files.end());
	std::sort(folders.begin(), folders.end());
}
void Folder::addFile(File *file){
    files.push_back(*file);
}

void Folder::addFolder(Folder *folder){
    folders.push_back(*folder);
}

void Folder::scan(){
    DIR* currentDirectory;
    struct dirent* readedFile;
    string sPath;
    char *cPath, *temp;
    size_t cPathSize;
    struct stat infosFichier;

    //Bloc de conversion string vers char* pour la compatibilité avec les appels systeme
    sPath = this->getPath();
    cPathSize = sPath.size() + 1;
    cPath = new char[ cPathSize ];
    strncpy(cPath, sPath.c_str(), cPathSize);
    //On ouvre le dossier
    currentDirectory = opendir(cPath);
    if (currentDirectory == NULL){//Si erreur
	perror("Error: ");
    }
    else{
	Folder newFolder;
	File newFile;
	while((readedFile = readdir(currentDirectory)) != NULL){//Parcours des fichiers du répertoire
	    //Bloc de création du chemin du fichier parcourru
	    temp = (char*)malloc(strlen(cPath) + sizeof(readedFile->d_name) + 1);
	    strcpy(temp, cPath);
	    strcat(temp, "/");
	    strcat(temp, readedFile->d_name);

	    if (! lstat(temp, &infosFichier)){//Récupération des infos du fichiers
		if(strcmp(readedFile->d_name, ".") && strcmp(readedFile->d_name, "..")){//On évite les dossiers "." et ".."	
		    if(S_IFDIR & infosFichier.st_mode){//Si le fichier est un répertoire
			//On crée un nouveau dossier
			newFolder = Folder(string(readedFile->d_name), this->getPath());
			newFolder.scan();//On le scanne (ce qui permet de lister en profondeur les ss dossiers/fichiers)
			newFolder.sort();//Tri du dossier
                        folders.push_back(newFolder);//Ajout du dossier au vecteur
		    }
		    else {//Si ce n'est pas un répertoire
			newFile = File(string(readedFile->d_name), this->getPath());//On crée un nveau fichier
                        files.push_back(newFile);//On l'ajoute au répertoire
		    }
		}
	    }
	}
    }
    //libération de l'espace mémoire
    delete [] cPath;
    delete readedFile;
    delete temp;
    closedir(currentDirectory);
}

void Folder::output(int prof){
    Element::output(prof);
    for(int i = 0; i < files.size(); i++){
	files[i].output(prof + 1);	
    }
    for(int i = 0; i < folders.size(); i++){
	folders[i].output(prof + 1);
    }
}
