# get_next_line

![MARK](https://raw.githubusercontent.com/Gtalavero/get_next_line/master/assets/success115.PNG)

"GNL" is a project at [42 school][1] that basically reads a file line by line from a file descriptor.

**You can read the subject in** [this link][2].

get_next_line returns -1, 0, 1 depending on wether an error has occurred, the reading has been completed or a line has been read respectively.

**Note:** There are so many easier methods of doing this using standar C functions, but the goal here is to be able to do it by using just our owns functions and only the standards `read`, `malloc` and `free`.

### I got it but... why would I use/try it?
The only reason to use this function would be that you were a student of 42 and want to see how it works before code the yours. The goal is to get better at C.

After finishing this project, you'll definitely learn some more about static variables, pointers, arrays, linked lists (if you decide to do the bonus part), dynamic memory allocation and file manipulation.

### How do I use it
First, clone the repo.

	git clone https://github.com/Gtalavero/get_next_line

I added a `main.c` that will read and print all the lines together of a `text.txt` file in the same directory. If you want to read by arguments, there is also commented code that does this.

Then, build the executable with:

	gcc -Wall -Wextra -Werror get_next_line.c get_next_line.h get_next_line_utils.c

**Note:** Forget the "*_bonus.*", are the same.

And run it:

	./a.out

[1]: https://www.42madrid.com/ "42 Madrid"
[2]: https://github.com/Gtalavero/get_next_line/blob/master/assets/gnl.subject.pdf "GNL subject"

