# 0x1B. C - Makefiles
At the end of this project you are expected to be able to explain to anyone, without the help of Google:
* What are `make` and Makefiles?
* When, why and how do you use Makefiles?
* What are a rules? How do you set and use them?
* What are explicit and implicit rules?
* What are the most common / useful rules?
* What are variables? How do you set and use them?
## Project Specifications
* OS: Ubuntu 14.04 LTS
* Version of gcc: 4.8.4
* Version of make: GNU Make 3.81
## File Description
Source files for all Makefiles: [main.c](main.c), [holberton.c](holberton.c), [m.h](m.h)
[0-Makefile](0-Makefile)
	Requirements:
		* name of the executable: `holberton`
		* rules: `all`
	  	  * `all`: builds your executable
		* variables: none
```
julien@ubuntu:~/0x1B. Makefiles$ make -f 0-Makefile
gcc main.c holberton.c -o holberton
julien@ubuntu:~/0x1B. Makefiles$ ./holberton
j#0000000000000000000000000000000000000
j#000000000000000000@Q**g00000000000000
j#0000000000000000*]++]4000000000000000
j#000000000000000k]++]++*N#000000000000
j#0000000000000*C+++]++]++]J*0000000000
j#00000000000@+]++qwwwp=]++++]*00000000
j#0000000000*+++]q#0000k+]+]++]4#000000
j#00000000*C+]+]w#0000*]+++]+]++0000000
j#0000we+]wW000***C++]++]+]++++40000000
j#000000000*C+]+]]+]++]++]++]+q#0000000
j#0000000*]+]+++++++]++]+++]+++J0000000
j#000000C++]=]+]+]+]++]++]+]+]+]=000000
j#00000k+]++]+++]+]++qwW0000000AgW00000
j#00000k++]++]+]+++qW#00000000000000000
j#00000A]++]++]++]++J**0000000000000000
j#000000e]++]+++]++]++]J000000000000000
j#0000000A]++]+]++]++]++000000000000000
j#000000000w]++]+]++]+qW#00000000000000
j#00000000000w]++++]*0##000000000000000
j#0000000000000Ag]+]++*0000000000000000
j#00000000000000000we]+]Q00000000000000
j#0000000000000@@+wgdA]+J00000000000000
j#0000000000000k?qwgdC=]4#0000000000000
j#00000000000000w]+]++qw#00000000000000
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
julien@ubuntu:~/0x1B. Makefiles$
```
[1-Makefile](1-Makefile)
	Requirements:
                * name of the executable: `holberton`
                * rules: `all`
                  * `all`: builds your executable
                * variables: `CC`, `SRC`
		  * `CC`: the compiler to be used
		  * `SRC`: the `.c` files
```
julien@ubuntu:~/0x1B. Makefiles$ make -f 1-Makefile
gcc main.c holberton.c -o holberton
julien@ubuntu:~/0x1B. Makefiles$ make -f 1-Makefile
gcc main.c holberton.c -o holberton
julien@ubuntu:~/0x1B. Makefiles$
```
[2-Makefile](2-Makefile)
        Requirements:
		* name of the executable: `holberton`
		* rules: `all`
		  * `all`: builds your executable
		* variables: `CC`, `SRC`, `OBJ`, `NAME`
                  * `CC`: the compiler to be used
                  * `SRC`: the `.c` files
		  * `OBJ`: the `.o` files
		  * `NAME`: the name of the executable
		* The `all` rule should recompile only the updated source files
		* You are not allowed to have a list of all the `.o` files
```
julien@ubuntu:~/0x1B. Makefiles$ make -f 2-Makefile
gcc    -c -o main.o main.c
gcc    -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$ make -f 2-Makefile
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$ echo "/* Holberton */" >> main.c
julien@ubuntu:~/0x1B. Makefiles$ make -f 2-Makefile
gcc    -c -o main.o main.c
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$
```
[3-Makefile](3-Makefile)
        Requirements:
		* name of the executable: `holberton`
		* rules: `all`, `clean`, `oclean`, `fclean`, `re`
		  * `all`: builds your executable
		  * `clean`: deletes all Emacs and Vim temporary files along with the executable
		  * `oclean`: deletes the object files
		  * `fclean`: deletes all Emacs and Vim temporary files, the executable, and the object files
		  * `re`: forces recompilation of all source files
		* variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`
                  * `CC`: the compiler to be used
                  * `SRC`: the `.c` files
		  * `OBJ`: the `.o` files
		  * `NAME`: the name of the executable
		  * `RM`: the command to delete files
		* The `all` rule should recompile only the updated source files
		* You are not allowed to have a list of all the `.o` files
		* The `clean`, `oclean`, `fclean`, and `re` rules should never fail
```
julien@ubuntu:~/holberton/curriculum_by_julien/holbertonschool-low_level_programming/0x1B. Makefiles$ ls -1
0-Makefile
1-Makefile
2-Makefile
3-Makefile
holberton.c
main.c
main.c~
m.h
julien@ubuntu:~/0x1B. Makefiles$ make -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$ make all -f 3-Makefile
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$ ls -1
0-Makefile
1-Makefile
2-Makefile
3-Makefile
holberton
holberton.c
holberton.o
main.c
main.c~
main.o
m.h
julien@ubuntu:~/0x1B. Makefiles$ make clean -f 3-Makefile
rm -f *~ holberton
julien@ubuntu:~/0x1B. Makefiles$ make oclean -f 3-Makefile
rm -f main.o holberton.o
julien@ubuntu:~/0x1B. Makefiles$ make fclean -f 3-Makefile
rm -f *~ holberton
rm -f main.o holberton.o
julien@ubuntu:~/0x1B. Makefiles$ make all -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$ make all -f 3-Makefile
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$ make re -f 3-Makefile
rm -f main.o holberton.o
gcc    -c -o main.o main.c
gcc    -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$
```
[4-Makefile](4-Makefile)
        Requirements:
		* name of the executable: `holberton`
		* rules: `all`, `clean`, `oclean`, `fclean`, `re`
		  * `all`: builds your executable
		  * `clean`: deletes all Emacs and Vim temporary files along with the executable
		  * `oclean`: deletes the object files
		  * `fclean`: deletes all Emacs and Vim temporary files, the executable, and the object files
		  * `re`: forces recompilation of all source files
		* variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`, `CFLAGS`
                  * `CC`: the compiler to be used
                  * `SRC`: the `.c` files
		  * `OBJ`: the `.o` files
		  * `NAME`: the name of the executable
		  * `RM`: the command to delete files
		  * `CFLAGS`: compiler flags `-Wall -Werror -Wextra -pedantic`
		* The `all` rule should recompile only the updated source files
		* You are not allowed to have a list of all the `.o` files
		* The `clean`, `oclean`, `fclean`, and `re` rules should never fail
```
julien@ubuntu:~/0x1B. Makefiles$ make all -f 4-Makefile
gcc -Wall -Werror -Wextra -pedantic   -c -o main.o main.c
gcc -Wall -Werror -Wextra -pedantic   -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
julien@ubuntu:~/0x1B. Makefiles$
```