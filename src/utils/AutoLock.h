//
// Created by kurt on 18-4-13.
//

#ifndef OPENGL2_AUTOLOCK_H
#define OPENGL2_AUTOLOCK_H

#include <pthread.h>
class Lock {
private:
    pthread_mutex_t * pMutex;
public:
    Lock() {
        pthread_mutex_init(pMutex, NULL);
    }

    void lock() {
        pthread_mutex_lock(pMutex);
    }

    void unlock() {
        pthread_mutex_unlock(pMutex);
    }
};

class AutoLock {
private:
    Lock mLock;
public:
    AutoLock(Lock& lock) {
        mLock = lock;
        mLock.lock();
    }
    ~AutoLock() {
        mLock.unlock();
    }
};

#endif //OPENGL2_AUTOLOCK_H
