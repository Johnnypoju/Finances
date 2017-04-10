#include "stdafx.h"
#include "FileHandle.h"
#undef max;


FileHandle::FileHandle()
{
	if (!ifstream("Expenses.txt")) {
		ofstream myExpenses("Expenses.txt");
		ofstream Expsum("expsum.txt");
		myExpenses << "Expenses\nDescription           Sum                Date\n";
		Expsum << "0";
		myExpenses.close();
		Expsum.close();
	}

	if (!ifstream("Incomes.txt")) {
		ofstream myIncomes("Incomes.txt");
		ofstream Incsum("incsum.txt");
		Incsum << "0";
		myIncomes << "Incomes\nDescription           Sum                Date\n";
		myIncomes.close();
		Incsum.close();
	}
	if (!ifstream("balance.txt")) {
		ofstream Balance("balance.txt");
		Balance << "0";
		Balance.close();
	}
	if (!ifstream("incsum.txt")) {
		ofstream incsum("incsum.txt");
		incsum.trunc;
		incsum << "0";
		incsum.close();
	}
	if (!ifstream("expsum.txt")) {
		ofstream expsum("expsum.txt");
		expsum << "0";
		expsum.close();
	}
}


FileHandle::~FileHandle()
{
}

void FileHandle::Initialize() //Removing all previous data
{
	if (ifstream("Expenses.txt")) {
		ofstream myExpenses("Expenses.txt");
		ofstream Expsum("expsum.txt");
		Expsum.trunc;
		myExpenses.trunc;
		myExpenses << "Expenses\nDescription           Sum                Date\n";
		myExpenses.close();
		Expsum.close();
	}
	else {
		ofstream myExpenses("Expenses.txt");
		ofstream Expsum("expsum.txt");
		myExpenses << "Expenses\nDescription           Sum                Date\n";
		Expsum << "0";
		myExpenses.close();
		Expsum.close();
	}
	
	if (ifstream("Incomes.txt")) {
		ofstream myIncomes("Incomes.txt");
		ofstream Incsum("incsum.txt");
		Incsum << "0";
		myIncomes.trunc;
		myIncomes << "Incomes\nDescription           Sum                Date\n";
		myIncomes.close();
		Incsum.close();
	}
	else {
		ofstream myIncomes("Incomes.txt");
		ofstream Incsum("incsum.txt");
		Incsum << "0";
		myIncomes << "Incomes\nDescription           Sum                Date\n";
		myIncomes.close();
		Incsum.close();
	}
	if (ifstream("balance.txt")) {
		ofstream Balance("balance.txt");
		Balance.trunc;
		Balance << "0";
		Balance.close();
	}
	else {
		ofstream Balance("balance.txt");
		Balance << "0";
		Balance.close();
	}
	if (ifstream("incsum.txt")) {
		ofstream incsum("incsum.txt");
		incsum.trunc;
		incsum << "0";
		incsum.close();
	}
	else {
		ofstream incsum("incsum.txt");
		incsum << "0";
		incsum.close();
	}
	if (ifstream("expsum.txt")) {
		ofstream expsum("expsum.txt");
		expsum.trunc;
		expsum << "0";
		expsum.close();
	}
	else {
		ofstream expsum("expsum.txt");
		expsum << "0";
		expsum.close();
	}

}

void FileHandle::read() //printing the account data
{
	ifstream myIncomes("Incomes.txt");
	if (myIncomes.is_open()) {
		cout << myIncomes.rdbuf() << endl;
		ifstream incsum("incsum.txt");
		incsum >> line;
		cout << "Amount: " << line << endl << endl;
		incsum.close();
	}
	else
		cout << "Error! Incomes not found!" << endl;
	myIncomes.close();
	ifstream myExpenses("Expenses.txt");
	if (myExpenses.is_open()) {
		cout << myExpenses.rdbuf() << endl;
		ifstream expsum("expsum.txt");
		expsum >> line;
		cout << "Amount: " << "-" << line << endl;
		
	}
	else {
		cout << "Error! Expenses not found!" << endl;
	}
	myExpenses.close();
	ifstream totalBalance("balance.txt");
	totalBalance >> line;
	cout << endl << "Total balance: " << line << endl;
}

void FileHandle::Incomes() //inputting incomes
{
	
	cout << "Description of transaction (max 21 letters): ";
	getline(cin, Desc);
	while (Desc.size() > 21) {
		cout << "Word too long." << endl;
		cout << "Description of transaction (max 21 letters): ";
		getline(cin, Desc);
	}
	while (GetAsyncKeyState('\r') & 0x8000 );

	cout << endl << "Sum of transaction (max 9 999 999 €): ";
	getline(cin, Sum);
	while (!has_digits_dots_only(Sum) || Sum.empty() ||stof(Sum) <= 0 || stof(Sum) > 9999999 || Sum.size() > 8) {
		//cin.ignore();
		cout << "Nothing or a letter entered or the number below zero or above 9 999 999." << endl;
		cout << endl << "Sum of transaction (max 9 999 999 €): ";
		getline(cin, Sum);
	}
	while (GetAsyncKeyState('\r') & 0x8000);
	cout << endl << "Day of transaction (use a whole number): ";
	getline(cin, day);
	while (!has_only_digits(day) || day.empty() || 0 >= stoi(day) ||stoi(day)>31) {
		//cin.ignore();
		cout << "Wrong date" << endl;
		cout << endl << "Day of transaction (use a whole number): ";
		getline(cin, day);
	}
	
	while (GetAsyncKeyState('\r') & 0x8000);
	cout << endl << "Month of transaction (use a whole number): ";
	getline(cin, month);
	while (!has_only_digits(month) || month.empty() || 0 >= stoi(month) || stoi(month) > 12)   {
		//cin.clear();
		//cin.ignore();
				cout << "Wrong month" << endl;
				cout << endl << "Month of transaction (use a whole number): ";
				getline(cin, month);
	}
	while (stoi(month) == 2 && stoi(day) > 28) {
		if (stoi(month) == 2) {
			cout << "February has only 28 days." << endl;
			cout << endl << "Month of transaction (use a whole number): ";
			getline(cin, month);
		}
		else {
			break;
		}
	}
	while (GetAsyncKeyState('\r') & 0x8000);
	cout << endl << "Year of transaction (use a whole number): ";
	getline(cin, year);
	while (!has_only_digits(year) || stoi(year) < 0) {
		//cin.clear();
		//cin.ignore();
		cout << "year not in Gregorian calendar" << endl;
		cout << "Year of transaction (use a whole number): ";
		getline(cin, year);
	}
	
	ostringstream convert;
	convert << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/"<< year;
	days = convert.str();

	/*cout << endl << "Date of transaction (dd/mm/yyyy): ";
	cout << Date;*/
	
	
	incDesc.push_back(Desc);
	incSum.push_back(Sum);
	incDate.push_back(days);
	inc++;
	
}

void FileHandle::Expenses() //inputting expenses
{
	cout << "Description of transaction (max 21 letters): ";
	getline(cin, Desc);
	while (Desc.size() > 21) {
		cout << "Word too long." << endl;
		cout << "Description of transaction (max 21 letters): ";
		getline(cin, Desc);
	}
	cout << endl << "Sum of transaction (max 9 999 999): ";
	getline(cin, Sum);
	while (!has_digits_dots_only(Sum) || Sum.empty() || stof(Sum) <= 0 || stof(Sum) > 9999999 || Sum.size() > 8) {
		//cin.ignore();
		cout << "Nothing or a letter entered or the number below zero or above 9 999 999" << endl;
		cout << endl << "Sum of transaction (max 9 999 999): ";
		getline(cin, Sum);
	}
	while (GetAsyncKeyState('\r') & 0x8000);
	cout << endl << "Day of transaction (use a whole number): ";
	getline(cin, day);
	while (!has_only_digits(day) || day.empty() || 0 >= stoi(day) || stoi(day)>31) {
		//cin.ignore();
		cout << "Wrong date" << endl;
		cout << endl << "Day of transaction (use a whole number): ";
		getline(cin, day);
	}

	while (GetAsyncKeyState('\r') & 0x8000);
	cout << endl << "Month of transaction (use a whole number): ";
	getline(cin, month);
	while (!has_only_digits(month) || month.empty() || 0 >= stoi(month) || stoi(month) > 12) {
		//cin.clear();
		//cin.ignore();
			cout << "Wrong month" << endl;
			cout << endl << "Month of transaction (use a whole number): ";
			getline(cin, month);
	}
	while (stoi(month) == 2 && stoi(day) > 28) {
		if (stoi(month) == 2) {
			cout << "February has only 28 days." << endl;
			cout << endl << "Month of transaction (use a whole number): ";
			getline(cin, month);
		}
		else {
			break;
		}
	}
	while (GetAsyncKeyState('\r') & 0x8000);
	cout << endl << "Year of transaction (use a whole number): ";
	getline(cin, year);
	while (!has_only_digits(year) || stoi(year) < 0) {
		//cin.clear();
		//cin.ignore();
		cout << "year not in Gregorian calendar" << endl;
		cout << "Year of transaction (use a whole number): " << endl;
		getline(cin, year);
	}
	ostringstream convert;
	convert << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << year;
	days = convert.str();
	/*cout << endl << "Date of expense (dd/mm/yyyy): ";
	cout << Date;*/

	expDesc.push_back(Desc);
	expSum.push_back(Sum);
	expDate.push_back(days);
	exp++;
}

void FileHandle::save() //saving temp data
{
	
	ofstream Incomes("Incomes.txt", ios_base::app);
	if (!incDesc.empty() || !incSum.empty() || !incDate.empty()) {
		for (int i = 0; i < inc; i++) {
			if (incDesc[i].size() < 21) {
				int fill = 21 - incDesc[i].size();
				incDesc[i].append(fill, ' ');
			}
			if (incSum[i].size() < 14) {
				int fill = 14 - incSum[i].size();
				appsuminc = " Euro";
				appsuminc.append(fill, ' ');
			}
			Incomes << incDesc[i] << " " << round(stof(incSum[i])) << appsuminc << incDate[i] << endl;
			
		}
		incDesc.clear();
		//incSum.clear();
		incDate.clear();
		cout << "Incomes saved." << endl << endl;
	}
	else {
		cout << "Error saving incomes!! No data." << endl << endl;
	}
	Incomes.close();
	ofstream Expenses("Expenses.txt", ios_base::app);
	if (!expDesc.empty() || !expSum.empty() || !expDate.empty()) {

		for (int i = 0; i < exp; i++) {
			if (expDesc[i].size() < 21) {
				int fill = 21 - expDesc[i].size();
				expDesc[i].append(fill, ' ');
			}
			if (expSum[i].size() < 14) {
				int fill = 14 - expSum[i].size();
				appsumex = " Euro";
				appsumex.append(fill, ' ');
			}
			Expenses << expDesc[i] << " " << round(stof(expSum[i])) << appsumex << expDate[i] << endl;
		}
			expDesc.clear();
			//expSum.clear();
			expDate.clear();
			cout << "Expenses saved." << endl << endl;
	}
	else {
		cout << "Error saving expenses!! No data." << endl << endl;
	}
	Expenses.close();


	Expenses.close();
	ofstream newBalance("balance.txt");
	newBalance << round(balance()) << " Euro";
	inc = 0;
	exp = 0;
	incSum.clear();
	expSum.clear();
	newBalance.close();
}

float FileHandle::balance() //counting account balance
{
	incsum = 0;
	expsum = 0;
	totalsum = 0;
	for (int i = 0; i < incSum.size(); i++) {
		incsum = incsum + stof(incSum[i]);
	}
	ifstream IncSum("incsum.txt");
	IncSum >> inctemp;
	incsum = inctemp + incsum;
	IncSum.close();
	ofstream IncSumnew("incsum.txt");
	IncSumnew << round(incsum);
	for (int i = 0; i < expSum.size(); i++) {
		expsum = expsum + stof(expSum[i]);
	}
	ifstream ExpSum("expsum.txt");
	ExpSum >> exptemp;
	expsum = exptemp + expsum;
	ExpSum.close();
	ofstream ExpSumnew("expsum.txt");
	ExpSumnew << round(expsum);

	totalsum = incsum - expsum;
	return totalsum;
}


bool FileHandle::has_digits_dots_only(const string s) { //checking for decimal number
	return (s.find_first_not_of("0123456789.") == string::npos);
}
bool FileHandle::has_only_digits(const string s) { //checking for whole number
	return (s.find_first_not_of("0123456789") == string::npos);
}
string FileHandle::round(float s) { //rounding numbers to two decimals
	stringstream stream;
	stream << fixed << setprecision(2) << s;
	string c = stream.str();
	return c;
}
void FileHandle::remove_last_inc() {
	if (incDesc.size() == 0) {
		cout << endl << "!!Error! Nothing to remove!!" << endl << endl;
	}
	else {
		incDesc.pop_back();
		incDate.pop_back();
		incSum.pop_back();
	}
}
void FileHandle::remove_last_exp() {
	if (incDesc.size() == 0) {
		cout << endl << "!!Error! Nothing to remove!!" << endl << endl;
	}
	else {
		expDate.pop_back();
		expDesc.pop_back();
		expSum.pop_back();
	}
}

/*string FileHandle::getLastLine(ifstream & in)
{
string line;
while (in >> ws && getline(in, line));
return line;
}*/

/*ofstream &operator<<(ofstream & out, const string & c)
{
	out << c << endl;
	return out;
}
ofstream &operator<<(ofstream & out, const float & c)
{
	out << c << endl;
	return out;
}

ifstream &operator >>(ifstream & in, const string & c)
{
	in >> c;
	return in;
}
ifstream &operator >> (ifstream & in, const float & c)
{
	in >> c;
	return in;
}*/
