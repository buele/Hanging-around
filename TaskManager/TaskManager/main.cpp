//
//  main.cpp
//  TaskManager
//
//  Created by Raffaele Bua on 06/06/14.


#include <iostream>
#include <mysql.h>
#include <vector>
#include "exceptions.h"
#include "DBManager.h" 
#include "EntityManager.h"
#include "MainView.h"
#include "MainController.h"
#include "Application.h"
using namespace std;


vector<string> taskList(){
    EntityManager * entityManager = new EntityManager();
    vector<string> tasks = entityManager->tasksList();
    delete entityManager;
    return tasks;
}

vector<string> completedTasks(){
    EntityManager * entityManager = new EntityManager();
    vector<string> tasks = entityManager->completedTaskList();
    delete entityManager;
    return tasks;
}

void insertNewTask(string newTaskName){
    DBManager * dbManager = new DBManager();
    dbManager->createTask(newTaskName);
    delete dbManager;
}

void printTask(string task){
    cout << task << endl;
}

void completeTask(int taskId){
    DBManager * dbManager = new DBManager();
    dbManager->completeTask(taskId);
    delete dbManager;
}

void printTasks(vector<string> tasks){
    for_each (tasks.begin(), tasks.end(), printTask);
}



int main(int argc, const char * argv[]) {
    //insertNewTask("funcionas?");
    //cout << "complete task 13" << endl;
    //completeTask(11);
    //cout << "pending tasks: "<< endl;
    //printTasks(taskList());
    //cout << "completed tasks" << endl;
    //printTasks(completedTasks());
    
    
    // --
    cout << "hello from main" << endl;
    Application app;
    
    
    
    return 0;
}













