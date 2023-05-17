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
             * Constructor with initializer list and maxSize
             * Sets size to be size of the initializer list.
             * Sets maxSize to be the given maxSize
             * Copies elements from initializer list to array
             * If maxSize is less than 0 throws runtime_error
             * If size of initializer list is greater than maxSize, throws runtime_error
             * @param list
             * @param maxSize
             */
            Array(const std::initializer_list<T>& list,int maxSize);

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
             * If index is < 0 or index is greater than size - 1, throw runtime_error exception
             * @param index as index of element to be returned
             * @return the element at given index
             */
            T& operator[](int index);