<h1 align="center">get_next_line - Reading a line from a fd is way too tedious</h1>
</br>

The goal of this function is to return a line read from a file descriptor.
</br>
## Concepts introduced in this project 🔮
- [Static Variables](https://www.geeksforgeeks.org/static-variables-in-c/https://www.geeksforgeeks.org/static-variables-in-c/)
- [File Discriptors](https://en.wikipedia.org/wiki/File_descriptor#:~:text=In%20Unix%20and%20Unix%2Dlike,a%20pipe%20or%20network%20socket.)
- [Reading/Opening/Closing/writing files](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)
- [Buffer in C](https://www.educative.io/answers/what-is-a-buffer-in-c#:~:text=C%20uses%20a%20buffer%20to,next%20input%20is%20taken%20in.)

## Diagram on how the function works 📊
<img align="right" src="https://user-images.githubusercontent.com/113459534/221387040-7081f52a-fe55-4287-b29c-22ef11d7ce59.jpg"/>
</br>

## Code 🧬

- get_next_line takes a file discriptor as an argument and reads from it using repeated calls (loop) one line at a time.

> The prototype of get_next_line(int fd) is :

```c
char	*get_next_line(int fd);
```
</br> 

- The function should return the line that was read otherwise NULL. 
</br>

- The returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.

## Usage

Compile the code

of course we would need a main function, either write one inside the ``get_next_line.c`` file or by creating a main file ``main.c``

```c
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd;
	char *line;

	fd = open("PATH", O_RDONLY);
	line = get_next_line(fd);
	printf("|%s|", line);
	free(line);
	return (0);
}
```
Compile the library that was created earlier with the ``main.c`` :

```bash
gcc main.c get_next_line.c get_next_line_utils.c get_next_line.h
```
Run the program :
```bash
./a.out
```
