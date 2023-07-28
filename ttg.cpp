#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

int main() {
    string input;
    string eq, out;
    ifstream file("logical_expressions2.txt");
    string a1 = "0011", a2 = "0101";
    string b1 = "00001111", b2 = "00110011", b3 = "01010101";

    // Prompt the user to enter the logical expression
    // Hints for different symbols used in logical expressions
    cout << "Symbol Hints:" << endl<<endl;
    cout << "p, q, r: Variables representing propositions." << endl;
    cout << "~ : NOT (Negation) - Reverses the truth value of a proposition." << endl;
    cout << "^ : AND (Conjunction) - Returns true if both propositions are true." << endl;
    cout << "v : OR (Disjunction) - Returns true if at least one proposition is true." << endl;
    cout << "-> : IMPLIES (Implication) - Returns false only when the antecedent is true and the consequent is false." << endl;
    cout << "<=> : IF AND ONLY IF (Biconditional) - Returns true when both propositions have the same truth value." << endl<<endl;
    cout << "Enter the logical expression (e.g., pvq, ~p^q, p->q, etc.): ";
    cin >> input;

    
    string line;

    while (getline(file, line)) {
        stringstream linestream(line);

        getline(linestream, eq, ',');
        if (eq == input) {
            getline(linestream, out, ',');
            break;
        }
    }

    cout << "Truth Table for: " << input << endl;
    cout << "+---+---+---+" << (out.length() == 8 ? "---+" : "") << endl;
    for (int i = 0; i < out.length(); i++) {
        if (out.length() == 4) {
            cout << "| " << a1[i] << " | " << a2[i] << " | " << out[i] << " |" << endl;
        } else if (out.length() == 8) {
            cout << "| " << b1[i] << " | " << b2[i] << " | " << b3[i] << " | " << out[i] << " |" << endl;
        }
    }
    cout << "+---+---+---+" << (out.length() == 8 ? "---+" : "") << endl;

    file.close();
}
