//
// Created by Justin Su on 5/15/2023.
//
/**
    Constructors
        Array()
        Array(int maxSize)
        Array(const Array<T>&arr)
        Array(std::initializer_list<T>& list)
    Destructors
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
    void reverse()
    void operator=(const Array<T>& arr)
    bool operator==(const Array<T>& arr)
    T& operator[](int position)
    Private member variables
        T* array;
        int size;
        int maxSize;
 */
#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H
#include <initializer_list>
#include <iostream>
namespace justin_su
{
    template<class T>
    /**
     * Justin Su's implementation of a fixed Array data structure
     * @tparam T as datatype Array will have
     */
    class Array
    {
        public:

            /**
             * Default constructor.
             * Sets length to be 0.
             * Sets maxSize to be 10.
             * Sets array to be a dynamic array with 10 elements.
             */
            Array();

            /**
             * Creates an array with a maximum of given maxSize.
             * Sets length to be 0.
             * Sets maxSize to be given maxSize.
             * Sets array pointer to a dynamic array with given maxSize.
             * @param maxSize max number of elements array can hold as int
             */
            Array(int maxSize);


            /**
             * Copy constructor.
             * Sets size to be arr.size
             * Sets maxSize to be arr.maxSize.
             * Reallocates array pointer to dynamic array with maxSize elements.
             * Copies elements from arr.array to array.
             * @param arr as existing instance of this class.
             */
            Array(const Array& arr);


            /**
             * Constructor with initializer list.
             * Sets size to be the size of the initializer list.
             * Sets maxSize to be the size of the initializer list.
             * @param list as initializer_list of elements with data type T to be copied
             */
            Array(const std::initializer_list<T>& list);


            /**
             * Destructor.
             * Deallocates array pointer.
             */
            ~Array();

            /**
             * Inserts given newValue at beginning of array.
             * If array is full, throw runtime_exception.
             * Increment size by 1.
             * Precondition: Array is not full
             * Postcondition: Given newValue is added to beginning of array.
             *                Size is increased by 1.
             * @param newValue as new element to be added to start of array with data type T
             */
            void insertAtStart(T newValue);



            /**
             * Insert given newValue at end of array.
             * If array is full, throw runtime_exception.
             * Increment size by 1.
             * Precondition: Array is not full
             * Postcondition: Given newValue is added to end of array
             *                Size is increased by 1
             * @param newValue as new element to be added to end of array with data type T
             */
            void insertAtEnd(T newValue);

            /**
             * Insert given new value at given position.
             * If array is full, throw runtime_exception
             * If position is 0, call insertAtStart
             * If position is size - 1, call insertAtEnd
             * Otherwise, insert newValue at position index
             * @param position as zero-based index to insert new element at
             * @param newValue as newValue to be inserted into array with data type of T
             */
            void insertAt(int position, T newValue);


            /**
             * Remove the first element in the array.
             * If array is already empty, throw runtime_error.
             * Precondition: Array has some elements.
             * Postcondition: The first element of array has been removed
             *                Size is decreased by 1
             */
            void removeAtStart();

            /**
             * Remove the last element in the array.
             * If array is already empty, throw runtime_error
             * Precondition: Array has some elements
             * Postcondition: The last element of array has been removed
             *                Size is decreased by 1
             */
            void removeAtEnd();

            /**
             * Remove the element at given position.
             * If position is 0, call removeAtStart()
             * If position is size - 1, call removeAtEnd()
             * Otherwise remove the element at the given position.
             * @param position as the zero-based index
             */
            void removeAt(int position);

            /**
             * Return the zero-based index of the first occurrence of the given value.
             * If value does not exist, return -1
             * Precondition: Array has some elements
             * Postcondition: The index of the first occurrence of the given value is returned
             *                If the given value does not exist in array, return -1
             * @param value as target value to search for
             * @return the index where the given value is at or -1
             */
            int indexOf(T value);



            /**
             * Return the first element of the array.
             * If array is empty, throw runtime_exception
             * Precondition: Array has some elements.
             * Postcondition: The first element of the array is returned
             * @return the first elememt of the array
             */
            T front();


            /**
             * Return the last element of the array.
             * if array is empty, throw runtime_exception
             * Precondition: Array has some elements.
             * Postcondition: The last element of the array is returned.
             * @return
             */
            T back();


            /**
             * Return the element at the given position.
             * @param position as index of element to be returned
             * @return the element of the array at the given position
             */
            T at(int position);


            /**
             * Return whether or not the array is full.
             * Array is full when size == maxSize
             * @return true if array is full, false otherwise
             */
            bool isFull();


            /**
             * Return whether or not the array is empty.
             * Array is empty when size == 0
             * @return true if array is empty, false otherwise
             */
            bool isEmpty();

            /**
             * Return the size of the array.
             * @return size of array as int
             */
            int length();

            /**
             * Return the maxSize of the array.
             * @return maxSize of array as int
             */
            int capacity();

            /**
             * Sort the array in ascending order.
             * Uses optimized bubble sort.
             * If array size is 1 or it is empty, return
             * Precondition: Array has some elements
             * Postcondition: Array is sorted in ascending order
             */
            void sort();

            /**
             * Fill the array with given value.
             * Precondition: Array is empty or has some elements.
             * Postcondition: Array is filled to maxSize with given value
             * @param value as value the entire array is filled with
             */
            void fill(T value);

            /**
             * Clear the array.
             * Deallocates the array pointer.
             * Sets size to 0
             * Precondition: Array is empty or has some elements
             * Postcondition: Array is deallocated
             *                Size is set to 0
             */
            void clear();

            /**
             * Reverses the elements of the array.
             * If array size is 0 or 1 return
             * Precondition: Array has some elements
             * Postcondition: The order of the elements in the array are reversed.
             */
            void reverse();

            /**
             * Outputs the elements of the array in between brackets
             */
            void print();

            /**
             * Copies the size, maxSize, and elements from existing Array instance to another Array instance
             * Precondition: This array instance has some size, maxSize, and elements
             * Postcondition: This array instancae has the size, maxSize, and elements of arr
             * Sets size to arr.size
             * Sets maxSize to arr.maxSize
             * Copies the elements
             * @param arr existing instance of this class
             */
            void operator=(const Array<T>& arr);

            /**
             * Returns whether or not two instances of this class are equal.
             * Two instances of this class are equal if their size, maxSize, and elements are equal
             * @param arr as existing instance of this class
             * @return true if the instances of this class are equal, false if not
             */
            bool operator==(const Array<T>& arr);


            /**
             * Returns the element at given index using bracket operator
             * @param index as index of element to be returned
             * @return the element at given index
             */
            T& operator[](int index);

        private:
            T* array;
            int size;
            int maxSize;
    };

    template<class T>
    void Array<T>::reverse()
    {
        if (size == 1 || isEmpty())
            return;
        int start = 0;
        int end = size - 1;
        while (start < end)
        {
            T temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }

    /**
     * Default constructor.
     * @param T
     */
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
        array = new T[maxSize]{};
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
    void Array<T>::removeAt(int position)
    {
        if (position < 0 || position > size - 1)
            throw std::runtime_error("removeAt: Array is already empty!");
        if (isEmpty())
            throw std::runtime_error("removeAt: Array is already empty!");

        if (position == 0)
        {
            removeAtStart();
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
