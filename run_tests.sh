rm main *.o
gcc -c array.c test/*.c && gcc -o main *.o && ./main