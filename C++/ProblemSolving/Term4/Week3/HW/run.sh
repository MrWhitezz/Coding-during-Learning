g++-11 rand.cpp -o rand.e
g++-11 test.cpp -o test.e
while true; do
    ./rand.e > 1.in #出数据
    echo "data: "
    cat 1.in
    echo "\nrunning time: "
    time ./test.e < 1.in  #被测程序
done
