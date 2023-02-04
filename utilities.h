#include <string>
#include <random>
#include <chrono>
using namespace std;

const int NUM_TESTS = 100;

const string ANS_FILE = "Working\\answer.txt";
const string OUT_FILE = "Working\\output.txt";
const string INP_FILE = "Working\\input.txt";

const string SUB_FILE = "Submissions\\submission";
const string SOL_FILE = "Submissions\\solution";

//input1.txt
string inputName(int index) {
    return "Testcases\\input" + to_string(index) + ".txt";
}

// gen a random long long from l to r
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

long long rand(long long l, long long r){
    uniform_int_distribution<long long> rnd(l, r);
    return rnd(gen);
}


