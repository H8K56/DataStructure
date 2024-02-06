#include <iostream>
#include <cstdlib>

// Function that takes an array and its size as parameters
void printArray(int* arr, int size) {
    int* ptr = arr;
    std::cout << "Address of arr: " << *(++ptr) << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int num = 10;
    int* ptr = &num;

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value of ptr: " << ptr << std::endl;
    std::cout << "Value pointed by ptr: " << *ptr << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Passing the array and its size to the function
    printArray(arr, size);

    // Other ways in which pointers can be used:
    int* dynamicPtr = new int; // Dynamic memory allocation using new
    *dynamicPtr = 20;
    std::cout << "Value of dynamicPtr: " << *dynamicPtr << std::endl;
    delete dynamicPtr; // Freeing the dynamically allocated memory

    int* mallocPtr = (int*)malloc(sizeof(int)); // Dynamic memory allocation using malloc
    *mallocPtr = 30;
    std::cout << "Value of mallocPtr: " << *mallocPtr << std::endl;
    free(mallocPtr); // Freeing the dynamically allocated memory using free

    int* nullPtr = nullptr; // Null pointer
    if (nullPtr == nullptr) {
        std::cout << "nullPtr is a null pointer" << std::endl;
    }
    
    return 0;
}