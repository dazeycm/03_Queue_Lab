03_Queue_Lab
============

Implement an array-based queue in C++

Note: When you create your project, do NOT add ArrayQueue.ipp to the list of source files, add it to the list of include files. You will see that ArrayQueue.ipp is #included at the bottom of ArrayQueue.h. See ArrayQueue.h for more explanation.

Requirements
------------

1. remove takes O(1) time
2. add takes O(1) time, unless it calls grow (in that case O(n) is okay)
3. grow is only called if the number of items == backingArraySize, and the size of the array is doubled during grow
4. grow takes O(n) time
5. Do not leak memory (make sure grow and the destructor do the right thing)
6. getNumItems is O(1) time
7. add and remove throw excpetions as appropriate
8. You must use the array in a circular fashion. If you don't do this you probably won't be able to get #1, #2 and #3 to all be true.

Reading
=======
"Open Data Structures," Chapter 2, up through section 2.4 (ArrayDequeue). http://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html

Information about the Von Neumann computing model may be helpful. This optional reading is section 2.2 of "Algorithms and Data Structures: A Basic Toolbox" by Melhorn and Sanders. A free copy may be found here: http://www.mpi-inf.mpg.de/~mehlhorn/ftp/Toolbox/Introduction.pdf

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. My remove takes O(1) time
2. My add takes O(1) time except for when grow() is called
3. Grow correctly works
4. Grow takes O(n) time
5. Destructor works properly
6. GetNumItems is properly implemented
7. Exception is thrown properly
8. Array is circular 

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
We would keep all of the private methods and variables except for the front variable. This is because the front of the stack is always where variables are added, so the front is always at backingArray[0].

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
The idea of modulus was confusing at first, and it's purpose in this lab. I would make sure the students really understand why they're using it. 

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
Instead of "extends" you would use ":" so you would write class "ArrayQueue : extends" queue.

#### 5. What is the purpose of "templates" in C++?
Templates allow you to create code that will work with different data types.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
int* array = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The destructor frees up the space that the object was using. Java doesn't use deconstructors because it has garbage collection. This means that it can automatically detect when stored data is no more useful and free it up. 
