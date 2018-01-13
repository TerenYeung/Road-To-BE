'''
learn point:
1. os.stat()
2. Unix File Management
'''

'''
notes:
1. What is Unix ?

a set of programs, also called OS that act as a link between the computer and the user.

Sereral people can use a Unix computer at the same time. Hence Unix is called a multiuser system.


A user can also run multiple programs at the same time. Hence Unix is a multitasking environment.

2. What is OS or kernel ?

the computer programs that allocate the system resources and coordinate all the details of the computer's internals

3. What is the shell ?

Users communicate with the kernel through a program know as the shell.

The shell is command line interpreter, and it translates commands entered by the user and converts them into a language that is understood by the kernel.

4. Unix Architecture
[](https://www.tutorialspoint.com/unix/images/unix_architecture.jpg)

All the data of Unix is organized into files. All files are then organized into directorires. These directories are further organized into a tree-like structure called the filesystem.

5. File Management

In Unix, there are three basic types of files:

- Orinary Files
An ordinary file is a file onthe system that contains data, text, or program instrucations.

- Directories
Directories store both special and ordinary files.

- Special FIles
Some special files provide access to hardware

- File Permission

Every File in Unix has the following attributes:

  Owner permissions
  Group persmissions
  Other persmissions

use ls -l can display various infomation related to file permission

drwxr-xr-x  9 terenyeung  staff  306 Dec 12 00:02 DATABASE
drwxr-xr-x  6 terenyeung  staff  204 Dec 23 23:17 PYTHON
-rw-r--r--  1 terenyeung  staff   35 Dec  6 23:25 README.md

File Access Modes

Read: view the contents of the file
Write: modify or remove the content of the file
Execute: run a file as a program

Changing Permissions
chmod u+x fileinfo.py
chmod o+wx fileinfo.py
chmod g=rwx fileinfo.py
'''