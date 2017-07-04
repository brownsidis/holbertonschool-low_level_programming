# 0x14. C - File I/O
This is an introductory project to creating, opening, reading, and writing files.
## File Descriptions
* **0-read_textfile.c** - a function with the prototype `ssize_t read_textfile(const char *filename, size_t letters);` that reads a text file and prints it to the POSIX standard output with the specifications:
  * `filename` is the name of the file to print
  * If `filename` is `NULL`, returns `0`
  * `letters` is the number of letters to read and print
  * Returns number of letters printed on success and `0` on failure
* **1-create_file.c** - a function with the prototype `int create_file(const char *filename, char *text_content);` that creates a file with the specifications:
  * `filename` is the name of the file to create
  * `text_content` is a `NULL` terminated string to write to the file
  * If `filename` is `NULL`, returns `-1`
  * If `text_content` is `NULL`, creates an empty file
  * The file is truncated if it already exists
  * The created file will have the permissions: `rw-------`
  * Returns `1` on success and `-1` on failure
* **2-append_text_to_file.c** - a function with the prototype `int append_text_to_file(const char *filename, char *text_content);` that appends text at the end of a file with the specifications:
  * `filename` is the name of the file
  * If `filename` is `NULL`, returns -1
  * Does not create the file if it does not exist
  * `text_content` is the `NULL` terminated string to add at the end of the file
  * If `text_content` is `NULL`, does not add anything to the file.
  * Returns `1` on success and `-1` on failure
* **3-cp.c** - a program that copies the content of a file to another file.
