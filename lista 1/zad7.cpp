#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

std::vector<int> getFromFile(const char* fname)
{
	std::vector<int> factors;
	std::ifstream file(fname);
	file.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		std::string buffer;
		while (std::getline(file, buffer))
		{
			factors.push_back(std::atoi(buffer.c_str()));
		}
		file.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return factors;
}

void saveToFile(const char* fname, std::vector<int> result)
{
	std::ofstream file(fname);

	for (int i = 0; i < result.size(); i++)
	{
		file << std::to_string(result[i]) << std::endl;
	}

	file.close();
}

void wielomian(std::vector<int>(*getFromFile) (const char* fname), void(*saveValues)(const char* fname, std::vector<int> result))
{
	std::vector<int> a = getFromFile("/Users/Viodine/Desktop/a.txt");
	std::vector<int> b = getFromFile("/Users/Viodine/Desktop/b.txt");
	std::vector<int> c;

	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			int tempResult = 0;
			for (int j = 0; j < b.size(); j++)
				tempResult += a[i] * b[j];
			c.push_back(tempResult);
		}
	}
	else
	{
		std::cout << "Error at writing!" << std::endl;
	}

	saveValues("/Users/Viodine/Desktop/c.txt", c);
}

//int main()
//{
//	wielomian(getFromFile, saveToFile);
//	getchar();
//}