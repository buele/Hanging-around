//
//  structures.h
//  TaskManager
//


#ifndef TaskManager_structures_h
#define TaskManager_structures_h

using namespace std;
struct CompletedTaskRow{
    string id;
    string name;
    string days;
    string hours;
    string minutes;
};


struct PendingTaskRow{
    string id;
    string name;
};
#endif


