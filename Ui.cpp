#include "pch.h"
#include "Ui.h"
#include<iostream>
#include<vector>
using namespace std;

Ui::Ui() {
	Controller cnt;
	this->cnt = cnt;
}

Ui::Ui(Controller cnt) {
	this->cnt = cnt;
}

Ui::Ui(const Ui &other) {
	this->cnt = other.cnt;
}

void Ui::printMenu() {
	cout << "Pt a opri aplicatia apasa 0" << '\n';
	cout << "Pentru adaugarea unui client nou apasa 1" << '\n';
	cout << "Pentru a retrage o suma de bani apasa 2" << '\n';
	cout << "Pentru a depune o suma apasa 3" << '\n';
	cout << "Pentru a vizualiza situatia curenta a bancomatului apasa 4" << '\n';

}

void Ui::addClient() {
	std::string name, CNP, PIN;
	float sum;
	cout << "Introduceti numele:" << endl; cin >> name;
	cout << "CNP:" << endl; cin >> CNP;
	cout << "PIN:" << endl; cin >> PIN;
	cout << "Suma este:";  cin >> sum;
	cout << cnt.addClient(name, CNP, PIN, sum);
}

void Ui::Start() {
	int p;
	do {
		this->printMenu();
		cin >> p;
		if (p == 1) {
			this->addClient();
		}

		if (p == 2) {
			std::string name, CNP, PIN;
			float sum;
			cout << "Introduceti numele:" << endl; cin >> name;
			cout << "CNP:" << endl; cin >> CNP;
			cout << "PIN:" << endl; cin >> PIN;
			cout << "Suma este:";  cin >> sum;
			cout << cnt.withdraw(name, CNP, PIN, sum);

		}
		if (p == 3) {
			std::string name, CNP, PIN;
			float sum;
			cout << "Introduceti numele:" << endl; cin >> name;
			cout << "CNP:" << endl; cin >> CNP;
			cout << "PIN:" << endl; cin >> PIN;
			cout << "Suma este:";  cin >> sum;
			cout << cnt.deposit(name, CNP, PIN, sum);


		}
		if (p == 4) {
			cout << "Total money in ATM: " << cnt.getMoney() << '\n';
			std::vector<Client> v = cnt.getClients();
			for (int i = 0; i < v.size(); i++)
				cout << v[i].getName() << " " << v[i].getCNP() << " " << v[i].getSum() << '\n';
		}
	} while (p != 0);
}
Ui::~Ui()
{
}
