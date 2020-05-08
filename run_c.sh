#! /bin/bash

rm main *.o
gcc -c *.c && gcc -o main *.o && ./main
