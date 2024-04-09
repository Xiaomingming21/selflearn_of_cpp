//系统需求：
//添加联系人：信息包括姓名，性别，年龄，联系电话，家庭住址，最多记录1000人
//显示联系人：显示通讯录中所有联系人信息 
//删除联系人：按照姓名删除
//查找联系人：按照姓名查找 
//修改联系人：按照姓名修改
//清空联系人：清空通讯录所有信息
//退出通讯录：退出

#include<iostream>
#include<string>

using namespace std;

#define MAX 1000

struct Person//联系人结构体
{
	string m_Name;//姓名
	int m_Sex;//性别  1. 男  2. 女
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//住址
};

struct Addressbooks//通讯录结构体
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//记录的个数
	int m_Size;
};

void ShowMenu()//菜单展示
{
	cout << "*************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空联系人 *****" << endl;
	cout << "***** 0. 退出通讯录 *****" << endl;
	cout << "*************************" << endl;
	
}

//1. 添加联系人
void addPerson(Addressbooks* abs)
{
	//判断是否已满
	if (abs->m_Size == MAX)
		cout << "通讯录已满，无法添加!" << endl;
	else {
		//添加
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别（1.男 2.女）" << endl;
		int sex;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "输入错误，请重新输入： " << endl;
			}
		}

		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新人数
		abs->m_Size++;

		cout << "添加成功！" << endl;

		system("pause");
		system("cls");
	}
}

//2. 显示联系人
void showPerson(Addressbooks* abs)
{
	//判断是否为空
	if (abs->m_Size == 0) {
		cout << "通讯录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name<<"\t";
			cout << "性别：" << ((abs->personArray[i].m_Sex) == 1 ?"男" :"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr <<endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，存在则返回下标，不存在返回-1
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

//3. 删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入需要删除的联系人" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	if (ret != -1) {
		//删除：ret后的每个人先前移动1
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新人数
		cout << "删除成功！" << endl;
	}
	else
		cout << "无此人" << endl;
	system("pause");
	system("cls");
}

//4. 查找联系人
void findPerson(Addressbooks* abs)
{

	string name;
	cout << "请输入要查找的联系人的姓名：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << ((abs->personArray[ret].m_Sex) == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
		cout << "无此人" << endl;
	system("pause");
	system("cls");
}

//5. 修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入所要修改的联系人姓名；" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		cout << "请重新输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		cout << "请重新输入性别：（1. 男  2. 女）" << endl;
		int sex;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "输入错误，请重新输入：" << endl;
			}
		}

		//年龄
		cout << "请重新输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请重新输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请重新输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}

	else {
		cout << "无此人" << endl;
	}

	system("pause");
	system("cls");
}

//6. 清空通讯录
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{

	//创建通讯录
	Addressbooks abs;
	abs.m_Size = 0;


	int select = 0;


	while (1) {

		ShowMenu();

		cin >> select;

		switch (select)
		{
		case 1://添加
			addPerson(&abs);//地址传递
			break;
		case 2://显示
			showPerson(&abs);
			break;
		case 3://删除
			deletePerson(&abs);
			break;
		case 4://查找
			findPerson(&abs);
			break;
		case 5://修改
			modifyPerson(&abs);
			break;
		case 6://清空
			cleanPerson(&abs);
			break;
		case 0://退出 
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;


		}
	}
	system("pause");
	return 0;
}

