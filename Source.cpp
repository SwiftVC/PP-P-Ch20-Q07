/*
*	Author: CS
*	2022/03/08
* 
*	Define a function that return the lexicographically last string of std::vector<std::string>
*/

#include <iostream>
#include <vector>
#include <string>
#include <exception>

std::vector<std::string>::iterator
lexicographical_last_str(std::vector<std::string>& vect) {
	if (vect.size() == 0)
		throw std::invalid_argument("empty std::vector<std::string> arg for lexicographical_last_str(..)");
	
	int index{ 0 };
	std::string best = vect[0];
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i] > best) {
			index = i;
			best = vect[i];
		}
	}

	return vect.begin() + index;
}

int main() {
	std::vector<std::string> vect{ "bravo","zulu", "alpha", "delta", "foxtrot" };
	for (std::string i : vect)
		std::cout << i << " ";

	std::cout << std::endl;

	std::cout << "lexicographical_last_str(..) : " << *lexicographical_last_str(vect) << std::endl;

	return 0;
}