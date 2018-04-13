//
// Created by kurt on 18-4-13.
//

#ifndef OPENGL2_SINGLETON_H
#define OPENGL2_SINGLETON_H

#include "AutoLock.h"

template <typename T>

class Singleton {
public:
    static T& getInstance() {
        AutoLock lock(sLock);
        if (instance == NULL) {
            instance = new T;
        }
        return *instance;
    }

    bool hasInstance() {
        AutoLock lock(sLock);
        return instance != NULL;
    }

private:
    static T *instance;
    static Lock sLock;

    ~Singleton() {
        delete instance;
    }
    Singleton() {}
    Singleton(const Singleton & t) {}
    Singleton & operator = () {}
};

#endif //OPENGL2_SINGLETON_H
