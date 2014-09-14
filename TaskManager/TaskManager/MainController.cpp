//
//  MainController.cpp
//  TaskManager
//


#include <iostream>
#include <mysql.h>
#include <vector>
#include "exceptions.h" // TODO: to remove in the UI
#include "DBManager.h"  // TODO: to remove in the UI
#include "EntityManager.h"
#include "MainView.h"
#include "MainController.h"
#include "Application.h"

MainController::MainController(){
    cout << "hello from main Controller" << endl;
    mainView = new MainView();
}
MainController::~MainController(){
    delete  mainView;
}

void manageCommand(int command){
    switch (command) {
        case CreateNewTaskCommand:

            break;
        case CompleteTaskCommand:

            break;
        case ArchiveTaskCommand:

            break;
        case CompleteTaskListCommand:

            break;
        case PendingTaskListCommand:

            break;
        case QuitCommand:
            break;
    }
}