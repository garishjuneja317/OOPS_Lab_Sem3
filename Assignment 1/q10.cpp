#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
void executeProgram(const vector<string>& program) {
    unordered_map<string, int> memory;
    int pc = 0; 
    while (pc < program.size()) {
        stringstream ss(program[pc]);
        string command;
        ss >> command;
        if (command == "LET") {
            string var;
            int val;
            ss >> var >> val;
            memory[var] = val;
            pc++;
        } else if (command == "ADD") {
            string var;
            int val;
            ss >> var >> val;
            memory[var] += val;
            pc++;
        } else if (command == "PRINT") {
            string var;
            ss >> var;
            cout << memory[var] << endl;
            pc++;
        } else if (command == "IF") {
            string var, op;
            int val;
            ss >> var >> op >> val;
            bool conditionMet = false;
            if (op == "==" && memory[var] == val) {
                conditionMet = true;
            }
            if (op == "!=" && memory[var] != val) {
                conditionMet = true;
            }
            if (conditionMet) {
                pc++;
            } else {
                int depth = 1;
                while (depth > 0 && pc < program.size()) {
                    pc++;
                    stringstream skip_ss(program[pc]);
                    string skip_cmd;
                    skip_ss >> skip_cmd;
                    
                    if (skip_cmd == "IF") depth++;
                    if (skip_cmd == "ENDIF") depth--;
                }
                pc++;
            }
        } else if (command == "ENDIF") {
            pc++;
        } else if (command == "WHILE") {
            string var, op;
            int val;
            ss >> var >> op >> val;
            bool conditionMet = false;
            if (op == "<" && memory[var] < val) conditionMet = true;
            if (conditionMet) {
                pc++;
            } else {
                int depth = 1;
                while (depth > 0 && pc < program.size()) {
                    pc++;
                    stringstream skip_ss(program[pc]);
                    string skip_cmd;
                    skip_ss >> skip_cmd;
                    
                    if (skip_cmd == "WHILE") depth++;
                    if (skip_cmd == "ENDWHILE") depth--;
                }
                pc++;
            }
        } else if (command == "ENDWHILE") {
            int depth = 1;
            while (depth > 0 && pc >= 0) {
                pc--;
                stringstream skip_ss(program[pc]);
                string skip_cmd;
                skip_ss >> skip_cmd;
                
                if (skip_cmd == "ENDWHILE") depth++;
                if (skip_cmd == "WHILE") depth--;
            }
        }
        else {
            pc++;
        }
    }
}
int main() {
    vector<string> sourceCode = {
        "LET x 0",
        "WHILE x < 3",
        "  ADD x 1",
        "  PRINT x",
        "  IF x == 2",
        "    PRINT x",
        "  ENDIF",
        "ENDWHILE"
    };
    executeProgram(sourceCode);
    return 0;
}
