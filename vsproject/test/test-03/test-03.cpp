// test-03.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "base\memory_pool.hpp"
#include "base/timeutils.h"
#include <iostream>
#include <thread>
using namespace std;



class Apple {
public:
    Apple() {
        id_ = 0;
        cout << "Apple()" << endl;
    }

    Apple(int id) {
        id_ = id;
        cout << "Apple(" << id_ << ")" << endl;
    }

    ~Apple() {
        cout << "~Apple()" << endl;
    }

    void SetId(int id) {
        id_ = id;
    }

    int GetId() {
        return id_;
    }
private:
    int id_;
};



void ThreadProc(ppx::base::MemoryPool<char> *mp) {
    ppx::base::TimerMeter t;
    int i = 0;
    while (i++ < 100000) {
        char* p0 = (char*)mp->allocate();

        char* p1 = (char*)mp->allocate();

        mp->deallocate(p0);

        char* p2 = (char*)mp->allocate();

        mp->deallocate(p1);


        mp->deallocate(p2);

    }
    printf("total time: %ld ms\n", t.Elapsed());
}

int main()
{
    ppx::base::TimerMeter t;
    int i = 0;
    while (i++ < 100000) {
        char* p0 = (char*)malloc(100);

        char* p1 = (char*)malloc(300);

        free(p0);

        char* p2 = (char*)malloc(500);

        free(p1);

        char* p3 = (char*)malloc(600);

        free(p2);

        free(p3);
    }
    printf("total time: %ld ms\n", t.Elapsed());


    t.Restart();
    ppx::base::MemoryPool<char> mp;
    i = 0;
    while (i++ < 100000) {
        char* p0 = (char*)mp.allocate();

        char* p1 = (char*)mp.allocate();

        mp.deallocate(p0);

        char* p2 = (char*)mp.allocate();

        mp.deallocate(p1);


        mp.deallocate(p2);

    }
    printf("total time: %ld ms\n", t.Elapsed());


    std::thread th0(ThreadProc, &mp);
    std::thread th1(ThreadProc, &mp);
    std::thread th2(ThreadProc, &mp);

    th0.join();
    th1.join();
    th2.join();

    Apple *apple = nullptr;
    {
        ppx::base::MemoryPool<Apple> mp2;
        apple = mp2.newElement(10);
        int a = apple->GetId();
        apple->SetId(10);
        a = apple->GetId();

        mp2.deleteElement(apple);
    }

    apple->SetId(12);
    int b = -4 % 4;

    int *a = nullptr;
    {
        ppx::base::MemoryPool<int, 18> mp3;
        a =  mp3.allocate();
        *a = 100;
        //mp3.deallocate(a);


        int *b =  mp3.allocate();
        *b = 200;
        //mp3.deallocate(b);

        mp3.deallocate(a);
        mp3.deallocate(b);

        int *c = mp3.allocate();
        *c = 300;
    }

    getchar();
    return 0;
}

