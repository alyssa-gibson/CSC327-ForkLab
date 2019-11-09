//============================================================================
// Name        : ForkLab.cpp
// Author      : Alyssa Gibson
// Version     :
// Copyright   : 
// Description : ForkLab - Linux Programming
//============================================================================

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
	int depth;
	int deep = 0;
	while (deep == 0) {
		cout << "Please enter the depth of the family tree:" << endl;
			cin >> depth;
			if (depth == 0) {
				break;
			}
			for (int i = 1; i < depth; i++) {
				pid_t proc = fork();
				if (proc > 0) {
					break;
				}
				deep++;
			}
			string ret = "I am the ";
			if (deep == 0) {
				ret = ret + "parent. ";
			}
			else if (deep == 1) {
				ret = ret + "child. ";
			}
			else if (deep == 2) {
				ret = ret + "grandchild. ";
			}
			else {
				for (int k = 2; k < deep; k++) {
					ret = ret + "great ";
				}
				ret = ret + "grandchild. ";
			}
			ret = ret + "My process ID is " + to_string(getpid());
			ret = ret + " and my parent’s process ID is " + to_string(getppid()) + "\n";
			cout << ret;
			sleep(1);
	}
	return 0;
}
