## Assignment 2: Rshell

Rshell is a computer program reads in a command line, then executes them.
It can run commands such as a custom built exit command as well as commands from the std library. 
Our objective for this assignment is to enable our program to handle single commands as well as
multiple commands that are connected by connectors, such as "&&", "||", ";". 
It should also recognize comment command, "#" and ignore anything typed after it for the rest of the line.

## Code Example

$ ls

License  README.md  bin  hw2  makefile  src  tests

$ echo hello

hello


## Tests

There are four test scripts included in the tests directory.

1) single commands

2) multiple commands

3) commands with exit

4) commands with comment

## Known Bugs

echoing more than one string will return error

for example, echo hello works but not echo hello world

unable to use cd command, returns error(file or directory not found)

## License

The License we are using is the GNU General Public License v3.
