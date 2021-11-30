# Assignment02-283

Team 1:Yasaswi Mandava(015910583) 2:Manikanta Tanniru(015947425)

we connected over teams to finish this assignment

these are the following steps we have followed:

Here Firstly we have Forked the torvalds/linux tree and then we have Cloned the forked repo into an ubuntu machine which we was created on GCP(Google cloud platform) after that we have  Downloaded important libraries for building the kernel.

and then we have followed the steps which was given :

1:Executed sudo cp /boot/{config-name} ./.config

2:Executed sudo make oldconfig

3:Edited code in cpuid.c and vmx.c, to satify the leaf nodes 0x4fffffff ans '0x4ffffffe` requirments

4:Executed sudo make -j 8 modules

5:Executed sudo make -j 8

6:Executed make INSTALL_MOD_STRIP=1 modules_install

7:Loaded kvm using the command modprobe kvm and modprobe kvm_linux

8:Created a VM using VirtManager

9:Created a test file and executed it to see the results.


# Assignment03-283

Team 1:Yasaswi Mandava(015910583) 2:Manikanta Tanniru(015947425)

we connected over teams to finish this assignment

These are the following steps we have followed:

a:Forked the torvalds/linux tree

b:Cloned the forked repo into an ubuntu machine

c:Downloaded important libraries for building the kernel

d:Executed sudo cp /boot/{config-name} ./.config

e:Executed sudo make oldconfig

f:Edited code in cpuid.c and vmx.c, to satify the leaf nodes 0x4fffffff ans '0x4ffffffe` requirments

g:Executed sudo make -j 8 modules

h:Executed sudo make -j 8

i:Executed make INSTALL_MOD_STRIP=1 modules_install

j:Loaded kvm using the command modprobe kvm and modprobe kvm_linux

k:Created a VM using VirtManager

l:Created a test file and executed it to see the results

Manikanta :

my role is to build the kernal by cloning it.

yasaswi :

i am responsible for two leaf funcutionality of code,here i have updated the vmx.c files of the kernal

Updating vmx.c files and executed the following commands

make -j 8 modules

make INSTALL_MOD_STRIP=1 modules_install

lsmod | grep kvm

rmmod kvm_intel

rmmod kvm

lsmod | grep kvm

modprobe kvm

modprobe kvm_intel

lsmod | grep kvm
