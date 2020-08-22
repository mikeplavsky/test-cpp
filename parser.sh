g++ -std=c++17 \
    -O2 \
    -Wall \
    -pedantic \
    -pthread parser.cpp && \
    cat parser.txt | ./a.out
