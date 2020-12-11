#include "start.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <map>
#include <vector>
#include <cctype>
#include <verbparse.h>

using namespace std;
start::start()


{
    //bool playing = true;

    string answer;
    char contin;
    bool quit = false;

do
    {
        verbParse();

    }

while (quit != true);
{

        cout << "what would you like to do?" << endl << "Press 'R' to Retry, 'P' to pass to the next question, or 'Q' to Quit " << endl;
        cin >> contin;
        contin = toupper(contin);
        cout << endl;


        switch (contin) {
            case 'R': cout << "Retrying" << endl << endl;
        break;
            case 'P': cout << "Passing to next question" << endl << endl;
        break;
            case 'Q': cout << "Quitting" << endl << endl;
            quit = true;

        break;
            default: cout << "I did not understand your answer! Please try again." << endl << endl;
        }
}
}


