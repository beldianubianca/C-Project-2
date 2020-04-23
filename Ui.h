#pragma once
#pragma once
#include"Controller.h"
#include<string>
class Ui
{
private:
	Controller cnt;

public:
	Ui();

	Ui(Controller cnt);

	Ui(const Ui & other);

	Ui& operator=(const Ui & other) {
		this->cnt = other.cnt;
		return *this;
	}

	void Start();

	void printMenu();

	void addClient();

	~Ui();
};

