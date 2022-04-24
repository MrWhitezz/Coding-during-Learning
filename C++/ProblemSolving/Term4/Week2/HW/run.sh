g++-11 rand.cpp -o rand.e
while true; do
    ./rand.e fast > 1.in #出数据
    ./rand.e slow > 2.in #出数据
    echo "fast instance:"
    cat 1.in
    time ./test.e < 1.in > tmp.out #被测程序
    echo "slow instance:"
    cat 2.in
    time ./test.e < 2.in > tmp.out #被测程序

done
