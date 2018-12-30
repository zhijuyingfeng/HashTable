#pragma once
#ifndef HASH_TABLE
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class HashTable
{
private:
	int m;//��Ĵ�С
	int p;//С��m���������
	string* Table;//�洢�ַ���
	bool *placed;//��־�Ƿ��м�¼
	int* RandSeq;//α�������
public:
	void insert(const string& str);//���ϣ���в���Ԫ��
	int find(const string &str, int& QueryTime)const;//�ڹ�ϣ���в���
	void Show()const;
	static int LastPrime(const int& x);//�ҵ�С�ڵ���x���������
	HashTable(const int &M);
	HashTable();//Ĭ�Ϲ��캯��
	~HashTable();//��������
};

#endif // !HASH_TABLE
