//
//  MainController.h
//  TaskManager
//

#ifndef __TaskManager__MainController__
#define __TaskManager__MainController__

class MainController{
private:
    MainView * mainView;
    EntityManager entityManager;
public:
    MainController();
    ~MainController();
};

#endif /* defined(__TaskManager__MainController__) */
