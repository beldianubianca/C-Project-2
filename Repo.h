#pragma once
#include<vector>

template <class T>
class Repo
{
protected:
	std::vector<T> elems;

public:

	Repo() {
		std::vector<T> elems;
		this->elems = elems;
	}

	Repo(std::vector<T> elems) {
		this->elems = elems;
	}

	T operator[](int pos) {
		return elems[pos];
	}

	int find(T elem) {
		for (int i = 0; i < elems.size(); i++)
			if (elems[i] == elem)
				return i;

		return -1;

	}
	std::string add(T elem) {
		if (find(elem) != -1)
			return "element already exists\n";
		this->elems.push_back(elem);
		return "element added succesfully\n";
	}

	std::vector<T> getElems() {
		return this->elems;
	}

	void Update(T elem) {
		int pos = find(elem);
		if (pos == -1)
			return;
		elems[pos] = elem;

	}

	~Repo() {

	}
};

