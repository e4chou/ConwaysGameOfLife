#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>

#include "observer.h"

template <typename T> class Subject {
   protected:
    std::vector<T *> observers;

   public:
    Subject();
    void attach(T *o);
    void detach(T *o);
    virtual void notifyObservers() const;
    virtual ~Subject() = 0;
};

template <typename T> Subject<T>::Subject() {}
template <typename T> Subject<T>::~Subject() {}

template <typename T> void Subject<T>::attach(T *o) {
  observers.emplace_back(o);
}

template <typename T> void Subject<T>::detach(T *o) {
  for (auto it = observers.begin(); it != observers.end(); ++it) {
    if (*it == o) {
      observers.erase(it);
      break;
    }
  }
}

template <typename T> void Subject<T>::notifyObservers() const {
  for (auto ob : observers) ob->notify();
}

#endif
