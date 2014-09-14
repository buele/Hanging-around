//
//  UI.h
//  TaskManager
//

#ifndef __TaskManager__MainView__
#define __TaskManager__MainView__



using namespace std;


enum Commands{
    CreateNewTaskCommand    = 1,
    CompleteTaskCommand     = 2,
    ArchiveTaskCommand      = 3,
    CompleteTaskListCommand = 4,
    PendingTaskListCommand  = 5,
    QuitCommand             = 0
};

class MainView{
    EntityManager entityManager;
    class MainController * controller;
private:
    void mainLoop();
    void showHeader();
public:
    void show();
    MainView();
    
};

#endif /* defined(__TaskManager__MainView__) */
