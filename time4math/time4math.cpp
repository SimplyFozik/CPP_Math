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

void funcAnimateText(string text)
{
    for (int i = 0; i < text.size(); i++)
    {
        cout << text[i];
        Sleep(10);
    }
    cout << endl;
}

int main()
    {
    string dota2;
    double startTime, endTime;
    funcAnimateText("Welcome To C++ Calculator!");
    funcAnimateText("Type Something Below!");
    getline(cin, dota2);
    auto begin = steady_clock::now();
    funcAnalyze(dota2, size(dota2));
    auto end = steady_clock::now();
    float elapsed_sec = duration_cast<seconds>(end - begin).count();
    float elapsed_ms = duration_cast<milliseconds>(end - begin).count();
    float elapsed_mcs = duration_cast<microseconds>(end - begin).count();
    float elapsed_ns = duration_cast<nanoseconds>(end - begin).count();
    cout << "Task Has Been Solved For : " << elapsed_sec << " sec | " << elapsed_ms << " ms | " << elapsed_mcs << " mcs | " << elapsed_ns << " ns | " << endl;
}
