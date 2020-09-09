#!/bin/bash
set -eoux pipefail
main() {
    dire="cmake-build-debug"
    if [ -d "${dire}" ]; then
        rm -rf "${dire}"
    fi
    if [[ ! -d "${dire}" ]]; then
        mkdir "${dire}"
    fi
    cd "${dire}"
    cmake ..
    make
    ./CS323-Compliers-lab01_hello.out
    ./CS323-Compliers-lab01_ll_main.out
    mv libll.so ./../libll.so
    cd ..
    python3 ./ll_test.py
}

main
