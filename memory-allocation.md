- It will NOT cause compilation errors, if a programmer forgets to de-allocate dynamically allocation memory in the C++ code, but it will cause a **memory leak**

- When a program terminates, all memory allocated to the program, including leaked memory, will be re-collected/deallocated by the operating system

- If a local variable within a function is statically allocated memory, this memory will be automatically deallocated after the end of the function's scope