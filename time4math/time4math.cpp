#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <chrono> 
#include <thread>
#include <windows.h>
#include "MathHandler.h"
#include "WxUI.h"

using namespace std;
using namespace std::chrono;

void start()
{
    string dota2;
    double startTime, endTime;
    funcAnimateText("Welcome To C++ Calculator!");
    funcAnimateText("Type Something Below!");
    getline(cin, dota2);
    auto begin = steady_clock::now();
    if (dota2 == "UI")
    {
        system("start CppCLR_WinForms_GUI1.exe");
        system("taskkill /IM time4math.exe");
    }
    funcAnalyze(dota2, size(dota2));
    auto end = steady_clock::now();
    float elapsed_sec = duration_cast<seconds>(end - begin).count();
    float elapsed_ms = duration_cast<milliseconds>(end - begin).count();
    float elapsed_mcs = duration_cast<microseconds>(end - begin).count();
    float elapsed_ns = duration_cast<nanoseconds>(end - begin).count();
    cout << "Task Has Been Solved For : " << elapsed_sec << " sec | " << elapsed_ms << " ms | " << elapsed_mcs << " mcs | " << elapsed_ns << " ns | " << endl;
    getchar();
    getchar();
    system("cls");
    start();
}

int main()
{
    system("cls");
    start();
}
