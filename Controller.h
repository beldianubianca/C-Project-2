#pragma once
#pragma once
#include"Repo.h"
#include"Client.h"
#include<vector>
#include"RepoFile.h"
class Controller
{
private:
	RepoFile<Client> repo;
	float Money;
public:

	Controller();

	Controller(RepoFile<Client> repo);

	Controller(RepoFile<Client> repo, float Money);

	std::string addClient(std::string name, std::string CNP, std::string PIN, float sum);

	std::vector<Client> getClients();

	std::string withdraw(std::string name, std::string CNP, std::string PIN, float sum2);

	std::string deposit(std::string name, std::string CNP, std::string PIN, float sum2);

	float getMoney();

	void UpdateMoney();

	~Controller();
};

