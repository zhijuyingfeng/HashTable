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
	int m;//表的大小
	int p;//小于m的最大素数
	string* Table;//存储字符串
	bool *placed;//标志是否有记录
	int* RandSeq;//伪随机序列
public:
	void insert(const string& str);//向哈希表中插入元素
	int find(const string &str, int& QueryTime)const;//在哈希表中查找
	void Show()const;
	static int LastPrime(const int& x);//找到小于等于x的最大素数
	HashTable(const int &M);
	HashTable();//默认构造函数
	~HashTable();//析构函数
};

#endif // !HASH_TABLE
