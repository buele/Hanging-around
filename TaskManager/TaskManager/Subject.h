//
//  Subject.h
//  TaskManager
//
//  Created by Raffaele Bua on 16/06/14.
//  Copyright (c) 2014 Buele. All rights reserved.
//

#ifndef __TaskManager__Subject__
#define __TaskManager__Subject__

#include <vector>
using namespace std;

class Subject {
    // 1. "independent" functionality
    vector < class Observer * > views; // 3. Coupled only to "interface"
    int value;
public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify();
};

#endif /* defined(__TaskManager__Subject__) */
