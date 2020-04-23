#pragma once
#include<string>
#include<fstream>
class Client {
private:
	std::string name;
	std::string CNP;
	std::string PIN;
	float sum;

public:
	Client();

	Client(std::string name, std::string CNP, std::string PIN, float suma);
	Client(std::string name, std::string CNP, std::string PIN);
	bool operator==(const Client & other);
	std::string getName();
	std::string getCNP();
	std::string getPIN();
	float getSum();
	void setSum(float sum);
	void setCNP(std::string CNP);
	void setName(std::string name2);
	friend std::istream &operator>>(std::istream &input, Client &C) {
		input >> C.name >> C.CNP >> C.PIN >> C.sum;
		return input;
	}

	friend std::ostream &operator<<(std::ostream &output, const Client &C) {
		output << C.name << " " << C.CNP << " " << C.PIN << " " << C.sum << '\n';
		return output;
	}

	~Client();
};


