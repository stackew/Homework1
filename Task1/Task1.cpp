#include <iostream>

int mystrcmp(const char* str1, const char* str2)
{
	size_t str1_size = 0, str2_size = 0;
	for (size_t i = 0; str1[i] != '\0'; i++)
	{
		str1_size++;
	}
	for (size_t i = 0; str2[i] != '\0'; i++)
	{
		str2_size++;
	}

	if (str1_size == str2_size)
	{
		return 0;
	}
	else if (str1_size > str2_size)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int StringToNumber(char* str)
{
	int num = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
		}
		else
		{
			return -1;
		}
	}
	return num;
}

char* NumberToString(int number)
{
	int string_size = 0;
	int temp_num = number;
	while (temp_num != 0)
	{
		temp_num /= 10;
		string_size++;
	}
	char* string_num = new char[string_size + 1];
	for (int i = string_size - 1; i != -1; i--)
	{
		string_num[i] = number % 10 + '0'; //123
		number /= 10;
	}
	string_num[string_size] = '\0';
	return string_num;
	delete[] string_num;
}

char* Uppercase(char* str1)
{
	for (size_t i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] - 32 >= 65 && str1[i] - 32 <= 90)
		{
			str1[i] = str1[i] - 32;
		}
	}
	return str1;
}

char* Lowercase(char* str1)
{
	for (size_t i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] + 32 >= 97 && str1[i] + 32 <= 122)
		{
			str1[i] = str1[i] + 32;
		}
	}
	return str1;
}

char* mystrrev(char* str)
{
	int reverse_size = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		reverse_size++;
	}
	char* reverse_str = new char[reverse_size + 1]; //123
	reverse_str[reverse_size] = '\0';

	size_t j = 0;
	for (int i = reverse_size - 1; i != -1; i--)
	{
		reverse_str[j++] = str[i];
	}

	return reverse_str;
	delete[] reverse_str;
}
int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Func 1" << std::endl;
	std::cout << mystrcmp("first string", "second string") << std::endl;

	std::cout << "Func 2" << std::endl;
	char str[4] = "123";
	if (StringToNumber(str) == -1)
	{
		std::cout << "Вы ввели что то неправильно!" << std::endl;
	}
	else
	{
		std::cout << StringToNumber(str) << std::endl;
	}

	std::cout << "Func 3" << std::endl;
	std::cout << NumberToString(123) << std::endl;

	std::cout << "Func 4" << std::endl;
	char str1[10] = "Abcdef23!";
	std::cout << Uppercase(str1) << std::endl;

	std::cout << "Func 5" << std::endl;
	std::cout << Lowercase(str1) << std::endl;

	std::cout << "Func 6" << std::endl;
	std::cout << mystrrev(str1) << std::endl;
	return 0;
}
