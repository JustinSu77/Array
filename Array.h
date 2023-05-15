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
            void insertAt(int position, T newValue);
            void removeAtStart();
            void removeAtEnd();
            void removeAt(int position, T newValue);
            int indexOf(T value);
            T front();
            T back();
            T at(int position);
            bool isFull();
            bool isEmpty();
            int length();
            int capacity();
            void sort();
            void fill(T value);
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
    Array<T>::Array(const std::initializer_list<T> &list): size(list.size()), maxSize(list.size())
    {
        delete[] array;
        int index = 0;
        for (auto element: list)
        {
            array[index] = element;
            index++;
        }
    }

    template<class T>
    Array<T>::Array(const Array &arr)
    {
        delete [] array;
        size = arr.size;
        maxSize = arr.maxSize;
        for (int i = 0; i < size; i++)
        {
            array[i] = arr.array[i];
        }
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

    template<class T>
    Array<T>::~Array()
    {
        delete [] array;
    }

    template<class T>
    void Array<T>::insertAtStart(T newValue)
    {
        if (isFull())
            throw std::runtime_error("insertAtStart: Array is full!");
        for (int i = size; i >= 0; i--)
        {
            array[i + 1] = array[i];
        }
        array[0] = newValue;
        size++;
    }

    template<class T>
    void Array<T>::insertAtEnd(T newValue)
    {
        if (isFull())
            throw std::runtime_error("insertAtEnd: Array is full!");
        array[size] = newValue;
        size++;
    }

    template<class T>
    void Array<T>::insertAt(int position,T newValue)
    {
        if (position < 0 || position > size - 1)
            throw std::runtime_error("insertAt: Array is full!");
        if (isFull())
            throw std::runtime_error("insertAt: Array is full!");
        if (position == 0)
        {
            insertAtStart(newValue);
            return;
        }
        if (position == size + 1)
        {
            insertAtEnd(newValue);
            return;
        }
        for (int i = size; i >= position; i--)
        {
            array[i + 1] = array[i];
        }
        array[position] = newValue;
        size++;


    }

    template<class T>
    void Array<T>::removeAtStart()
    {
        if (isEmpty())
            throw std::runtime_error("removeAtStart: Array is already empty!");
        for (int i = 0; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }

    template<class T>
    void Array<T>::removeAtEnd()
    {
        if (isEmpty())
            throw std::runtime_error("removeAtEnd: Array is already empty!");
        T* temp = new T[2]{};
        array[size - 1] = temp[0];
        delete[] temp;
        size--;
    }

    template<class T>
    void Array<T>::removeAt(int position, T newValue)
    {
        if (position < 0 || position > size - 1)
            throw std::runtime_error("removeAt: Array is already empty!");
        if (isEmpty())
            throw std::runtime_error("removeAt: Array is already empty!");

        if (position == 0)
        {
            removeAtEnd();
            return;
        }
        if (position == size - 1)
        {
            removeAtEnd();
            return;
        }

        size--;
    }

    template<class T>
    int Array<T>::indexOf(T value)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == value)
                return i;
        }
        return -1;
    }

    template<class T>
    T Array<T>::front()
    {
        if (isEmpty())
            throw std::runtime_error("front: Array is empty!");
        return array[0];
    }

    template<class T>
    T Array<T>::back()
    {
        if (isEmpty())
            throw std::runtime_error("back: Array is empty!");
        return array[size - 1];
    }

    template<class T>
    T Array<T>::at(int position)
    {
        if (position < 0 || position > size - 1);
            throw std::runtime_error("at: Given position is out of bounds!");
        return array[position - 1];
    }

    template<class T>
    bool Array<T>::isFull()
    {
        return size == maxSize;
    }

    template<class T>
    bool Array<T>::isEmpty()
    {
        return size == 0;
    }

    template<class T>
    void Array<T>::sort()
    {
        for (int i = 0; i < size; i++)
        {
            bool isSwapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j + 1] > array[j])
                {
                    T temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;

                }
            }
            if (!isSwapped)
                break;
        }

    }

    template<class T>
    void Array<T>::fill(T value)
    {
        delete[] array;
        array = new T[maxSize]{};
        for (int i = 0; i < maxSize; i++)
        {
            array[i] = value;
        }
        size = maxSize;
    }

    template<class T>
    void Array<T>::clear()
    {
        delete[] array;
        array = new T[maxSize]{};
        size = 0;

    }

    template<class T>
    void Array<T>::operator=(const Array<T> &arr)
    {
        size = arr.size;
        maxSize = arr.size;
        for (int i = 0; i < size; i++)
        {
            array[i] = arr.array[i];
        }

    }

    template<class T>
    bool Array<T>::operator==(const Array<T> &arr)
    {
        if (size != arr.size || maxSize != arr.maxSize)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (array[i] != arr.array[i])
                return false;
        }
        return true;
    }

    template<class T>
    T& Array<T>::operator[](int index)
    {
        if (index < 0 || index > size)
            throw std::runtime_error("[]: Index is out of bounds!");
        return  array[index - 1];
    }


}




#endif //ARRAY_ARRAY_H
