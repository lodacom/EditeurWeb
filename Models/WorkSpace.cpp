#include "WorkSpace.h"
#include <cstdlib>

WorkSpace::WorkSpace(string name, string parentPath):Element(name, parentPath){
	projects = vector<Project>();
}

WorkSpace::~WorkSpace(){

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

                while ((readFile = readdir(workSpaceDir)) != NULL){//On parcourt les éléments du workspace
                        if(strcmp(readFile->d_name, ".") && strcmp(readFile->d_name, "..")){//On évite . et ..
				//Bloc de création du path de l'élément
                                folderPath = (char*)malloc(strlen(wPath) + sizeof(readFile->d_name) + 2);
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

		delete [] folderPath;
		delete [] proPath;
	}
        closedir(workSpaceDir);
        delete readFile;
	delete wPath;
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

int WorkSpace::getType(){
    return WORKSPACE_TYPE;
}

void WorkSpace::deleteElement(){}
