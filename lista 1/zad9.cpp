#include <iostream>
#include <fstream>

void ascii_counter(const char* fname)
{
	int ascii[128 - 32] = { ' ' };
	std::ifstream file(fname);

		char singleChar;
		do
		{
			singleChar = file.get();
			int numeric = singleChar - ' ';

			++ascii[numeric];

		} while (singleChar != EOF);

		int i;
		for (i = 0; i < (128 - 32); ++i)
			std::cout << "Znak " << (char)(i + 32) << " wystapil " << ascii[i] << std::endl;


	file.close();
	getchar();
}

//int main()
//{
//	ascii_counter("/Users/Viodine/Desktop/ascii.txt");
//}