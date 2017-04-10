#pragma once
#include <iostream>
#include <fstream>
#include <string> 
#include <thread>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctype.h>
#include <sstream>
using namespace std;
class FileHandle
{
	/*friend ofstream &operator<<(ofstream &out, const string &c);
	friend ofstream &operator<<(ofstream &out, const float & c);
	friend ifstream &operator >> (ifstream &in, const  float &c);
	friend ifstream &operator>>(ifstream &in, const string &c);*/
public:
	
	FileHandle();
	~FileHandle();
	void Initialize();
	void read();
	void Incomes();
	void Expenses();
	void save();
	float balance();
	//string getLastLine(ifstream & in);
	bool has_digits_dots_only(const string s);
	bool has_only_digits(const string s);
	string round(float s);

	void remove_last_inc();

	void remove_last_exp();

	
	
private:
	int inc, exp;
	string Desc;
	string Sum, dayt;
	string Date;
	string days, months, years, input;
	string month;
	string day;
	string year;
	string line;
	string appsuminc, appsumex;
	float inctemp, exptemp;
	float  totalsum, incsum, expsum, all;
	bool iskeydown = false;
	bool nada = false;
	vector<string>incDesc, expDesc, incDate, expDate;
	vector<string>incSum, expSum;
};

