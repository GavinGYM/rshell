#include "rshellbase.hpp"
#include <sys/wait.h>
#include<sys/types.h>
#include<cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

bool ExeArgu::Operate()
{
	pid_t pid;
	pid = fork();

	if (pid < 0) {
		perror("fork creates child process error!");
		exit(0);
	}
	else if (pid == 0) {
		if(this->argu == ""){
			char *argv[] = { const_cast<char*>(this->exe.c_str()),NULL };
			char* path = const_cast<char*>(this->exe.c_str());
			int a = execvp(path, argv);
			if (a == -1) {
				perror("execution fails!");
				exit(1);
				return false;
			}
			else {
				exit(0);
				return true;
			}	
		}
		else{
			char *argv[] = { const_cast<char*>(this->exe.c_str()), const_cast<char*>(this->argu.c_str()),NULL };
			char* path = const_cast<char*>(this->exe.c_str());
			int a = execvp(path, argv);
			if (a == -1) {
				perror("execution fails!");
				exit(1);
				return false;
			}
			else {
				exit(0);
				return true;
			}
		}
	}
	else {
		waitpid(pid, NULL, 0);
	}
}

string ExeArgu::getExe()
{
	return this->exe;
}

string ExeArgu::getArgu()
{
	return this->argu;
}
