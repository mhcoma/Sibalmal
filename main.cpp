#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

class Value {
	private:
		int nVal;
		double fVal;
	public:
		bool type;
		Value() {
			nVal = 0;
			fVal = 0;
			type = true;
		}
		
		template <class T>
		Value(T v) { set(v); }

		void set(int v) {
			nVal = v;
			type = true;
		}
		void set(double v) {
			fVal = v;
			type = false;
		}
		int getInt() {
			if (type) return nVal;
			else return (int)fVal;
		}
		double getFloat() {
			if (type) return (double)nVal;
			else return fVal;
		}
};

class Interpreter {
	private:
		unsigned int funcIndex;
		unsigned int codeIndex;
		unsigned int strgIndex;
		unsigned int loopLevel;
		bool loopSkip;
		vector<vector<char>> codes;
		stack<unsigned int> loopIndex;
		deque<Value> storage[26];
	public:
		void open(string fileName);
		void loop();
		bool interprete(char code);
};

void Interpreter::open(string fileName) {
	string line;
	ifstream fin(fileName);
	while (getline(fin, line)) {
		vector<char> temp;
		for (int i = 0; i < line.length(); i++)
			temp.push_back(line.at(i));
		temp.push_back('\n');
		codes.push_back(temp);
	}
	funcIndex = 0;
	codeIndex = 0;
	strgIndex = 0;
	loopLevel = 0;
	loopSkip = false;
}

void Interpreter::loop() {
	while (interprete(codes[funcIndex][codeIndex]));
}

bool Interpreter::interprete(char code) {
	if (codeIndex >= codes[funcIndex].size())
		return false;
	if (loopSkip) {
		codeIndex++;
		if (code == '\\') {
			if (loopLevel == loopIndex.size())
				loopSkip = false;
			else loopLevel--;
		}
		else
			if (code == '?')
				loopLevel++;
		return true;
	}
	switch (code) {
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z': {
			strgIndex = code - 97;
			break;
		}
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z': {
			storage[code - 65].push_front(storage[strgIndex].front());
			storage[strgIndex].pop_front();
			break;
		}
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': {
			Value a(code - 48);
			storage[strgIndex].push_front(a);
			break;
		}
		case ':': {
			Value a = storage[strgIndex].front();
			storage[strgIndex].push_front(a);
			break;
		}
		case ';': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			storage[strgIndex].push_front(b);
			storage[strgIndex].push_front(a);
			break;
		}
		case '.': {
			Value a = storage[strgIndex].back();
			storage[strgIndex].pop_back();
			storage[strgIndex].push_front(a);
			break;
		}
		case ',': {
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			storage[strgIndex].push_back(a);
			break;
		}
		case '+': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			if (a.type && b.type)
				a.set(a.getInt() + b.getInt());
			else
				a.set(a.getFloat() + b.getFloat());
			storage[strgIndex].push_front(a);
			break;
		}
		case '-': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			if (a.type && b.type)
				a.set(a.getInt() - b.getInt());
			else
				a.set(a.getFloat() - b.getFloat());
			storage[strgIndex].push_front(a);
			break;
		}
		case '*': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			if (a.type && b.type)
				a.set(a.getInt() * b.getInt());
			else
				a.set(a.getFloat() * b.getFloat());
			storage[strgIndex].push_front(a);
			break;
		}
		case '/': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			a.set(a.getFloat() / b.getFloat());
			storage[strgIndex].push_front(a);
			break;
		}
		case '%': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			if (a.type && b.type)
				a.set(a.getInt() % b.getInt());
			else
				a.set(fmod(a.getFloat(), b.getFloat()));
			storage[strgIndex].push_front(a);
			break;
		}
		case '=': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			if (a.type && b.type)
				a.set(a.getInt() == b.getInt());
			else
				a.set(a.getFloat() == b.getFloat());
			storage[strgIndex].push_front(a);
			break;
		}
		case '>': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			if (a.type && b.type)
				a.set(a.getInt() > b.getInt());
			else
				a.set(a.getFloat() > b.getFloat());
			storage[strgIndex].push_front(a);
			break;
		}
		case '<': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			if (a.type && b.type)
				a.set(a.getInt() < b.getInt());
			else
				a.set(a.getFloat() < b.getFloat());
			storage[strgIndex].push_front(a);
			break;
		}
		case '&': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			a.set(a.getInt() && b.getInt());
			storage[strgIndex].push_front(a);
			break;
		}
		case '|': {
			Value b = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			a.set(a.getInt() || b.getInt());
			storage[strgIndex].push_front(a);
			break;
		}
		case '~': {
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			a.set(!a.getInt());
			storage[strgIndex].push_front(a);
			break;
		}
		case '#': {
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			cout << a.getInt();
			break;
		}
		case '^': {
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			cout << a.getFloat();
			break;
		}
		case '@': {
			Value a = storage[strgIndex].front();
			storage[strgIndex].pop_front();
			cout << char(a.getInt());
			break;
		}
		case ' ': {
			storage[strgIndex].pop_front();
			break;
		}
		case '`': {
			Value a;
			string tempStr;
			int pos, tempInt;
			double tempFloat;
			cin >> tempStr;
			pos = tempStr.find('.');
			if (pos != string::npos) {
				try {
					tempFloat = stof(tempStr);
				}
				catch (std::invalid_argument ia) {
					tempFloat = -1;
				}
				tempInt = (int)tempFloat;
				if (tempInt != tempFloat)
					a.set(tempFloat);
				else
					a.set(tempInt);
			}
			else {
				try {
					tempInt = stoi(tempStr);
				}
				catch (std::invalid_argument ia) {
					tempInt = -1;
				}
				a.set(tempInt);
			}
			storage[strgIndex].push_front(a);
			break;
		}
		case '\'': {
			Value a;
			char tempInt;
			cin.get(tempInt);
			a.set((int)tempInt);
			storage[strgIndex].push_front(a);
			break;
		}
		case '\"': {
			unsigned int end = storage[strgIndex].front().getInt();
			storage[strgIndex].pop_front();
			Value a;
			string tempStr;
			if (end == '\0')
				cin >> tempStr;
			else 
				getline(cin, tempStr, (char)end);
			a.set(0);
			storage[strgIndex].push_front(a);
			for (int i = tempStr.length() - 1; i >= 0; i--) {
				a.set(tempStr.at(i));
				storage[strgIndex].push_front(a);
			}
			break;
		}
		case '?': {
			if (storage[strgIndex].size() > 0) {
				Value a = storage[strgIndex].front();
				storage[strgIndex].pop_front();
				if (a.getInt()) {
					loopIndex.push(codeIndex - 1);
					loopLevel++;
				}
				else
					loopSkip = true;
			}
			else
				loopSkip = true;
			break;
		}
		case '\\': {
			codeIndex = loopIndex.top();
			loopIndex.pop();
			loopLevel--;
			break;
		}
		case '!': {
			loopSkip = true;
			break;
		}
	}
	codeIndex++;
	return true;
}

int main(int argc, char** argv) {
	string fileName;
	Interpreter inter;
	if (argc > 1)
		fileName = argv[1];
	else
		cin >> fileName;
	if (fileName != "") {
		inter.open(fileName);
		inter.loop();
	}
}
