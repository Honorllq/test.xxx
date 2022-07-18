#include<iostream>
#include<string>
#define max 1000
using namespace std;
//��ϵ�˵Ľṹ��
struct person
{
	string name;//����
	int sex;//�Ա� 1.�� 2.Ů
	int age;//����
	string phonenumber;//��ϵ�绰
	string add;//��ַ
};
// ͨѶ¼�Ľṹ��
struct addressbooks
{
	struct person personnumber[max];//ͨѶ¼�б������ϵ������

	int size;//ͨѶ¼�м�¼����ϵ�˸���
};
//�˵�����
void showmenu()
{
	cout << "****************************"<< endl;
	cout << "*******  1.�����ϵ��  *****" << endl;
	cout << "*******  2.��ʾ��ϵ��  *****" << endl;
	cout << "*******  3.ɾ����ϵ��  *****" << endl;
	cout << "*******  4.������ϵ��  *****" << endl;
	cout << "*******  5.�޸���ϵ��  *****" << endl;
	cout << "*******  6.�����ϵ��  *****" << endl;
	cout << "*******  0.�˳�ͨѶ¼  *****" << endl;
	cout << "****************************" << endl;
}
//1.�����ϵ��
void addperson(addressbooks* abs)
{
	if (abs->size == max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ������ϵ��
		string name;//����
		cout << "������������" << endl;
		cin >> name;
		abs->personnumber[abs->size].name = name;
		int sex;//�Ա�


		cout << "�������Ա�" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personnumber[abs->size].sex = sex;
				break;
			}
			else
				cout << "����������������������" << endl;
		}



		int age;//����
		cout << "����������:" << endl;
		cin >> age;
		abs->personnumber[abs->size].age = age;


		string phonenumber;//�绰
		cout << "��������ϵ�绰:" << endl;
		cin >> phonenumber;
		abs->personnumber[abs->size].phonenumber = phonenumber;



		string add;//סַ
		cout << "������סַ" << endl;
		cin >> add;
		abs->personnumber[abs->size].add = add;

		abs->size++;//����ͨѶ¼����
		cout << "����ӳɹ���" << endl;
		system("pause");//�밴���������
		system("cls");//����

	}

}
//2.��ʾ��ϵ��
void showperson(addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "��ǰ����Ϊ��" << endl;
	}
	else
	{
		int i;
		for (i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->personnumber[i].name << "\t";
			cout << "�Ա�" <<( abs->personnumber[i].sex==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personnumber[i].age << "\t";
			cout << "�绰: " << abs->personnumber[i].phonenumber << "\t";
			cout << "סַ��" << abs->personnumber[i].add << "\t\n";
		}
	}
	system("pause");//�밴���������
	system("cls");//����

}
//������ϵ��
//�ñ����ķ���������ϵ�ˣ������������������ֵΪi�����������е�λ�ã�������������ͷ���-1
//����һ��ͨѶ¼��������Ϊ����
int isexit(addressbooks *abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personnumber[i].name == name)
			return i;
	}
	return -1;
}
//3.ɾ����ϵ��
void deleteperson(addressbooks* abs)
{
	cout << "����������Ҫɾ����ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret!=0)
	{

		for (int i = ret; ret < abs->size; i++)
		{
			abs->personnumber[i] = abs->personnumber[i + 1];//����ǰ�ƣ��Դ˴ﵽɾ����ϵ�˵�Ŀ��
		}
		abs->size--;//������ϵ������
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
		
	}
	system("pause");//�밴���������
	system("cls");//����
}
//4.������ϵ��
void findperson(addressbooks* abs)
{
	cout << "������Ҫ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personnumber[ret].name << "\t";
		cout << "�Ա�" << (abs->personnumber[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personnumber[ret].age << "\t";
		cout << "�绰: " << abs->personnumber[ret].phonenumber << "\t";
		cout << "סַ��" << abs->personnumber[ret].add << "\t\n";
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�밴���������
	system("cls");//����
}
//5.�޸���ϵ��
void modifyperson(addressbooks *abs)
{	
	cout << "������Ҫ�޸���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		//�޸�����
		string name;//����
		cout << "������������" << endl;
		cin >> name;
		abs->personnumber[ret].name = name;
		int sex;//�Ա�


		cout << "�������Ա�" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personnumber[ret].sex = sex;
				break;
			}
			else
				cout << "����������������������" << endl;
		}



		int age;//����
		cout << "����������:" << endl;
		cin >> age;
		abs->personnumber[ret].age = age;


		string phonenumber;//�绰
		cout << "��������ϵ�绰:" << endl;
		cin >> phonenumber;
		abs->personnumber[ret].phonenumber = phonenumber;



		string add;//סַ
		cout << "������סַ" << endl;
		cin >> add;
		abs->personnumber[ret].add = add;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�밴���������
	system("cls");//����

}
//6.���ͨѶ¼
void cleanperson(addressbooks* abs)
{
	abs->size = 0;//����ǰ��ϵ��������Ϊ�㣬���߼����
	cout << "ͨѶ¼�����" << endl;
	system("pause");//�밴���������
	system("cls");//����

}




int main()
{
	addressbooks abs;//�����ṹ�����
	abs.size = 0;
	while (true)
	{
		showmenu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:addperson(&abs);//1.�����ϵ��
			break;
		case 2:showperson(&abs);//2.��ʾ��ϵ��
			break;
		case 3:deleteperson(&abs);//3.ɾ����ϵ��
			break;
		case 4:findperson(&abs);//4.������ϵ��
			break;
		case 5:modifyperson(&abs); //5.�޸���ϵ��
			break;
		case 6:cleanperson(&abs);//6.�����ϵ��
			break;
		case 0 :
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;


		}
	}
	system("pause");
	return 0;

}