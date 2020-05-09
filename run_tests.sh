rm main *.o
gcc -c array.c array_void.c test/*.c && gcc -o main *.o && ./main