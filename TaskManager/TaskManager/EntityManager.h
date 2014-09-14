//
//  EntityManager.h
//  TaskManager
//


#ifndef __TaskManager__EntityManager__
#define __TaskManager__EntityManager__


using namespace std;



class EntityManager{
    DBManager dbManager;    
public:
    bool createTask(string name);
    bool completeTask(int taskId);
    bool archiveTask(int taskId);
    vector<string> completedTaskList();
    vector<string> tasksList();
};

#endif /* defined(__TaskManager__EntityManager__) */
