
#include "pch.h"
#include <iostream>
#include"Controller.h"
#include"Client.h"
#include"Ui.h"
#include<vector>
using namespace std;

int main() {
	Client c1("Ana", "2991113089924", "1234", 200);
	Client c2("Maria", "2991017123456", "02020", 12);
	Client c3("Ion", "1", "2", 800);
	RepoFile<Client> repo("Clients.in.txt");
	Controller cnt(repo);
	Ui u(cnt);
	u.Start();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
