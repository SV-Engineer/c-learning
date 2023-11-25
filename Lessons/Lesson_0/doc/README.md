# Lesson 0 - Gitting Started With Git

## Git download and Install
1. Download git from the [official website](https://git-scm.com/downloads)
2. Run the executable and install it.
  * Ensure you install git bash as well (makes unix commands available through the shell and thus adds loads of value).
3. Press the windows key <kbd>Windows</kbd>, type "cmd" and pressing "Enter" <kbd>Return</kbd>
4. In the command prompt that opens, type the command ```git --help``` and ensure a help message is printed rather than an error message stating that git is not a command that is found.
5. Assuming step 4 was successful, use the following commands:
  ```
  git config --global user.name "Your Name Here"
  git config --global user.email yourEmail@example.com
  ```
6. Now you should be able to clone this repository with the `clone` command passed to git (run this command from the directory you want the files to be stored).
  ```
  git clone https://github.com/SV-Engineer/c-learning.git
  ```
7. In the future, as more is added to this repository, you can use the following command to retrieve the latest version of the files:
  ```
  git pull origin master
  ```
Just make sure you run that command on a terminal that has the top level directory of this repository open.

## Compilation From The Command Line
1. Change directory to C-Learning/Lessons/Lesson_0/src
2. Use the following command:
  ```
  gcc HelloWorld.c -o HelloWorld.exe
  ```
3. Once compilation is successful, try running the command `HelloWorld.exe`
4. If the console outputs "Hello World!" then you have completed this lesson.
5. Move on to Lesson_1
