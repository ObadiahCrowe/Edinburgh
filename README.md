# Edinburgh

##About
Edinburgh is a 64-bit operating system designed for Intel CPUs,
it requires very little resources however is fast and small by design.

The goal is to build a fast and usable operating system with clear and structured code.


##Build Info
* **OS required:** Linux 64-bit
* **Packages needed:** NASM, QEMU(For VM testing), [x86_64-ELF Cross Compiler](http://newos.org/toolchains/x86_64-elf-4.9.1-Linux-x86_64.tar.xz)


##Known bugs
Developers, please put all known bugs below so they can be fixed/worked on in an orderly manner

* None atm :D

##Roadmap
* Develop windowing system
* Rework syscalls and drivers to integrate better with Assembly
* Add FAT32 and Ext2 filesystem support
* Integrate [DundeeFS](https://github.com/ObadiahCrowe/Dundee)
* Multitasking
* Add C++ support
* Add audio drivers
* Add LAN network drivers
* Create a paging system
* Add VESA support

##Screenshots
![Basic commands](https://github.com/ObadiahCrowe/Edinburgh/raw/master/docs/img/basiccmds.png)

![Windowing system](https://github.com/ObadiahCrowe/Edinburgh/raw/master/docs/img/windowingsystem.png)
