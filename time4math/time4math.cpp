#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "only4math.h"

using namespace std;

int main()
    {
    string dota2;
    cout << "Welcome To C++ Calculator!" << endl << "Type Something Below" << endl;
    getline(cin, dota2);
    Analyze(dota2, size(dota2));    
}
