#include "Folder.h"

Folder::Folder(string name, string parentPath):Element(name, parentPath){
    folders = vector<Folder>();
    files = vector<File>();
    qItem->setIcon(QIcon("Pics/Folder-icon.png"));
}

Folder::~Folder(){}

bool Folder::isEmpty(){
    if(files.empty() && folders.empty())
	return true;
    else
	return false;
}


void Folder::sort(){
	std::sort(folders.begin(), folders.end());
        std::sort(files.begin(), files.end());
}
void Folder::addFile(File *file){
    files.push_back(*file);
}

void Folder::addFolder(Folder *folder){
    folders.push_back(*folder);
}

void Folder::scan(){
    DIR* currentDirectory;
    struct dirent* readFile;
    string sPath;
    char *cPath, *temp = NULL;
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
        while((readFile = readdir(currentDirectory)) != NULL){//Parcours des fichiers du répertoire
	    //Bloc de création du chemin du fichier parcourru
            temp = (char*)malloc(strlen(cPath) + sizeof(readFile->d_name) + 1);
	    strcpy(temp, cPath);
	    strcat(temp, "/");
            strcat(temp, readFile->d_name);

	    if (! lstat(temp, &infosFichier)){//Récupération des infos du fichiers
                if(strcmp(readFile->d_name, ".") && strcmp(readFile->d_name, "..")){//On évite les dossiers "." et ".."
		    if(S_IFDIR & infosFichier.st_mode){//Si le fichier est un répertoire
			//On crée un nouveau dossier
                        newFolder = Folder(string(readFile->d_name), this->getPath());
			newFolder.scan();//On le scanne (ce qui permet de lister en profondeur les ss dossiers/fichiers)
			newFolder.sort();//Tri du dossier
                        folders.push_back(newFolder);//Ajout du dossier au vecteur
		    }
		    else {//Si ce n'est pas un répertoire
                        newFile = File(string(readFile->d_name), this->getPath());//On crée un nveau fichier
                        files.push_back(newFile);//On l'ajoute au répertoire
		    }
		}
	    }
	}
    }
    //libération de l'espace mémoire
    delete [] cPath;
    delete readFile;
    delete temp;
    closedir(currentDirectory);
}

void Folder::output(int prof){
    Element::output(prof);
    for(size_t i = 0; i < files.size(); i++){
	files[i].output(prof + 1);	
    }
    for(size_t i = 0; i < folders.size(); i++){
	folders[i].output(prof + 1);
    }
}

QStandardItem* Folder::getQItem(){
    for(size_t i = 0; i < folders.size(); i++){
        qItem->appendRow(folders[i].getQItem());
    }
    for(size_t i = 0; i < files.size(); i++){
        qItem->appendRow(files[i].getQItem());
    }
    return qItem;
}

Element* Folder::getElement(list<int>* accessList){
    if (accessList->size() == 1){
        if (accessList->front() < (int)folders.size()){
            return &folders[accessList->front()];
        }
        else
            return &files[accessList->front() - folders.size()];
    }
    else{
        int folderNumber = accessList->front();
        accessList->pop_front();
        return folders[folderNumber].getElement(accessList);
    }
}

int Folder::getType(){
    return FOLDER_TYPE;
}

void Folder::deleteElement(){
        for(size_t i=0; i < folders.size(); i++){
            folders[i].deleteElement();
        }
        for(size_t i=0; i <files.size();i++){
            files[i].deleteElement();
        }
        qItem->parent()->removeRow(qItem->row());
        remove(this->getPath().c_str());
}

void Folder::dropElement(int position){
    if ((size_t)position < folders.size() + files.size() && position >= 0){
        if ((size_t)position<folders.size()){
            folders[position].deleteElement();
            folders.erase(folders.begin() + position);
        }
        else{
            files[position - folders.size()].deleteElement();
            files.erase(files.begin() + (position - folders.size()));
        }
    }
}
