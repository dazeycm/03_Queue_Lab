//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
template <class T>
ArrayQueue<T>::ArrayQueue(){
	numItems = 0;
	front = 0;
	backingArraySize = START_SIZE;
	backingArray = new T[START_SIZE];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
	backingArray = NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if (numItems == backingArraySize)	{
		grow();
	}
	backingArray[(front + numItems) % backingArraySize] = toAdd;
	
	numItems++;

	//make new array, put in the new item
	//T* myNewArray = new T[numItems];
	//myNewArray[numItems - 1] = toAdd;

	//copy old array
	//for(unsigned int i=0;i<numItems-1;i++)	{
	//	myNewArray[i] = backingArray[i];
	//}
	//This is delete[], not delete
	//delete[] backingArray;

	//Update pointer
	//backingArray = myNewArray;
}

template <class T>
T ArrayQueue<T>::remove(){
	
	if (numItems == 0)	{
		throw std::string("There are no items to remove!");
	}
	
	T ret = backingArray[front];
	front = (front + 1)%backingArraySize;
	numItems--;
	return ret;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
//double size of array
	T* myNewArray = new T[backingArraySize * 2];
	for (unsigned int i = 0; i<backingArraySize; i++)	{
		myNewArray[i] = backingArray[(front + i) % backingArraySize];
	}
	delete[] backingArray;
	backingArray = myNewArray;
	backingArraySize *= 2;
	front = 0;
}
