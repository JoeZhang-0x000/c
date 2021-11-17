/**
 1.�߾��ȼ���

#include<iostream>
#include<string>
using namespace std;
void menu();
void highPrecisionAdd(char*,char*);
void inverse(char*,int);
void swap(void*, void*, int);
bool isLegal(char*, int);
bool isNumber(char*);
int main() {

	menu();
	return(EXIT_SUCCESS);
}

//����a,b
void swap(void* a, void* b, int size) {
	void* buffer = (void*)malloc(size);
	memcpy(buffer, a, size);
	memcpy(a, b, size);
	memcpy(b, buffer, size);
	free(buffer);
}

//c = a +b, a��λ������b
void highPrecisionAdd(char* a, char* b, int la, int lb) {
	int i,n,tem,carry,n1,n2;
	char c[1024];
	inverse(a, la);
	inverse(b, lb);
	//cout << "aת�ú�" << a << endl;
	//cout << "bת�ú�" << b << endl;
	i = 0, n = 0, carry = 0;
	while (i < la) {
		n++;
		n1 = *(a + i) - '0';
		if (i < lb)
			n2 = *(b + i) - '0';
		else
			n2 = 0;
		tem = n1 + n2 + carry;
		carry = 0;
		//����10��Ҫ��λ
		if (tem >= 10) {
			carry = 1;
			tem = tem - 10;
		}
		c[i] = tem + '0';
		i++;
	}
	//�������λ��λ���
	if (carry == 1) {
		n++;
		c[i] = 1+'0';
	}
	//��ӡ����
	inverse(c, n);
	cout << "output:";
	for (i = 0; i < n; i++)
		cout << c[i];
	cout << endl;

}
//ת��
void inverse(char* a, int len) {
	for (int i = 0; i < len/2; i++)
		swap(a + i, a + len - i-1, sizeof(char));
}
//�ж�һ���ַ��Ƿ�Ϊ����
bool isNumber(char* a) {
	const char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 10; i++)
		if (*a == numbers[i])
			return true;
	return false;
}
//�ж��Ƿ�Ϸ�
bool isLegal(char* a, int len) {
	for (int i = 0; i < len; i++)
		//���ַ�������һ�Ϊ����ʱ����ô�Ͳ��Ϸ�
		if (!isNumber(a + i))
			return false;
	return true;
}

void menu() {
	char ch;
	string a;
	string b;
	while (true) {
		cout << "��ENTER���Լ���" << endl;
		cin.ignore(1024, '\n');
		cin.get();
		system("cls");
		cout << "c--------�������߾��ȼ���" << endl;
		cout << "q---------�˳�" << endl;
		cin >> ch;
		switch (ch)
		{
		case ('c'):
		case ('C'):
			cout << "��������������" << endl;
			cin >> a;
			cin >> b;
			cout << "ur input1:" << a << endl;
			cout << "ur input2:" << b << endl;
			if (isLegal(&a[0], a.length()) && isLegal(&b[0], b.length()))
				if(a.length()>b.length())
					highPrecisionAdd(&a[0], &b[0],a.length(),b.length());
				else
					highPrecisionAdd(&b[0], &a[0],b.length(),a.length());
			else
				cout << "�������벻�Ϸ������ܺ��зǷ��ַ���" << endl;
			break;
		case('q'):
		case('Q'):
			return;
		default:
			cout << "���Ϸ������룡������" << endl;
			break;
		}

	}
}
**/

/**
* 2.�����������
**/
#include<iostream>
#include<string>
using namespace std;
void menu();
int search(char*,char*,int,int);
int main() {
	menu();
	return (EXIT_SUCCESS);
}
int  search(char* src, char* tg, int l1, int l2) {
	//����һ��flag�����ڱ�ʾ�Ƿ��ҵ��ˣ�����������ַ�����ôflag��Ϊ1������Ϊ0
	int i, j,flag;
	i = 0, j = 0, flag = 0;
	while (i <= l1)
		if (j < l2) {
			if (*(src + i) == *(tg + j))
				j++;
			else
				j = 0;
			i++;
		}
		else {
			//�ҵ���
			flag = 1;
			break;
		}
	//�ҵ��˾ͷ��ص�һ��ƥ����±�ǣ�û�ҵ��ͷ���-1
	return (flag)?i-l2:-1;
}
void menu() {
	int n;
	char ch;
	string src,target;
	while (true) {
		cout << "��ENTER���Լ���" << endl;
		cin.ignore(1024, '\n');
		cin.get();
		system("cls");
		cout << "s----------����SRC�ַ���" << endl;
		cout << "t------------����TARGET�ַ���" << endl;
		cout << "q---------�˳�" << endl;
		cout << "Ŀǰ��SRC�ַ���Ϊ:";
		for (int i = 0; i < src.length(); i++)
			cout << src[i];
		cout << endl;
		cout << ">>";
		cin >> ch;
		switch (ch)
		{
		case ('S'):
		case ('s'):
			cout << "input the src string:" << endl;
			cin >> src;
			break;
		case('t'):
		case('T'):
			n = -1;
			cout << "input the target string:" << endl;
			cin >> target;
			n = search(&src[0], &target[0], src.length(), target.length());
			if (n != -1)
				cout << "first find target at the index of " << n << endl;
			else
				cout << "not find target" << endl;
			break;
		case ('q'):
		case('Q'):
			return;
			break;
		default:
			cout << "���벻�Ϸ��������ԣ�" << endl;
			break;
		}
	}
}

/**
* 3.lab 10,practice 5
**
#include<iostream>
#include<string>
#include<regex>
using namespace std;
void menu();
int msearch(string&,string&);
bool isLegal_regex(string& , int);
bool isLegal_c(string&);
int main() {
	menu();

	return (EXIT_SUCCESS);
}
//��һ������Ǹ�����ֱ���հ����...
int  msearch(string &src,string &tg) {
	int l1 = src.length();
	int l2 = tg.length();
	//����һ��flag�����ڱ�ʾ�Ƿ��ҵ��ˣ�����������ַ�����ôflag��Ϊ1������Ϊ0
	int i, j, flag;
	i = 0, j = 0, flag = 0;
	while (i <= l1)
		if (j < l2) {
			if (src[i] ==tg[j])
				j++;
			else
				j = 0;
			i++;
		}
		else {
			//�ҵ���
			flag = 1;
			break;
		}
	//�ҵ��˾ͷ��ص�һ��ƥ����±�ǣ�û�ҵ��ͷ���-1
	return (flag) ? i - l2 : -1;
}
bool isLegal_c(string& s) {
	int na = 0;
	bool result = true;
	string ileagl[] = {"@.",".@",".","@",".."};
	int index[5];
	//�жϼ��ַǷ���ʽ�� @., .@,  xxx., xxx@
	for (int i = 0; i < 5;i++) {
		index[i] = msearch(s, ileagl[i]);
	}
	//@. ����.@����
	if (index[0]!=-1||index[1] !=-1)
		result = false;
	// . ���� @������ĩβ
	if (index[3] == (s.length() - 1)||index[4]==(s.length()-1))
		result = false;
	//. ���� @�����ڿ�ͷ
	if (index[3] == (0)||index[4]==(0))
		result = false;
	//���ֶ��..����
	if (index[4] != -1)
		result = false;
	//û��@����û��.
	if (index[2] == -1 || index[3] == -1)
		result = false;
	for (int i = 0; i < s.length(); i++) {
		if (na > 1)
			result = false;
		//ͳ��@����
		if (s[i] == '@')
			na++;
	}
	
	return result;
}
bool isLegal_regex(string& addr) {
	regex standard_mail_reg("[a-zA-Z0-9_]+(\.[a-zA-Z0-9_]+)*(@[a-zA-Z0-9_]+){1}(\.[a-zA-Z0-9_])+");
	smatch result;
	bool ismatch = regex_match(addr, result, standard_mail_reg);
	return ismatch;
}
void menu() {
	char ch;
	string s;
	while (true) {
		cout << "��ENTER���Լ�������һ��Ҫ�ఴ����" << endl;
		cin.ignore(1024, '\n');
		cin.get();
		system("cls");
		cout << "e----------����һ������" << endl;
		cout << "r------------��������Ƿ�Ϸ�(����������ʽ�ж�)" << endl;
		cout << "c-------------��������Ƿ�Ϸ�(����if-else�ж�)" << endl;
		cout << "q---------�˳�" << endl;
		cout << "MAIL��";
		for (int i = 0; i < s.length(); i++)
			cout << s[i];
		cout << endl;
		cout << ">>";
		cin >> ch;
		switch (ch)
		{
		case ('e'):
		case ('E'):
			cout << "�������䣺" << endl;
			cout << ">>";
			cin >> s;
			break;
		case('R'):
		case('r'):
			if (isLegal_regex(s))
				cout << "�Ǳ�׼�������ʽ" << endl;
			else
				cout << "���Ǳ�׼�������ʽ" << endl;
			break;
		case('c'):
		case('C'):
			if (isLegal_c(s))
				cout << "�Ǳ�׼�������ʽ" << endl;
			else
				cout << "���Ǳ�׼�������ʽ" << endl;
			break;
		case ('q'):
		case('Q'):
			return;
			break;
		default:
			cout << "���벻�Ϸ��������ԣ�" << endl;
			break;
		}
	}
}
**/