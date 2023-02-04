#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Result {
    bool result;
    string message;
};

// return true if AC, false if WA
Result check(vector<string> submission, vector<string> solution) {
    bool result = true;
    string message = "Accepted";

    if (solution.size() < submission.size()) {
        result = false;
        message = "Submission has too many words";
    }
    else if (solution.size() > submission.size()) {
        result = false;
        message = "Submission has too few words";
    }
    else {
        for (int i = 0; i < solution.size(); i++) {
            if (submission[i] != solution[i]) {
                result = false;
                message = "Different at position " + to_string(i + 1);
                break;
            }
        }
    }

    Result res = {result, message};
    return res; 
}