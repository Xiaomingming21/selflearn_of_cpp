//ϵͳ����
//�����ϵ�ˣ���Ϣ�����������Ա����䣬��ϵ�绰����ͥסַ������¼1000��
//��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ 
//ɾ����ϵ�ˣ���������ɾ��
//������ϵ�ˣ������������� 
//�޸���ϵ�ˣ����������޸�
//�����ϵ�ˣ����ͨѶ¼������Ϣ
//�˳�ͨѶ¼���˳�

#include<iostream>
#include<string>

using namespace std;

#define MAX 1000

struct Person//��ϵ�˽ṹ��
{
	string m_Name;//����
	int m_Sex;//�Ա�  1. ��  2. Ů
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//סַ
};

struct Addressbooks//ͨѶ¼�ṹ��
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//��¼�ĸ���
	int m_Size;
};

void ShowMenu()//�˵�չʾ
{
	cout << "*************************" << endl;
	cout << "***** 1. �����ϵ�� *****" << endl;
	cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
	cout << "***** 3. ɾ����ϵ�� *****" << endl;
	cout << "***** 4. ������ϵ�� *****" << endl;
	cout << "***** 5. �޸���ϵ�� *****" << endl;
	cout << "***** 6. �����ϵ�� *****" << endl;
	cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
	
}

//1. �����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж��Ƿ�����
	if (abs->m_Size == MAX)
		cout << "ͨѶ¼�������޷����!" << endl;
	else {
		//���
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա�1.�� 2.Ů��" << endl;
		int sex;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "����������������룺 " << endl;
			}
		}

		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "������绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//��������
		abs->m_Size++;

		cout << "��ӳɹ���" << endl;

		system("pause");
		system("cls");
	}
}

//2. ��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж��Ƿ�Ϊ��
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name<<"\t";
			cout << "�Ա�" << ((abs->personArray[i].m_Sex) == 1 ?"��" :"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr <<endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ������򷵻��±꣬�����ڷ���-1
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

//3. ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret != -1) {
		//ɾ����ret���ÿ������ǰ�ƶ�1
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//��������
		cout << "ɾ���ɹ���" << endl;
	}
	else
		cout << "�޴���" << endl;
	system("pause");
	system("cls");
}

//4. ������ϵ��
void findPerson(Addressbooks* abs)
{

	string name;
	cout << "������Ҫ���ҵ���ϵ�˵�������" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << ((abs->personArray[ret].m_Sex) == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
		cout << "�޴���" << endl;
	system("pause");
	system("cls");
}

//5. �޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//����
		cout << "����������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		cout << "�����������Ա𣺣�1. ��  2. Ů��" << endl;
		int sex;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "����������������룺" << endl;
			}
		}

		//����
		cout << "�������������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << "������������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		cout << "�����������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}

	else {
		cout << "�޴���" << endl;
	}

	system("pause");
	system("cls");
}

//6. ���ͨѶ¼
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "�����" << endl;
	system("pause");
	system("cls");
}

int main()
{

	//����ͨѶ¼
	Addressbooks abs;
	abs.m_Size = 0;


	int select = 0;


	while (1) {

		ShowMenu();

		cin >> select;

		switch (select)
		{
		case 1://���
			addPerson(&abs);//��ַ����
			break;
		case 2://��ʾ
			showPerson(&abs);
			break;
		case 3://ɾ��
			deletePerson(&abs);
			break;
		case 4://����
			findPerson(&abs);
			break;
		case 5://�޸�
			modifyPerson(&abs);
			break;
		case 6://���
			cleanPerson(&abs);
			break;
		case 0://�˳� 
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;


		}
	}
	system("pause");
	return 0;
}

