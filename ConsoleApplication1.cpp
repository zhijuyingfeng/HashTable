#include "HashTable.h"

int main()
{
	const int n = 30;
	string name[n] = {
	"TangBingXin","RuanLisha","HanJing","XiaoHuaiYu","SiTuYuanHao","YangXin","HuangRuoTong","LinZeBang",
	"XuMinRui","GuoMingHao","ZhangYue","TangLuYao","FengYiKai","LiuLiHong","DengZiRu","LiJiaDai",
	"WangShiYou","XiongShuYang","WeiJunQuan","HuangKangRui","WangYaJun","YaoJieQian","YanJingYa",
	"MaiTianWei","HuZiRui","RenShuangYin","WangJunDa","WangLiang","Nigao","WangXinYu"
	};
	int total = 0, temp,time;
	HashTable HT(HashTable::LastPrime(n << 1));
	for (int i = 0; i < n; i++)
		HT.insert(name[i]);
	for (int i = 0; i < n; i++)
	{
		temp = HT.find(name[i], time);
		if (temp >= 0)
		{
			total += time;
			//cout << temp << endl;
		}
	}
	HT.Show();
	cout << total << endl;
	return 0;
}