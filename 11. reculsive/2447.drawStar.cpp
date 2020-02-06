#include <iostream>
using namespace std;

class Table {
private:
	int n;
	char** tables;
public:
	Table(int n);
	int markingStar();
	void printTable();
};
Table::Table(int n)	
{
	this->n = n;
	tables = new char*[n];
	for (int i = 0; i < n; ++i) {
		tables[i] = new char[n];
		for (int j = 0; j < n; ++j) {
			tables[i][j] = ' ';
		}
	}	// declare && initialize table

}
int Table::markingStar()
{
	return 0;
}

void Table::printTable()
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << tables[i][j];
		}
		cout << "\n";
	}
}

int main() {
	int n;
	cin >> n;
	Table t(n); 
	t.printTable();
	return 0;
}
