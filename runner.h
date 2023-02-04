#include <iostream>
#include <string>
using namespace std;

struct Runner {
    // compile("Submissions/solution.cpp")
    // g++ -std=c++14 -O2 {file}.cpp -o {file}
    bool compile(string file) {
        string cmd = "g++ -std=c++14 -O2 " + file + ".cpp -o " + file;
        if (system(cmd.c_str()) == 0) {
            cout << "Compile " << file << " successfully" << endl; 
            return true;
        }
        else {
            cout << "Compile errors in " << file << endl;
            return false;
        }
    }

    // return false if having RTE
    // {file}.exe < input > output
    bool run(string file, string input, string output) {
        string cmd = file + ".exe < " + input + " > " + output;
        if (system(cmd.c_str()) != 0) { //RTE
            cout << "Run Time Error" << endl;
            return false;
        }
        return true;
    }
};