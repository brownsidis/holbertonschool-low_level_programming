# 0x17. C - Dynamic libraries
An introductory project into dynamic libraries in C

## File Descriprions
* Task 0 - Create a dynamic library with specified functions
  * [libholberton.so](libholberton.so) - dynamic library
  * [C_files](C_files) - directory containing all of the functions included in [libholberton.so](libholberton.so)
  * [holberton.h](holberton.h) - header file containing all of the prototypes of the functions found in [C_files](C_files)
* Task 1 - Create a script that creates a dynamic library called `liball.so` from all the `.c` files that are in the current directory.
  * [1-create_dynamic_lib.sh](1-create_dynamic_lib.sh) - shell script to create `liball.so`
* Task 2 - Write a blog post describing the differences between static and dynamic libraries.
  * [Medium Post](google.com)
### Advanced
* Task 3 - Create a dynamic library that contains C functions that can be called from Python. See example for more detail.
```
julien@ubuntu:~/0x17$ cat 100-tests.py
import random
import ctypes

cops = ctypes.CDLL('./100-operations.so')
a = random.randint(-111, 111)
b = random.randint(-111, 111)
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.div(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
julien@ubuntu:~/0x16. Doubly linked lists$ python3 100-tests.py
66 + -76 = -10
66 - -76 = 142
66 x -76 = -5016
66 / -76 = 0
66 % -76 = 66
julien@ubuntu:~/0x17$ python3 100-tests.py
-34 + -57 = -91
-34 - -57 = 23
-34 x -57 = 1938
-34 / -57 = 0
-34 % -57 = -34
julien@ubuntu:~/0x17$ python3 100-tests.py
-5 + -72 = -77
-5 - -72 = 67
-5 x -72 = 360
-5 / -72 = 0
-5 % -72 = -5
julien@ubuntu:~/0x17$ python3 100-tests.py
39 + -62 = -23
39 - -62 = 101
39 x -62 = -2418
39 / -62 = 0
39 % -62 = 39
julien@ubuntu:~/0x17$
```
	* [100-operations.so](100-operations.so) - dynamic library
	* [ops.c](ops.c) - functions found in [100-operations.so](100-operations.so)
