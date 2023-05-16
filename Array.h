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
            Array(const Array<T>& existingArray);


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



    /**
     * Default constructor.
     * @param T
     */
    template<class T>
    Array<T>::Array(): size(0),maxSize(10)
    {
        // Sets array pointer to be a dynamic array with maxSize
        // Initialized to default value of T data type
        array = new T[maxSize]{};

    }


    template<class T>
    Array<T>::Array(int maxSize): size(0), maxSize(maxSize)
    {
        // If given maxSize is negative throw exception
        if (maxSize < 0)
            throw std::runtime_error("Array(int maxSize): Given maxSize cannot be negative");

        // Sets array pointer to be a dynamic array with maxSize
        // Initialized to default value of T data type
        array = new T[maxSize]{};
    }

    template<class T>
    Array<T>::Array(const std::initializer_list<T> &list): size(list.size()), maxSize(list.size())
    {


        // Reallocates array pointer to have maxSize and default values
        array = new T[maxSize]{};
        // Set index counter to copy elements from list to array
        int index = 0;
        // Copy elements from range
        for (auto element: list) {
            // Set index of array to element of initializer list
            array[index] = element;
            // Increment index counter
            index++;
        }

    }

    template<class T>
    Array<T>::Array(const Array<T>& existingArray):size(existingArray.size), maxSize(existingArray.maxSize)
    {
        // Allocate memory for dynamic array
         array = new T[maxSize]{};
         // Copy elements from array of exising instance of this class
         for (int i = 0; i < size; i++)
         {
             array[i] = existingArray.array[i];
         }


    }

    template<class T>
    void Array<T>::print()
    {
        // Print first bracket
        std::cout << "[";
        // Print the elements
        for (int i = 0; i < size; i++)
        {
            // Last element will have no space before it
            if (i == size - 1)
                std::cout << array[i];
            // Print space between elements otherwise
            else
                std::cout << array[i] << " ";
        }
        // Print last bracket
        std::cout << "]";
        // Add newline to next output will be on next line
        std::cout << std::endl;
    }

    template<class T>
    void Array<T>::reverse()
    {
        // If array only has one element or it is empty then return
        if (size == 1 || isEmpty())
            return;
        // Set pointer to beginning of array
        int start = 0;
        // Set pointers to end of array
        int end = size - 1;
        // as long as start and end pointers do not meet each other
        while (start < end)
        {
            // Swap
            T temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            // Increase start pointers
            start++;
            // Decrease start pointers
            end--;
        }
    }


    template<class T>
    int Array<T>::length()
    {
        // Return the size member variable
        return size;
    }

    template<class T>
    int Array<T>::capacity()
    {
        // Return the maxSize member variable
        return maxSize;
    }

    template<class T>
    Array<T>::~Array()
    {
        // Deallocate dynamic array
        delete[] array;
    }

    template<class T>
    void Array<T>::insertAtStart(T newValue)
    {
        // If array is full, throw runtime_error
        if (isFull())
            throw std::runtime_error("insertAtStart: Array is full!");
        // Shift elements to right first
        for (int i = size; i >= 0; i--)
        {
            array[i + 1] = array[i];
        }
        // Insert given newValue at beginning
        array[0] = newValue;
        // Increase size
        size++;
    }

    template<class T>
    void Array<T>::insertAtEnd(T newValue)
    {
        // If array is full, throw runtime_error
        if (isFull())
            throw std::runtime_error("insertAtEnd: Array is full!");
        // Set last element to newValue
        array[size] = newValue;
        // Increase size by 1
        size++;
    }

    template<class T>
    void Array<T>::insertAt(int position,T newValue)
    {
        // If given position is out of bounds, throw runtime error
        if (position < 0 || position > size)
            throw std::runtime_error("insertAt: Array is full!");
        // If array is full, throw runtime error
        if (isFull())
            throw std::runtime_error("insertAt: Array is full!");
        // If position is 0, call insertAtStart function
        if (position == 0)
        {
            insertAtStart(newValue);
            return;
        }
        // If position is at the end of array, call insertAtEnd function
        if (position == size)
        {
            insertAtEnd(newValue);
            return;
        }
        // Shift element at given position to right
        for (int i = size; i >= position; i--)
        {
            array[i + 1] = array[i];
        }
        // Set given newValue to given position index - 1
        array[position - 1] = newValue;
        // Increase by 1
        size++;


    }

    template<class T>
    void Array<T>::removeAtStart()
    {
        // If array is full, throw runtime error
        if (isEmpty())
            throw std::runtime_error("removeAtStart: Array is already empty!");
        // Shift elements to the left
        for (int i = 0; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        //Decrease size by 1
        size--;
    }

    template<class T>
    void Array<T>::removeAtEnd()
    {
        // If array is full, throw runtime error
        if (isEmpty())
            throw std::runtime_error("removeAtEnd: Array is already empty!");
        // Create a temp array to get the default value of the data type T
        T* temp = new T[2]{};
        // Set the last element to be the default value
        array[size - 1] = temp[0];
        // Deallocate temp array
        delete[] temp;
        // Decrease size by 1
        size--;
    }

    template<class T>
    void Array<T>::removeAt(int position)
    {
        // If given position is out of bounds, throw runtime_error
        if (position < 0 || position > size - 1)
            throw std::runtime_error("removeAt: Array is already empty!");
        // If array is empty, throw runtime_error
        if (isEmpty())
            throw std::runtime_error("removeAt: Array is already empty!");
        // If given position is 0, call removeAtStart function
        if (position == 0)
        {
            removeAtStart();
            return;
        }
        // If given position is the last position, call removeAtEnd function
        if (position == size - 1)
        {
            removeAtEnd();
            return;
        }
        // Decrease size by 1
        size--;
    }

    template<class T>
    int Array<T>::indexOf(T value)
    {
        // Traverse array
        for (int i = 0; i < size; i++)
        {
            // if the given value is found
            if (array[i] == value)
                // Return the index
                return i;
        }
        // Otherwise return -1
        return -1;
    }

    template<class T>
    T Array<T>::front()
    {
        // If array is empty, throw runtime_error
        if (isEmpty())
            throw std::runtime_error("front: Array is empty!");
        // Return the first element
        return array[0];
    }

    template<class T>
    T Array<T>::back()
    {
        // If array is empty, throw runtime_error
        if (isEmpty())
            throw std::runtime_error("back: Array is empty!");
        // Return the last element
        return array[size - 1];
    }

    template<class T>
    T Array<T>::at(int position)
    {
        if (position < 0 || position > size - 1)
            throw std::runtime_error("at: Given position is out of bounds!");
        // Return the element at given position
        return array[position - 1];
    }

    template<class T>
    bool Array<T>::isFull()
    {
        // Return if size == maxSize
        return size == maxSize;
    }

    template<class T>
    bool Array<T>::isEmpty()
    {
        // Return if size is 0
        return size == 0;
    }

    template<class T>
    void Array<T>::sort()
    {
        // Bubble sort
        for (int i = 0; i < size; i++)
        {
            // Flag for optimization
            bool isSwapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                // If the next element is greater than current element
                if (array[j + 1] > array[j])
                {
                    // Swap
                    T temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;
                    // Set flag to true
                    isSwapped = true;
                }
            }
            // If flag has not been set then break
            if (!isSwapped)
                break;
        }

    }

    template<class T>
    void Array<T>::fill(T value)
    {
        // Deallocate array pointer
        delete[] array;
        // Reallocate array pointer
        array = new T[maxSize]{};
        // Traverse the array to maxSize
        for (int i = 0; i < maxSize; i++)
        {
            // Set the elements to given value
            array[i] = value;
        }
        // Set size to maxSize
        size = maxSize;
    }

    template<class T>
    void Array<T>::clear()
    {
        // Deallocate array pointer
        delete[] array;
        // Set array elements to default elements
        array = new T[maxSize]{};
        // Set size to 0
        size = 0;

    }

    template <class T>
    void Array<T>::operator=(const Array<T>& arr)
    {
        // Set size to the size of arr.size
        size = arr.size;
        // Set size to arr.maxSize
        maxSize = arr.maxSize;
        // Deallocate array
        delete[] array;
        // Reallocate array pointer to default values
        array = new T[maxSize]{};
        // Copy element from arr.array to initialized array
        for (int i = 0; i < size; i++)
        {
            array[i] = arr.array[i];
        }
    }

    template<class T>
    bool Array<T>::operator==(const Array<T> &arr)
    {
        // If size is not equal to arr.size or if maxSize is not equal to arr.maxSize
        if (size != arr.size || maxSize != arr.maxSize)
            return false;
        // Check if any elements are different
        for (int i = 0; i < size; i++)
        {
            if (array[i] != arr.array[i])
                return false;
        }
        // Otherwise return true
        return true;
    }


    template<class T>
    T& Array<T>::operator[](int index)
    {
        // If given index is out of bounds, throw runtime_error
        if (index < 0 || index > size)
            throw std::runtime_error("[]: Index is out of bounds!");
        // Return the element at given index
        return  array[index - 1];
    }


}




#endif //ARRAY_ARRAY_H
