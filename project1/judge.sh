#!/bin/bash
set -eoux pipefail
###
 # @Github: https://github.com/Certseeds/CS323-Compilers
 # @Organization: SUSTech
 # @Author: nanoseeds
 # @Date: 2020-09-19 17:59:07
 # @LastEditors: nanoseeds
 # @LastEditTime: 2020-09-19 19:16:11
### 
CMAKE_DIR="cmake-build-debug"
cmake_ensure_dir() {
  if [[ ! -d "${CMAKE_DIR}" ]]; then
    mkdir "${CMAKE_DIR}"
  fi
}
compiler() {
  cd "${CMAKE_DIR}"
  cmake ..
  make -j "$(nproc)"
  cd ..
}
run_test() {
   ./${CMAKE_DIR}/Flex.out ./test/testcase1
}
cmake_ensure_dir
compiler
run_test