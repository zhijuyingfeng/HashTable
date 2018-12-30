#include "HashTable.h"

int HashTable::LastPrime(const int& x)
{
	bool *isPrime = new bool[x + 1];
	memset(isPrime, 0x11, sizeof(bool)*(x + 1));
	vector<int> prime;
	for (int i = 2; i <= x; i++)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
		int size = prime.size();
		for(int j=0;j<size&&prime[j]*i<=x;j++)
		{
			isPrime[i*prime[j]] = 0;
			if (i%prime[j] == 0)
				break;
		}
	}
	delete[]isPrime;
	return prime.back();
}

HashTable::HashTable(const int&M)
{
	this->m = M;
	this->p = LastPrime(this->m);
	this->RandSeq = new int[this->m];
	this->Table = new string[this->m];
	this->placed = new bool[this->m];
	memset(placed, 0, sizeof(bool)*this->m);
	for (int i = 0; i < m; i++)
	{
		this->RandSeq[i] = i+1;
	}
	int a, b;
	for (int i = 0; i < m; i++)
	{
		a = rand() % this->m;
		b = rand() % this->m;
		if(a>=m||b>=m)
		swap(this->RandSeq[a], this->RandSeq[b]);
	}
}

HashTable::~HashTable()
{
	delete[]Table;
	delete[]placed;
	delete[]RandSeq;
}

HashTable::HashTable()
{
	this->m = 30;
	this->p = LastPrime(this->m);
	this->Table = new string[this->m];
	this->RandSeq = new int[this->m];
	this->placed = new bool[this->m];
	memset(placed, 0, sizeof(bool)*this->m);
	for (int i = 0; i < m; i++)
	{
		this->RandSeq[i] = i+1;
	}
	int a, b;
	for (int i = 0; i < m; i++)
	{
		a = rand() % this->m;
		b = rand() % this->m;
		swap(this->RandSeq[a], this->RandSeq[b]);
	}
}

void HashTable::insert(const string& str)
{
	int sum = 0;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		sum += str[i];
	}
	int hash = sum % p;//除留余数法
	if (placed[hash] == 0)
	{
		Table[hash] = str;
		placed[hash] = 1;
		return;
	}
	int i = 0;
	while(placed[hash] == 1 && str.compare(Table[hash]) )
	{
		hash = (hash + this->RandSeq[i++]) % p;//伪随机再散列处理冲突
		i = i % this->m;
	}
	Table[hash] = str;
	placed[hash] = 1;
}

int HashTable::find(const string& str, int& QueryTime)const
{
	int sum = 0;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		sum += str[i];
	}
	int hash = sum % this->p;
	QueryTime = 1;
	if (placed[hash] == 0)
	{
		cout << "No such record!!!" << endl;
		return -1;
	}
	else if (placed[hash] && str.compare(Table[hash]) == 0)
	{
		return hash;
	}
	else
	{
		int i = 0;
		while (placed[hash] && str.compare(Table[hash]))
		{
			hash = (hash + this->RandSeq[i++]) % p;
			QueryTime++;
			i = i % m;
		}
		if (!placed[hash])
		{
			return -1;
		}
		else
		{
			return hash;
		}
	}
}

void HashTable::Show()const
{
	for (int i = 0; i < this->m; i++)
	{
		cout<<i<<"\t"<<Table[i] << endl;
	}
}