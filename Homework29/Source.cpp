#include <iostream>
#include <string>
#include <fstream>

//Задача 2.
bool overwrite(std::string &path, std::string &str) {
	std::ofstream out2;
	out2.open(path, std::ios::in || std::ios::out);
	if (out2.is_open()) {
		out2 << str << "\n";
		out2.close();
		return true;
	}

	out2.close();
	return false;
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::string path = "file.txt";
	
	//Задача 1.
	std::ofstream out;
	out.open(path, std::ios::app);
	if (out.is_open()) {
		std::cout << "Файл открыт для записи.\n";
		std::string tmp;
		do {
			std::cout << "Введите строку: ";
			getline(std::cin, tmp);
			out << tmp + '\n';
		} while (tmp != "end");
	}
	else
		std::cout << "Ошибка открытия файла.\n";
	
	out.close();

	std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		while (!in.eof()) {
			std::cout << "Файл открыт для чтения.\nСодержимое файла:\n";
			std::string str;
			while (getline(in, str))
				std::cout << str << '\n';
		}
	}
	else
		std::cout << "Ошибка открытия файла!\n";
		
		in.close();

		if (!remove(path.c_str()))
			std::cout << "Файл удалён.\n";
		else
			std::cout << "Ошибка удаления файла.\n\n";
		std::cout << "\n";


	//Задача 2.
	std::string path2 = "file2.txt";
	std::cout << "Задача 2. \nПуть к файлу: " << path2;
	std::cout << "\n";
	std::string str2 = "If you never try you will never know.";
	std::cout << "Cтрока: " << str2 ;
	std::cout << "\n";

		if (overwrite(path2, str2))
			std::cout << "Замена прошла успешно.\n";
		else
			std::cout << "Ошибка записи. Файла не существует.";

		remove("file2.txt");

	return 0;
}