#!/bin/bash
set -eoux pipefail
###
# @Github: https://github.com/Certseeds/CS323-Compilers
# @Organization: SUSTech
# @Author: nanoseeds
# @Date: 2020-09-16 16:36:39
 # @LastEditors: Please set LastEditors
 # @LastEditTime: 2020-09-16 18:45:03
###
CMAKE_DIR="cmake-build-debug"
main() {
  flex ./lex.l
  gcc lex.yy.c --shared -fPIC -o libip.so
  python3 ./ip_test.py
}
clean() {
  rm ./lex.yy.c libip.so
}
cmake_ensure_dir() {
  if [[ ! -d "${CMAKE_DIR}" ]]; then
    mkdir "${CMAKE_DIR}"
  fi
}
compiler() {
  cd "${CMAKE_DIR}"
  cmake ..
  make -j "$(nproc)"
  cp ./libip.so ./../libip.so
  cd ..
}
run_test() {
  python3 ./ip_test.py
}
cmake_ensure_dir
compiler
run_test
