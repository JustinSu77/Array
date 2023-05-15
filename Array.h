//
// Created by justi on 5/15/2023.
//
/**
    Array()
    Array(int maxSize)
    Array(const Array<T>&arr)
    Array(std::initializer_list<T>& list)
    ~Array()
    void insertAtStart(T newValue)
    void insertAtEnd(T newValue)
    void insertAt(int position, T newValue)
    void removeAtStart(T newValue)
    void removeAtEnd(T newValue)
    void removeAt(int position, T newValue)
    int indexOf(T value)
    T front()
    T back()
    T at(int position)
    int length()
    int capacity()
    void sort()
    void fill(T value)
    void clear()
    void print()
    void operator=(const Array<T>& arr)
    bool operator==(const Array<T>& arr)
    T& operator[](int position)
 */
#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H
#include <initializer_list>
#include <iostream>
namespace
{
    template<class T>
    class Array
    {
        public:
            Array();
            Array(int maxSize);
            Array(const Array& arr);
            Array(const std::initializer_list<T>& list);
            ~Array();
            void insertAtStart(T newValue);
            void insertAtEnd(T newValue);
            void insertAt(T newValue);
            void removeAtStart();
            void removeAtEnd();
            void removeAt(T newValue);
            int indexof(T value);
            T front();
            T back();
            T at(int position);
            int length();
            int capacity();
            void sort();
            void fill();
            void clear();
            void print();
            void operator=(const Array<T>& arr);
            bool operator==(const Array<T>& arr);
            T& operator[](int index);

        private:
            T* array;
            int size;
            int maxSize;
    };

    template<class T>
    Array<T>::Array(): size(0),maxSize(10)
    {
        array = new T[maxSize]{};

    }
    template<class T>
    Array<T>::Array(int maxSize): size(0), maxSize(maxSize)
    {
        if (maxSize < 0)
            throw std::runtime_error("Array(int maxSize): Given maxSize cannot be negative");
        if (maxSize > INT_MAX)
            throw std::runtime_error("Array(int maxSize): Given maxSize is too large! ");
        array = new T[maxSize]{};
    }

    template<class T>
    void Array<T>::print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    template<class T>
    int Array<T>::length()
    {
        return size;
    }

    template<class T>
    int Array<T>::capacity()
    {
        return maxSize;
    }



}




#endif //ARRAY_ARRAY_H