#include <string>
#include <vector>
#include <climits>
using namespace std;

class ExeArgu;
class Connector;
class Command;

class Rshellbase {
private:
	string input;
public:
	Rshellbase(string s) : input(s) {}
	Rshellbase() {};
	~Rshellbase() {
		delete &this->input;
	}

	void Operate() {};

	bool Disintegrate(vector<ExeArgu*> &exeargu, vector<Connector*> &connector,vector<Command*> &command);
};


class ExeArgu : public Rshellbase {
private:
	string exe;
	string argu;
	vector<int> leftP;
	vector<int> rightP;
public:
	ExeArgu(string e, string a) : exe(e), argu(a) {}
	~ExeArgu() {
		delete &this->exe;
		delete &this->argu;
	}
	bool Operate();
	string getExe();
	string getArgu();
	vector<int> getLeftP();
	vector<int> getRightP();
	void setLeftP(int i);
	void setRightP(int i);
	void setExeL();
	void setExeR();
	void setArgu();
};

class Connector : public Rshellbase {
private:
	char sign;
public:
	Connector() {}
	Connector(char c) : sign(c) {}
	~Connector() {
	}
	bool Operate(bool result);
	char GetSign();
};

class Command : public Rshellbase {
private:
	ExeArgu *exeArgu;
	Connector *connector;
public:
	Command(ExeArgu *e, Connector *c) : exeArgu(e), connector(c) {}
	~Command() {
		delete &this->exeArgu;
		delete &this->connector;
	}
	bool Operate();
	Connector * GetConnector(){
		return this->connector;
	}
};
