# To use with WSL

## Setup WSL 2 with an ubuntu Distro following the steps of:

https://code.visualstudio.com/remote-tutorials/wsl/getting-started

## Setup the Display following the steps:

1. Install vcxsrv from https://sourceforge.net/projects/vcxsrv/
2. Open vcxsrv in Windows, select start no client, also check disable access control. When launch allow privade an public network access in firewall
3. Once in vsCode add the display ev variable (To see the ip adress  use cat /etc/resolv.conf):

   export DISPLAY=$(awk '/nameserver / {print $2; exit}' /etc/resolv.conf 2>/dev/null):0
   export LIBGL_ALWAYS_INDIRECT=1

## Build

gcc -Wall -g threadVilleSimulator.c -o threadVilleSimulator `pkg-config --cflags gtk+-3.0` \
    `pkg-config --libs gtk+-3.0`