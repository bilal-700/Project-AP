# Project-AP
Different programs done for end semester project of AP using C++

## Requirments: 
- Linux
- g++

## Tasks:
- Intermediate level: 
  - PROGRAM 1: Write a program that automatically converts English text to Morse code and vice versa.

- Advanced Level: 
  - PROGRAM 2: Given two strings, write a program that efficiently finds the longest common subsequence.

  - PROGRAM 3: Given two strings, write a program that outputs the shortest sequence of character insertions and deletions that turn one string into the other.

  - PROGRAM 4: Write a function that multiplies two matrices together. Make it as efficient as you can and compare the performance to a polished linear algebra library for your language. You might want to read about Strassen’s algorithm and the effects CPU caches have. Try out different matrix layouts and see what happens.

## Steps to run code:
- Make file is also given.
- Now you can run any program file using (./Program1, ./Program2, ./Program3, ./Program4)

For Program4 you first have to install _**Eigen**_ library:
- Download eigen from here:
  - https://tutorialforlinux.com/2020/09/25/step-by-step-eigen-c-ubuntu-20-04-installation-guide/2/
- File 'eigen-git-mirror-master'is already present in parent folder.
- Copy folder into /tmp. For /tmp go to home and search in left side pane 'Other locations'. After clicking on other locations you will see 'Computer' option. Click on it. And scroll in down at third or fourth last option there will be folder /tmp.
- Now go to terminal and paste 
  - `cd /tmp/eigen*`
- Now paste following commands one by one in terminal
  - `mkdir build`
  - `cd build`
  - `sudo apt install cmake`
  - `cmake ..`
  - `make`
  - `sudo make install`
