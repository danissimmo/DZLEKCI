#include <iostream>
#include <fstream>
#include <list>
#include <bitset>
using namespace std;


class Protocol
{
public:
	virtual void send(char* buf, int len) = 0;
};

class BinaryProtocol : public Protocol
{
public:

	void send(char* buf, int len)
	{
		for (int i = 0; i < len; i++)
		{
			int l = 128;
			while (l > 0)
			{
				cout << bool(buf[i] & l);
				l = l >> 1;
			}
			cout << " ";
		}
	}
};

class HexProtocol : public Protocol
{
public:

	void send(char* buf, int len)
	{
		if (buf[0] != NULL)
		{
			for (int i = 0; i < strlen(buf); i++)
				cout << "0x" << hex << (int)(buf[i] & 0xff) << " ";
		}
	}
};

struct ConnectionList
{
	Protocol* mas[100];
	int count = 0;

};

void addProtocol(ConnectionList* p, Protocol* newProtocol)
{
	p->mas[p->count] = newProtocol;
	p->count++;
}

void sendAll(ConnectionList* p)
{
	for (int i = 0; i < p->count; i++) {
		p->mas[i]->sendName();
	}
}

void Read()
{
	string fileName, line;

	cout << "Enter the file name" << endl;

	cin >> fileName;
	fstream file;
	file.open(fileName);

	if (file.is_open() != true)
	{
		cout << "File reading error" << endl;
		return;
	}

	string _protocol = "";

	int pos = 0;

	while (file >> line)
	{
		_protocol.push_back(line[0]);
		pos++;
	}

	file.close();

	ConnectionList* p = new ConnectionList[pos];
	for (int i = 0; i < _protocol.size(); i++)
	{
		if (_protocol[i] == 'B') addProtocol(p, new BinaryProtocol);
		if (_protocol[i] == 'H') addProtocol(p, new HexProtocol);
	}

	sendAll(p);
	delete[] p;
}

int main()
{
	char word[20];
	cin >> word;

	BinaryProtocol bp;
	bp.send(word, 20);

	cout << endl;

	HexProtocol hp;
	hp.send(word, 20);

	cout << endl;

	Read();
}
