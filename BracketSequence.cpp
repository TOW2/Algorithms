#include "Stack.h";
#include <iostream>;
#include <string>;
using namespace std;

bool isopenbracket(char symbol) {
	return (symbol == '(') || (symbol == '{') || (symbol == '[');
}

bool isMatching(char openBracket, char closeBracket) {
	return (openBracket == '(' && closeBracket == ')') || (openBracket == '{' && closeBracket == '}') || (openBracket == '[' && closeBracket == ']');
}

int main() {
	string bracketSequence = "";
	Stack sequenator;
	bool flag = 0;
	getline(cin, bracketSequence);

	for (int index = 0; bracketSequence[index] != '\0';index++) {
		if (isopenbracket(bracketSequence[index]))
			sequenator.push(bracketSequence[index]);
		else {
			if (sequenator.Empty()) {
				flag = 1;
				break;
			}
			if (isMatching(sequenator.check(), bracketSequence[index])){
				sequenator.pop();
			}
		}
	}
	if (flag || !sequenator.Empty())
		cout << "Incorrect";
	else
		cout << "Correct";

	bracketSequence.~basic_string();
	sequenator.~Stack();
	return 0;
}
//07.10.24 9:42 Стек был написан еще неделю назад, после этого задача решается за пять минут.