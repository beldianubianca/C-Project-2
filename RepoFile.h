#pragma once
#pragma once
#include"Repo.h"
#include<iostream>
#include<fstream>
template<class T>
class RepoFile :public Repo<T>
{
private:
	std::string filename;
public:
	RepoFile() {

	}
	RepoFile(std::string filename) {
		std::vector<T> v;
		this->elems = v;
		this->filename = filename;
		this->readElements();

	}

	void readElements() {
		std::ifstream fin(filename);
		T elem;
		while (fin >> elem) {
			std::cout << elem;
			Repo<T>::add(elem);
		}

		fin.close();
	}

	void printToFile() {
		std::ofstream fout(filename);
		for (int i = 0; i < this->elems.size(); i++)
			fout << this->elems[i];
		fout.close();

	}


	std::string add(T elem) {
		std::string result = Repo<T>::add(elem);
		printToFile();
		return result;

	}


	void Update(T elem) {
		Repo<T>::Update(elem);
		printToFile();

	}


	~RepoFile() {

	}
};

