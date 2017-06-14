File Descriptions:
function_pointers.h - header file for 0-print_name.c, 1-array_iterator.c, and 2-int_index.c
0-print_name.c - void print_name(char *name, void (*f)(char *)) - prints a name.
1-array_iterator.c - void array_iterator(int *array, size_t size, void (*action)(int)) - executes a function given as a parameter on each element of an array.
2-int_index.c - int int_index(int *array, int size, int (*cmp)(int)) - searches for an integer.
3-calc.h - header file for 3-main.c, 3-op_functions.c, and 3-get_op_func.c
3-main.c - performs simple operations.
3-op_functions.c - 5 following functions:
		 1. int op_add(int a, int b) - returns the sum of a and b
		 2. int op_sub(int a, int b) - returns the difference of a and b
		 3. int op_mul(int a, int b) - returns the product of a and b
		 4. int op_div(int a, int b) - returns the result of the division of a by b
		 5. int op_mod(int a, int b) - returns the remainder of the division of a by b
3-get_op_func.c - selects the correct function to perform the operation asked by the user
