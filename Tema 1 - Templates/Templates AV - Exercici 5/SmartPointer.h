#pragma once
#include <iostream>
using namespace std;

template <class T>
class SmartPointer
{
public:

    SmartPointer() : ptr(nullptr) {}
    SmartPointer(SmartPointer& sp) : ptr(sp.ptr) { sp.ptr = nullptr; }

    SmartPointer<T>& operator=(T* p);
    SmartPointer<T>& operator=(SmartPointer& sp);

    T& operator*();
    T* operator->();

    bool isNull() { return ptr == nullptr; }

private:

    T* ptr;

};

template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(T* p)
{
    if (ptr != p)
    {
        delete ptr;
        ptr = p;
    }
    return *this;
}

template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer& sp)
{
    if (this != &sp)
    {
        delete ptr;
        ptr = sp.ptr;
        sp.ptr = nullptr;
    }
    return *this;
}

template <class T>
T& SmartPointer<T>::operator*()
{
    if (ptr == nullptr)
    {
        cout << "L'apuntador és NULL" << endl;
    }
    return *ptr;
}

template <class T>
T* SmartPointer<T>::operator->()
{
    if (ptr == nullptr)
    {
        cout << "L'apuntador és NULL" << endl;
    }
    return ptr;
}