
# Simple Shell Project

## Introduction
The Simple Shell project is an essential component of the ALX Software Engineering - Holberton Scholl curriculum, emphasizing the creation of a UNIX command line interpreter in C. The project focuses on gradually introducing complexities, from executing simple commands to handling environment variables and built-in functions.


## Installation
To clone the repository, use:
```bash
git clone https://github.com/Y4SS11N3/simple_shell.git
```

## Compilation and Execution
Compile the shell using:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Run the shell in interactive mode:

```bash
./hsh
```

Or use it in non-interactive mode:

```bash
echo "/bin/ls" | ./hsh
```

## Usage Examples
Intermediate Shell Functionality:

```bash
$ ./hsh
$ /bin/ls
[Output of /bin/ls]
$ ls
[Output of ls command, assuming PATH is handled]
$ ls -l /tmp
[Detailed list of /tmp directory]
$ ^C
```

Advanced Shell Features:

Handling environment variables:

```bash
$ ./hsh
$ env
[Displays environment variables]
$ exit
```

Exit command with status:

```bash
$ ./hsh
$ exit 98
$ echo $?
98
```

Set and unset environment variables:

```bash
$ ./hsh
$ setenv VARIABLE VALUE
$ unsetenv VARIABLE
```

Change directory with cd:

```bash
$ ./hsh
$ cd /path/to/directory
$ cd -
[Changes to the previous directory]
$ cd
[Changes to the home directory]
```

## Project Guidelines
- Adheres to the Betty coding style.
- Developed and tested on Ubuntu 20.04 LTS.
- Focuses on a comprehensive understanding of shell functionalities.


## Authors
- Yassine Mtejjal
- Anas Mouak
