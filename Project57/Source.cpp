#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void process(const char* file, const char* file1, const char* file2, const char* file3);
void diy(const char* strin, char* strout, char* strout1, char* strout2);

int main()
{
	setlocale(LC_ALL, "RUS");
	process("file.txt", "simbols.txt", "numbers.txt", "other.txt");
}

void process(const char* file, const char* file1, const char* file2, const char* file3)
{
	FILE* f = fopen(file, "rt");
	if (f == NULL)
	{
		cout << "Не удалось открыть файл " << endl;
		return;
	}
	ofstream fo;
	ofstream fo1;
	ofstream fo2;
	fo.open(file1);
	fo1.open(file2);
	fo2.open(file3);
	if (!fo.is_open()|| !fo1.is_open()|| !fo2.is_open())
	{
		cout << "Не удалось открыть файл " << endl;
		fclose(f);
		return;
	}
	while (!feof(f))
	{
		char buff[250];
		buff[0] = 0;
		fgets(buff, 250, f);
		if (strlen(buff) > 0)
		{
			char buff2[250];
			char buff3[250];
			char buff4[250];
			diy(buff, buff2, buff3, buff4);
			cout << buff2;
			fo << buff2;
			fo1 << buff3;
			fo2 << buff4;
		}
	}
	fclose(f);
	fo.close();
	fo1.close();
	fo2.close();
}

void diy(const char* strin, char* strout, char* strout1, char* strout2) {
	memset(strout, 0, sizeof(char) * 250);
	memset(strout1, 0, sizeof(char) * 250);
	memset(strout2, 0, sizeof(char) * 250);
	char simbols[10] = {};
	char numbers[10] = {};
	char other[10] = {};
	for (int i = 0; i < strlen(strin); i++) {
		memset(numbers, 0, sizeof(char) * 10);
		memset(simbols, 0, sizeof(char) * 10);
		memset(other, 0, sizeof(char) * 10);
		if (strin[i] >= 'A' && strin[i] <= 'Z' || strin[i] >= 'a' && strin[i] <= 'z') {
			strncpy(&simbols[0], &strin[i], 1);
		}
		else if (strin[i] >= '0' && strin[i] <= '9') {
			strncpy(&numbers[0], &strin[i], 1);
		}
		else 
		{
			strncpy(&other[0], &strin[i], 1);
		}
		strcat(strout, &simbols[0]);
		strcat(strout1, &numbers[0]);
		strcat(strout2, &other[0]);
	}
	
}
