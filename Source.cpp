#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm> 
#include <ostream>
#include <chrono> 



void Clean_simbol(std::string& word) { // Функция для очистки переданного слова от знаков препинания и др.
	
	for (int i = 0; i < word.length(); ++i) {
		if ((word.at(i) == '\'' && i == 0) || (word.at(i) == '\'' && i == word.length() - 1) || word.at(i) == '(' || word.at(i) == ')' \
			|| word.at(i) == '.' || word.at(i) == ',' || word.at(i) == '!' || word.at(i) == '?' || word.at(i) == '"' || word.at(i) == '-' \
			|| word.at(i) == '\\' || word.at(i) == ';' || word.at(i) == ':' || std::isdigit(word. at (i))) {
			word.erase(i, 1);
			--i; 
		}
		std::transform(word.begin(), word.end(), word.begin(), tolower);
	}
}
 

int main()
{
	setlocale(0, "");
	int n;
	std::string path = "1.txt";
	std::string path_v = "2.txt"; 
	std::string path_s = "3.txt";
	std::ifstream in;	
	std::ofstream out;
	std::string word;
	std::vector < std::string> f;
	std::set < std::string> l;
	// Запись в вектор
	auto start = std:: chrono::steady_clock::now();
	in.open(path);
	if (in.is_open()) {
		std::cout << "Файл открыт. \n";
		while (!in.eof()) { // Пословное считывание
		in >> word;
		Clean_simbol (word); 
		
		if (word == "i'm") {
			f.push_back("i");
			f.push_back("am");
		}
		else
			if (word.find("'d") != std::string::npos) {
				f.push_back("would");
				f.push_back(word.substr(0, word.find("'d")));
			}
			else
				if (word.find("'ll") != std::string::npos) {
					f.push_back("will");
					f.push_back(word.substr(0, word.find("'ll")));
				}
				else
					if (word.find("'ve") != std::string::npos) {
						f.push_back("have");
						f.push_back(word.substr(0, word.find("'ve")));
					}
					else
						if (word.find("'re") != std::string::npos) {
							f.push_back("are");
							f.push_back(word.substr(0, word.find("'re")));
						}
						else
							if (word.find("'s") != std::string::npos) {
								f.push_back("is");
								f.push_back(word.substr(0, word.find("'s")));
							}
							else
								if (word == "isn't") {
									f.push_back("is");
									f.push_back("not");
								}
								else
									if (word == "aren't") {
										f.push_back("are");
										f.push_back("not");
									}
									else
											f.push_back(word);
		}
	}
	else {
		std::cout << "Ошибка открытия файла \n";
	}
	in.close();
	std::sort(f.begin(), f.end());
	auto resalt = std::unique(f.begin(), f.end());
	f.erase(resalt, f.end());
	out.open(path_v, std::ios::out); //  Файл для записи
	if (out.is_open()) {
		std::cout << "Файл открыт. \n";
		for (std::string st : f) { //  Запись в файл
			out << st << std::endl;
		}
	}
	else {
		std::cout << "Ошибка открытия файла \n";
	}
	out.close();
	auto end = std::chrono::steady_clock::now();
	std:: cout << "Время работы записи в vector: "
		<< std:: chrono::duration_cast<std:: chrono::milliseconds>(end - start).count()
		<< " ms" << std::endl;

	// Запись в set
	auto start_s = std::chrono::steady_clock::now();
	in.open(path);
	if (in.is_open()) {
		std::cout << "Файл открыт. \n";
		while (!in.eof()) { // Пословное считывание
			in >> word;
			Clean_simbol(word);

			if (word == "i'm") {
				l.insert ("i");
				l.insert("am");
			}
			else
				if (word.find("'d") != std::string::npos) {
					l.insert ("would");
					l.insert (word.substr(0, word.find("'d")));
				}
				else
					if (word.find("'ll") != std::string::npos) {
						l.insert ("will");
						l.insert (word.substr(0, word.find("'ll")));
					}
					else
						if (word.find("'ve") != std::string::npos) {
							l.insert ("have");
							l.insert (word.substr(0, word.find("'ve")));
						}
						else
							if (word.find("'re") != std::string::npos) {
								l.insert ("are");
								l.insert (word.substr(0, word.find("'re")));
							}
							else
								if (word.find("'s") != std::string::npos) {
									l.insert ("is");
									l.insert (word.substr(0, word.find("'s")));
								}
								else
									if (word == "isn't") {
										l.insert ("is");
										l.insert ("not");
									}
									else
										if (word == "aren't") {
											l.insert ("are");
											l.insert ("not");
										}
										else
												l.insert (word);
		}
	}
	else {
		std::cout << "Ошибка открытия файла \n";
	}
	in.close();
	out.open(path_s, std::ios::out); //  Файл для записи
	if (out.is_open()) {
		std::cout << "Файл открыт. \n";
		for (std::string st : l) { //  Запись в файл
			out << st << std::endl;
		}
	}
	else {
		std::cout << "Ошибка открытия файла \n";
	}
	out.close();
	auto end_s = std::chrono::steady_clock::now();
	std::cout << "Время работы записи в set: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(end_s - start_s).count()
		<< " ms" << std::endl;

	return 0;
};