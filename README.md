# PAUSE
------
### Motivation
Our purpose in creating this software was to bring one of Microsoft Windows most fundamental system-services to unix systems. We hope our contribution will help developers all over the world to easily deploy their projects to other systems.

### Description
-------
PAUSE redefines the service called throughout the "PAUSE" command on Microsoft Windows host systems. The basic tasks are:
* the OS locates the PAUSE program
* allocate the memory to execute the command
* execute the command and wait for a keystroke
* deallocate the memory
* exit the OS and resume the program

### Build
**1. Get the repository**
#### https
```https
git clone https://github.com:Frzifus/PAUSE.git
```

**2. Navigate to the repo and execute**
```bash
make -j4
```

### Install and uninstall
-----
**Execute as privileged user**
```bash
make install
#or
make uninstall
```
