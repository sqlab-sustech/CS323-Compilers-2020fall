#!/bin/bash
set -eoux pipefail
###
 # @Github: https://github.com/Certseeds/CS323-Compilers
 # @Organization: SUSTech
 # @Author: nanoseeds
 # @Date: 2020-09-17 12:06:16
 # @LastEditors: Please set LastEditors
 # @LastEditTime: 2020-09-20 17:12:30
### 
main(){
    # build essential include gcc and make
    sudo apt install build-essential
    # get flex and bison
    sudo apt install flex bison
    # get python's pip
    # you can change to anaconda,miniconda or use system's python
    sudo apt install python3-pip
    #? dont forget to change pip's repo address to aliyun, hust or any other.
    
    # `` this command can not run on ubuntu,
    # use this command to download urwid
    pip3 install urwid -i http://pypi.hustunique.com/
    # Do not use sudo pip3 install urwid

    # install Spim
    sudo apt install spim
}
extra(){
    # if you want to use cmake
    sudo pip3 install cmake==3.17.2
}
# + GCC version 7.4.0
# + GNU Make version 4.1
# + GNU Flex version 2.6.4
# + GNU Bison version 3.0.4
# + Python version 3.6.8
# + urwid (Python module) 2.0.1
# + Spim version 8.0
main
# extra