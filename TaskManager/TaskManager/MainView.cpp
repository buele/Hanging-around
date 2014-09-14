//
//  UI.cpp
//  TaskManager
//

#include <iostream>
#include <mysql.h>
#include <vector>
#include "exceptions.h" // TODO: to remove in the UI
#include "DBManager.h" // TODO: to remove in the UI
#include "EntityManager.h"
#include "MainView.h"
#include "MainController.h"

#include "Application.h"


using namespace std;


void MainView::mainLoop(){
    string command;
    while (true){
        cout << "insert command: ";
        cin >> command;
        //manageCommand((int)command);
    };
}

void MainView::showHeader(){
    cout<< "*** TASK MANAGER ***" << endl;
    cout<< "Select action, list of commands 'help'." << endl;
}

void MainView::show(){
    showHeader();
    mainLoop();
}

MainView::MainView(){
    show();
}