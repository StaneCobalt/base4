# Base4 to Base10
### by Stephen Sladek

This is a simple C++ program that I got inspired to do after my discrete structures class.
It converts base10 numbers (aka decimal system numbers) to base4 using a set where S = { A, B, C, D }.

#### Example of some conversions

base10 | base4
--- | ---
1 | A
4 | BA
15 | DD
16 | BAA
50 | DAC
64 | BAAA

## Building the app
I like to use MinGW to build my C/C++ applications. You can pick up a copy at https://nuwen.net/.
If you're installing for the first time, you'll want to run the set_distro_paths batch file to set your path. You only need to do this once. After that just use the open_distro_window batch file to run MinGW.

In order to build just follow these steps:
1. Open up MinGW and navigate to the Source Folder
2. Use the following command: `g++ convertBase.cpp -o convertBase.exe`
3. After the executable is created just type `convertBase.exe` to run the file
