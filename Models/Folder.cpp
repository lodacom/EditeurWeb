#include "Folder.h"

Folder::Folder(string name, string parentPath):Element(name, parentPath){
    folders = vector<Folder>();
    files = vector<File>();
    qItem->setIcon(*Tools::projectIcon);
}

Folder::~Folder(){
    files.clear();
    folders.clear();
}
void Folder::clear(){
    for (int i = 0; i < files.size(); i++){
        files[i].clear();
    }
    for (int i = 0; i < folders.size(); i++){
        folders[i].clear();
    }
    delete qItem;
}

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
void Folder::setName(string name){
    this->name = name;
    for(size_t i = 0; i < folders.size(); i++){
        folders[i].setParentPath(this->getPath());
    }
    for(size_t i = 0; i <files.size(); i++){
        files[i].setParentPath(this->getPath());
    }
}
void Folder::setParentPath(string parentPath){
    this->parentPath = parentPath;
    for(size_t i = 0; i < folders.size(); i++){
        folders[i].setParentPath(this->getPath());
    }
    for(size_t i = 0; i <files.size(); i++){
        files[i].setParentPath(this->getPath());
    }
}

void Folder::scan(){
    DIR* currentDirectory;
    struct dirent* readFile;
    string sPath;
    char *cPath, *temp = NULL;
    size_t cPathSize, tempSize = 512;
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
        temp = (char*)malloc(tempSize * sizeof(char));
        while((readFile = readdir(currentDirectory)) != NULL){//Parcours des fichiers du répertoire
            //Bloc de création du chemin du fichier parcouru
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

    delete readFile;
    delete[] cPath;
    free(temp);
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

QStandardItem* Folder::getQItem(int i){
    if(i == 0){
        for(size_t i = 0; i < folders.size(); i++){
            qItem->appendRow(folders[i].getQItem());
        }
        for(size_t i = 0; i < files.size(); i++){
            qItem->appendRow(files[i].getQItem());
        }
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

//Folder* Folder::getFolder(list<int>* accessList){
//    if (accessList->size() == 1){
//        if (accessList->front() < (int)folders.size()){
//            return &folders[accessList->front()];
//        }
////        else
////            return NULL;
//    }
//    else{
//        int folderNumber = accessList->front();
//        accessList->pop_front();
//        return folders[folderNumber].getFolder(accessList);
//    }
//}

File Folder::getFileByPosition(int position){
    return files[position];
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

int Folder::newFile(string fileName,string content){
    if(findFilePosition(fileName) != -1){
        return -1;
    }
    ofstream file;
    string filePath = this->getPath() + '/' + fileName;
    file.open(filePath.c_str(), ios::out);
    if(file.bad()){
        cerr << "Erreur d'ouverture du fichier" << endl;
        return -1;
    }
    else{
        File *logicalFile = new File(fileName, this->getPath());
        if(!content.empty()){
            logicalFile->setContent(content);
        }
        this->addFile(logicalFile);
        this->sort();
        int position = findFilePosition(fileName);
        qItem->insertRow(position + folders.size(), logicalFile->getQItem());
    }
    file.close();
    return 0;
}

int Folder::newFolder(string folderName){
    string folderPath = this->getPath() + '/' + folderName;

    if (mkdir(folderPath.c_str(), 0777) == -1){
        cerr << "erreur de création du dossier" << endl;
        return -1;
    }
    else{
        Folder *logicalFolder = new Folder(folderName, this->getPath());
        this->addFolder(logicalFolder);
        this->sort();
        int position = findFolderPosition(folderName);
        qItem->insertRow(position, logicalFolder->getQItem());
        return 0;
    }
}
int Folder::findFilePosition(string fileName){
    size_t i = 0;
    while(i < files.size() && files[i].getName() != fileName){
        i++;
    }
    if (i == files.size())
        return -1;
    else
        return i;
}
int Folder::findFolderPosition(string folderName){
    size_t i = 0;
    while(i < folders.size() && folders[i].getName() != folderName){
        i++;
    }
    if (i == folders.size())
        return -1;
    else
        return i;
}

int Folder::renameElement(int elementPosition, string newName){
    if(findFolderPosition(newName) != -1 || findFilePosition(newName) != -1){
        return -1;
    }
    int newPosition = 0, renamingResult;
    if((size_t)elementPosition < folders.size()){
        string oldPath = folders[elementPosition].getPath();
        string newPath = this->getPath() + "/" + newName;
        renamingResult = rename(oldPath.c_str(), newPath.c_str());
        if(renamingResult == 0){
            folders[elementPosition].setName(newName);
            folders[elementPosition].setQItemName(newName);
            this->sort();
            newPosition = findFolderPosition(newName);
        }
    }
    else{
        string oldPath = files[elementPosition - folders.size()].getPath();
        string newPath = this->getPath() + "/" + newName;
        renamingResult = rename(oldPath.c_str(), newPath.c_str());
        if(renamingResult == 0){
            files[elementPosition - folders.size()].setName(newName);
            files[elementPosition - folders.size()].setQItemName(newName);
            this->sort();
            newPosition = findFilePosition(newName);
        }
    }
    qItem->insertRow(newPosition, qItem->takeRow(elementPosition));
    return renamingResult;
}
