#include <fstream>
#include "utilities.h"
#include "Checker/matching.h"
#include "runner.h"
using namespace std;

void copyInput(int index) {
    string cmd = "copy /Y " + inputName(index) + " " + INP_FILE;
    system(cmd.c_str());
}

vector<string> readFile(string file) {
    ifstream inp(file.c_str());
    string s;
    vector<string> res;
    while (inp >> s) {
        res.push_back(s);
    } 
    return res;
}

int main() {
    Runner runner;
    if (runner.compile(SUB_FILE) == false) {
        return 0;
    }
    if (runner.compile(SOL_FILE) == false) {
        return 0;
    }    

    for (int index = 1; index <= NUM_TESTS; index++) {
        copyInput(index);
        cout << "Test " << index << endl; 
        
        if (runner.run(SOL_FILE, INP_FILE, ANS_FILE) == false) {
            return 0;
        }
        if (runner.run(SUB_FILE, INP_FILE, OUT_FILE) == false) {
            return 0;
        }
        
        vector<string> sol = readFile(ANS_FILE);
        vector<string> sub = readFile(OUT_FILE);

        Result res = check(sub, sol);
        if (res.result == false) {
            cout << "Wrong Answer" << endl;
            cout << res.message << endl;
            return 0;
        }
    }
    cout << "Accepted" << endl;

    return 0;
}