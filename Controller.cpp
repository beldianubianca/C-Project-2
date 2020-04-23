#include "pch.h"
#include "Controller.h"

Controller::Controller()
{
	RepoFile<Client> repo;
	this->repo = repo;
}

Controller::Controller(RepoFile<Client> repo) {
	this->repo = repo;
	this->UpdateMoney();
}

Controller::Controller(RepoFile<Client> repo, float Money) {
	this->repo = repo;
	this->Money = Money;
}

std::string Controller::addClient(std::string name, std::string CNP, std::string PIN, float sum) {
	Client c(name, CNP, PIN, sum);
	std::string result = repo.add(c);
	if (result == "element added succesfully")
		Money = Money + sum;
	return result;
}

std::vector<Client> Controller::getClients() {
	return this->repo.getElems();

}

std::string Controller::withdraw(std::string name, std::string CNP, std::string PIN, float sum2) {
	Client c(name, CNP, PIN);
	int pos = repo.find(c);
	if (pos == -1)
		return "client doesn't exists";
	Client c1 = repo[pos];
	if (c1.getPIN() != c.getPIN())
		return "PIN doesn't match";
	if (c1.getSum() < sum2)
		return "too less money";
	if (Money < sum2)
		return "not enough money";
	c1.setSum(c1.getSum() - sum2);
	Money = Money - sum2;
	repo.Update(c1);
	return "sum updated succesfully";
}

std::string Controller::deposit(std::string name, std::string CNP, std::string PIN, float sum2) {
	Client c(name, CNP, PIN);
	int pos = repo.find(c);
	if (pos == -1)
		return "client doesn't exists";
	Client c1 = repo[pos];
	if (c1.getPIN() != c.getPIN())
		return "PIN doesn't match";
	c1.setSum(c1.getSum() + sum2);
	Money = Money + sum2;
	repo.Update(c1);
	return "sum updated succesfully";
}

void Controller::UpdateMoney() {
	std::vector<Client> elems = repo.getElems();
	for (int i = 0; i < elems.size(); i++)
		Money = Money + elems[i].getSum();
}
float Controller::getMoney() {
	return this->Money;
}
Controller::~Controller()
{
}
