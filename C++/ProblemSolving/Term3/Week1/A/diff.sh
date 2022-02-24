g++-11 rand.cpp -o rand.e
g++-11 test.cpp -o test.e
g++-11 std.cpp -o std.e
count=0
while true; do
    ./rand.e > tmp.in #出数据
    ./test.e < tmp.in > tmp.out #被测程序
    ./std.e < tmp.in > tmp2.out #正确（暴力）程序
    if diff tmp.out tmp2.out; then #比较两个输出文件
        count=$((count+1))
        echo "AC $count times"

    elif diff -B -b tmp.out tmp2.out; then
        printf "PE\n"

    else
        printf "WA\n" #结果不同显示WA，并退出
        exit 0
    fi
done
