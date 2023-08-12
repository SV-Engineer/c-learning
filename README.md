# c-learning
This repository is used to create a personal reference of more advanced C concepts; starting from the base axioms. The tutorials below assume basic knowledge of git. Please refer to a git tutorial via youtube or the official [git documentation](https://docs.github.com/en/get-started/quickstart).

# Getting Started
## Compiler Installation for Windows 10
1. Download the download the [mingw compiler](https://sourceforge.net/projects/mingw/files/latest/download) from [Sourceforge](https://sourceforge.net/projects/mingw/).

2. Launch the exe file once the download is complete. 
  * Leave the install path at the default location \([highlighted](#markdown-style) below.\).
  * When prompted, ensure you enable the gui installation. [^1]

3. After installation occurs, launch the GUI \(graphical user interface[^2]\). If you left the path at the default location, it should be at:
  > C:\MinGW\libexec\mingw-get\guimain.exe

4. You should see a window as pictured [below](#mingw-installation-manager)[^3].

5. Select for installation. This can be changed at anytime later.
  * For C Language installation, right click the `mingw32-base` option and select the "[Mark for Installation](#mingw-marking-for-installation)" option.
  * For C++ Language installation, right click the `mingw32-gcc-g++` option and select the "[Mark for Installation](#mingw-marking-for-installation)" option.

6. Install your selections by clicking the "Installation" tool bar item and selecting "Apply Changes" in the resulting [drop down](#mingw-installing-selected-items).

7. Verify your installation by pressing the windows key <kbd>Windows</kbd>, typing "cmd" and pressing "Enter" <kbd>Return</kbd>. In the prompt type the path to the gcc executable:
  > C:\MinGW\bin\gcc.exe -v

8. The install was successful if you see a multiline output that has a final line that states:
  > gcc version x.x.x (MinGW.org GCC-x.x.x-x)[^4]

9. To complete setup, we must add the gcc compiler to the [path](#mingw-adding-to-path) environment variable.

## Compiler Installation Reference Images
### Mingw Splash Screen
![mingw_splash](./resources/mingw/mingw_splash.PNG)

### Mingw Install Choices
![mingw_install_choices](./resources/mingw/mingw_install_choices.PNG)

### MinGW Installation Manager
![mingw_install_mgr_prim](./resources/mingw/mingw_installation_manager_primary.PNG)

### MinGW Marking For installation
![mingw_mark_for_install](./resources/mingw/mark_for_installation.PNG)

### MinGW Installing Selected Items
![mingw_install_selected](./resources/mingw/install_selected.PNG)

<div style="page-break-after: always"></div>

## MinGW Adding To Path
1. Press the windows key <kbd>Windows</kbd> and select the first option that comes up when `environment` is entered into the search bar.

2. Once the window titled "System Properties" is open, if not on the "Advanced" tab, switch to it. Near the bottom of the window is a button with the label "Environnment Variables...", click on it.

3. The resulting window is divided into two primary sections; "User variables" and "System variables". In the system variables space highlight the "Path" entry in the "Variable" column by left clicking it.

4. With the "Path" entry still highlighted, click the "Edit..." button beneath the "System Variables" section.

5. A new window titled "Edit environment variable" should now be open. Select the "New" button at the top of the column of buttons on the right region of the screen.

6. A section for text entry should appear. Type or copy and paste the following in the text entry:
  > C:\MinGW\bin\

7. Now press the "OK" button on the current window as well as the others that opened.

8. Verify this worked by pressing the windows key <kbd>Windows</kbd>, typing "cmd" and pressing "Enter" <kbd>Return</kbd>. In the prompt type:
  > gcc -v

  * If you installed c++ you can also try:
  > g++ -v

9. If you see the same output as before when the compiler installation was initially verified, then you are done with compiler installation and setup.

<div style="page-break-after: always"></div>

## Compilation Via Command Line
Open the command line by pressing the windows key <kbd>Windows</kbd>, typing "cmd" and pressing "Enter" <kbd>Return</kbd>.

### Tool Invocation
The gcc compiler can be invoked with the command `gcc` or `g++` in the case of C++[^5]. Using the command line on any OS \(Operating System\) is a powerful tool and if you aren't familiar with it, it may be a good idea to learn more. If you want to learn more about the Windows command line, please refer to its [documentation](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/windows-commands). To see a list inputs \(A.K.A switches\) try typing `gcc --help` to see the options available.

### Compiling your first C file
  1. This repository contains a directory called "src" which is short hand for source. Located in that directory is a file called "HelloWorld.c".[^6]

  2. From the command line, navigate to the src directory. The source directory will be different for everyone, depending on where the reader has cloned it. The windows command `cd`[^7] will be used here. It is reasonable to open the windows file explorer and navigate to the src folder and copy-paste from the address bar. For the author, the command looks like:

    `cd /d N:\Development\c-learning\src`[^8]

  3. The `cd` command can also show you your current directory (Windows not Linux). Try `cd` on the command line to verify the command prompt is in the correct place. The `dir` command shows the contents of the directory you are located. Try `dir` now. At minimum this command should output at the end "1 File\(s\)" and "2 Dir\(s\)".[^9] One of those files in the list should be HelloWorld.c

  4. To compile the HelloWorld.c file, we will now invoke the compiler with the command:

    `gcc HelloWorld.c -o hello.exe`

  5. In the same directory there should now be a file called "hello.exe" \(The `dir` command can help\) and you can invoke that from the command line as well by typing `hello.exe`. The output should look like: "Hello World!".

  6. Lastly it is now safe to remove the executable or exe file with the command: `del hello.exe`.

# Footnotes
[^1]: You may uncheck the start menu and desktop shortcut creation options circled in red. You likely will not use those shortcuts if created.
[^2]: Sometimes pronounced as an acronym G.U.I. and sometimes pronounced as a word "gooey".
[^3]: In the referenced image, the tick boxes for "mingw32-base" and "mingw32-gcc-g++" are green. If you do **not** want to install c++ then do not select the second item "mingw32-gcc-g++."
[^4]: Where the 'x' character is replaced by numbers.
[^5]: From here on out, C++'s existence will be ignored as that languages' features go beyond the scope of this repository's purpose.
[^6]: Note that the file name does not contain spaces. While most OS's provide support for spaces in folder names and files names, when dealing with coding of any form, it is best to use no spaces in the naming convention you choose. This [blog](https://cscareerline.com/camel-case-vs-snake-case/) found with a cursory google search seems to do an okay job of explaining the two currently most popular naming conventions.
[^7]: `cd` is the command for change directory.
[^8]: Note that the \/d option was provided because the repository is not located on the same disc as the Author's OS.
[^9]: Notice that 1 directory is called '.' and another is called '..'. These represent the current directory and the parent directory respectively.
