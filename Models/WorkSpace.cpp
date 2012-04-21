#include "WorkSpace.h"
#include <cstdlib>

WorkSpace::WorkSpace(string name, string parentPath):Element(name, parentPath){
	projects = vector<Project>();
}

WorkSpace::~WorkSpace(){
    projects.clear();
}
void WorkSpace::clear(){
    for (int i = 0; i < projects.size(); i++){
        projects[i].clear();
    }
    delete qItem;
}

void WorkSpace::addProject(Project *project){
    projects.push_back(*project);
}
void WorkSpace::scan(){
	DIR* workSpaceDir;
        struct dirent* readFile;
	string sPath;
	char* wPath;
	size_t wPathSize;
	struct stat infosFichier;

	//Conversion string vers char* pour pouvoir executer les appels systeme
	sPath = this->getPath();
	wPathSize = sPath.size() +1;
	wPath = new char[ wPathSize ];
	strncpy(wPath, sPath.c_str(), wPathSize);

	workSpaceDir = opendir(wPath);//On ouvre le repertoire du workspace
	if (workSpaceDir == NULL){//Si erreur
		perror("Error: ");
	}
	else{
                FILE* projectFile = NULL;
                char* folderPath = NULL;
                char* proPath = NULL;
                size_t folderPathSize = 512;
                folderPath = (char*)malloc(folderPathSize * sizeof(char));
                while ((readFile = readdir(workSpaceDir)) != NULL){//On parcourt les éléments du workspace
                        if(strcmp(readFile->d_name, ".") && strcmp(readFile->d_name, "..")){//On évite . et ..
				//Bloc de création du path de l'élément

				strcpy(folderPath, wPath);
				strcat(folderPath, "/");
                                strcat(folderPath, readFile->d_name);
				
				if (! lstat(folderPath, &infosFichier)){//récupération des infos du fichier
					if(S_IFDIR & infosFichier.st_mode){//Si c'est un répertoire
                                                //Bloc de création du path du .pro
						proPath = (char*)malloc(strlen(folderPath) + sizeof("/.pro") + 1);
						strcpy(proPath, folderPath);
						strcat(proPath, "/.pro");
                                                projectFile = fopen(proPath, "r");// On tente l'ouverture
						if(projectFile){//S'il existe
							//Création d'un nouveau projet
                                                        Project project = Project(readFile->d_name, this->getPath());
                                                        project.scan();
                                                        project.sort();
							projects.push_back(project);//Ajout du projet au vecteur
						} else {
                                                        cout << "Pas de .pro dans " << readFile->d_name << endl;
						}
                                        }
				}
			}
		}
                if (projectFile){
                    fclose(projectFile);
                }
                free(folderPath);
                free(proPath);
	}
        closedir(workSpaceDir);
        delete readFile;
        delete[] wPath;
}

void WorkSpace::sort(){
	std::sort(projects.begin(),projects.end());
}

void WorkSpace::output(int prof){
	Element::output(prof);
        for(size_t i = 0; i < projects.size(); i++){
		projects[i].output(prof + 1);
	}
}

QStandardItem* WorkSpace::getQItem(){
    for(size_t i = 0; i < projects.size(); i++){
        qItem->appendRow(projects[i].getQItem());
    }
    return qItem;
}

Element* WorkSpace::getElement(list<int> *accessList){
    if (accessList->size() == 1){
        return &projects[accessList->front()];
    }
    else{
        int projectNumber = accessList->front();
        accessList->pop_front();
        return projects[projectNumber].getElement(accessList);
    }
}

void WorkSpace::dropElement(int position){
    if((size_t)position < projects.size() && position >= 0){
        projects[position].deleteElement();
        projects.erase(projects.begin() + position);
    }
}
int WorkSpace::findProjectPosition(string projectName){
    size_t i = 0;
    while(i < projects.size() && projects[i].getName() != projectName){
        i++;
    }
    if (i == projects.size())
        return -1;
    else
        return i;
}
int WorkSpace::newProject(string projectName){
    string projectPath = this->getPath() + '/' + projectName;
    if (mkdir(projectPath.c_str(), 0777) == -1){
        cerr << "erreur de création du dossier" << endl;
        return -1;
    }
    ofstream file;
    string filePath = projectPath + '/' + ".pro";
    file.open(filePath.c_str(), ios::out);
    if(file.bad()){
        cerr << "Erreur d'ouverture du fichier" << endl;
        return -1;
    }
    return 0;
}

int WorkSpace::getType(){
    return WORKSPACE_TYPE;
}

void WorkSpace::deleteElement(){}

int WorkSpace::renameElement(int elementPosition, string newName){
    if(findProjectPosition(newName) != -1){
        return -1;
    }
    int renamingResult = 0;
    if((size_t) elementPosition < projects.size()){
        string oldPath = projects[elementPosition].getPath();
        string newPath = this->getPath() + "/" + newName;
        renamingResult = rename(oldPath.c_str(), newPath.c_str());
        if(renamingResult == 0){
            projects[elementPosition].setName(newName);
            projects[elementPosition].setQItemName(newName);
            this->sort();
        }
    }
    return renamingResult;
}
