#ifndef STACK_H
#define STACK_H

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout;
#include <sstream>
using std::istringstream;
using std::getline;


// TODO: Your code goes here

class Stack {
private:
    vector<double> v;

public:
    bool empty() const {
        return (v.size() == 0);
    }

    double pop() {
        if (empty()) {
            cout << "Empty string, cannot pop!\n";
            exit(EXIT_FAILURE);
        }
        double d = v.back();
        v.pop_back();
        return d;
    }

    void push(const double & d) {

        v.push_back(d);
    }

    double front() const {
        return v.back();
    }
};

vector<string> split(const string & str, char delimiter) {
	vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

double evaluate(const string & rpn) {
    Stack stack;
    vector<string> tokens = split(rpn, ' ');

    if (tokens.empty()) {
        return 0.0;
    }

    for (int i = 0; i < tokens.size(); i++) {

        double a = 0.0;
        double b = 0.0;

        if (tokens[i] == "+") {
            if (!stack.empty()) a = stack.pop();
            if (!stack.empty()) b = stack.pop();
            stack.push(b+a);
        } else if (tokens[i] == "-") {
            if (!stack.empty()) a = stack.pop();
            if (!stack.empty()) b = stack.pop();
            stack.push(b-a);
        } else if (tokens[i] == "*") {
            if (!stack.empty()) a = stack.pop();
            if (!stack.empty()) b = stack.pop();
            stack.push(b*a);
        } else if (tokens[i] == "/") {
            if (!stack.empty()) a = stack.pop();
            if (!stack.empty()) b = stack.pop();
            stack.push(b/a);
        } else {
            stack.push(std::stod(tokens[i]));
        }
    }

    return stack.front();
}

// Do not write anything below this line

#endif
