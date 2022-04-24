#include <bits/stdc++.h>
using namespace std;

class Foo {
    mutex m;
    condition_variable cv;
    int turn = 1;
public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lk(m);
        while(turn != 2) {
            cv.wait(lk);
        }
        assert(turn == 2);
        printSecond();
        turn = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lk(m);
        while(turn != 3) {
            cv.wait(lk);
        }
        assert(turn == 3);
        printThird();
    }
};