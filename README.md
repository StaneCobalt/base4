# Base 10 to Base N
### by Stephen Sladek

This is a simple C++ program that I got inspired to do after my discrete structures class.
It converts base 10 numbers (decimal system) to a new base with the set S = { A, ..., n }.

#### Example of some conversions

base 10 | base 4 | base 2
--- | --- | ---
1 | A | B
4 | BA | BAA
15 | DD | BBBB 
16 | BAA | BAAAA
50 | DAC | BBAABA
64 | BAAA | BAAAAAA

## Building the app
I like to use MinGW to build my C/C++ applications. You can pick up a copy at https://nuwen.net/.
If you're installing for the first time on Windows, you'll want to run the set_distro_paths batch file to set your path. You only need to do this once. After that just use the open_distro_window batch file to run MinGW. If you have linux, you probably already have gcc/g++ installed. Try typing `gcc --version` to make sure.

In order to build just follow these steps:
1. Open up MinGW and navigate to the Source Folder
2. Use the following command: `make all`
3. After the executable is created just type `base.exe` to run the file
4. First input the number you wish to convert, then the base you wish to use. You can also enter these in when you call the exe file!
Example: `base.exe 16 4`
