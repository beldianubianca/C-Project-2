#include "pch.h"
#include "Client.h"
using namespace std;


Client::Client()
{
}
Client::Client(string name, string CNP, string PIN, float sum) {
	this->name = name;
	this->CNP = CNP;
	this->PIN = PIN;
	this->sum = sum;
}

Client::Client(string name, string CNP, string PIN) {
	this->name = name;
	this->CNP = CNP;
	this->PIN = PIN;
	this->sum = -1;
}
bool Client::operator==(const Client & other) {
	if (this->CNP == other.CNP)
		return true;
	return false;
}

std::string Client::getCNP() {
	return this->CNP;
}

void Client::setCNP(std::string CNP) {
	this->CNP = CNP;
}
std::string Client::getPIN() {
	return this->PIN;
}

float Client::getSum() {
	return this->sum;
}

void Client::setSum(float sum) {
	this->sum = sum;
}

std::string Client::getName() {
	return this->name;
}

void Client::setName(std::string name2) {
	this->name = name2;
}
Client::~Client()
{
}
