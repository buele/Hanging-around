//
//  EntityManager.cpp
//  TaskManager
//

#include <vector>
#include <string>
#include <mysql.h>
#include "structures.h"
#include "exceptions.h"
#include "DBManager.h"
#include "EntityManager.h"

// TODO: improve the model
using namespace std;

vector<string> EntityManager::completedTaskList(){
    vector<struct CompletedTaskRow> rows ;
    vector<string> tasks;
    try {
        rows = dbManager.completedTaskList();
    }catch(exception ex) {
      //TODO: manage exceptions
    }
    for (CompletedTaskRow row : rows)
        tasks.push_back( ( row.id + ") " + row.name +
                          " - taken: days: " + row.days +
                          ", hours: " + row.hours +
                          ", minutes: " + row.minutes ) );
    return tasks;
}


vector<string> EntityManager::tasksList(){
    vector<struct PendingTaskRow> rows ;
    vector<string> tasks;
    try {
        rows = dbManager.tasksList();
    }catch(exception ex) {
        //TODO: manage exceptions
    }
    for (PendingTaskRow row : rows)
        tasks.push_back( ( row.id + ") " + row.name ) );
    return tasks;
}


bool EntityManager::createTask(string name) {
    return dbManager.createTask(name);
}

bool EntityManager::archiveTask(int taskId){
    return dbManager.archiveTask(taskId);
}

