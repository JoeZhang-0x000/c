/**
 1.高精度计算

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

//交换a,b
void swap(void* a, void* b, int size) {
	void* buffer = (void*)malloc(size);
	memcpy(buffer, a, size);
	memcpy(a, b, size);
	memcpy(b, buffer, size);
	free(buffer);
}

//c = a +b, a的位数大于b
void highPrecisionAdd(char* a, char* b, int la, int lb) {
	int i,n,tem,carry,n1,n2;
	char c[1024];
	inverse(a, la);
	inverse(b, lb);
	//cout << "a转置后" << a << endl;
	//cout << "b转置后" << b << endl;
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
		//大于10需要进位
		if (tem >= 10) {
			carry = 1;
			tem = tem - 10;
		}
		c[i] = tem + '0';
		i++;
	}
	//得数最高位进位溢出
	if (carry == 1) {
		n++;
		c[i] = 1+'0';
	}
	//打印得数
	inverse(c, n);
	cout << "output:";
	for (i = 0; i < n; i++)
		cout << c[i];
	cout << endl;

}
//转置
void inverse(char* a, int len) {
	for (int i = 0; i < len/2; i++)
		swap(a + i, a + len - i-1, sizeof(char));
}
//判断一个字符是否为数字
bool isNumber(char* a) {
	const char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 10; i++)
		if (*a == numbers[i])
			return true;
	return false;
}
//判断是否合法
bool isLegal(char* a, int len) {
	for (int i = 0; i < len; i++)
		//当字符串中有一项不为数字时候，那么就不合法
		if (!isNumber(a + i))
			return false;
	return true;
}

void menu() {
	char ch;
	string a;
	string b;
	while (true) {
		cout << "按ENTER键以继续" << endl;
		cin.ignore(1024, '\n');
		cin.get();
		system("cls");
		cout << "c--------进入程序高精度计算" << endl;
		cout << "q---------退出" << endl;
		cin >> ch;
		switch (ch)
		{
		case ('c'):
		case ('C'):
			cout << "请输入两个数字" << endl;
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
				cout << "您的输入不合法！不能含有非法字符！" << endl;
			break;
		case('q'):
		case('Q'):
			return;
		default:
			cout << "不合法的输入！请重试" << endl;
			break;
		}

	}
}
**/

/**
* 2.迷你搜索软件
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
	//设置一个flag，用于表示是否找到了，如果找了子字符串那么flag设为1，否则为0
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
			//找到了
			flag = 1;
			break;
		}
	//找到了就返回第一次匹配的下标记，没找到就返回-1
	return (flag)?i-l2:-1;
}
void menu() {
	int n;
	char ch;
	string src,target;
	while (true) {
		cout << "按ENTER键以继续" << endl;
		cin.ignore(1024, '\n');
		cin.get();
		system("cls");
		cout << "s----------更改SRC字符串" << endl;
		cout << "t------------查找TARGET字符串" << endl;
		cout << "q---------退出" << endl;
		cout << "目前的SRC字符串为:";
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
			cout << "输入不合法！请重试！" << endl;
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
//上一道题的那个函数直接照搬过来...
int  msearch(string &src,string &tg) {
	int l1 = src.length();
	int l2 = tg.length();
	//设置一个flag，用于表示是否找到了，如果找了子字符串那么flag设为1，否则为0
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
			//找到了
			flag = 1;
			break;
		}
	//找到了就返回第一次匹配的下标记，没找到就返回-1
	return (flag) ? i - l2 : -1;
}
bool isLegal_c(string& s) {
	int na = 0;
	bool result = true;
	string ileagl[] = {"@.",".@",".","@",".."};
	int index[5];
	//判断几种非法型式， @., .@,  xxx., xxx@
	for (int i = 0; i < 5;i++) {
		index[i] = msearch(s, ileagl[i]);
	}
	//@. 或者.@出现
	if (index[0]!=-1||index[1] !=-1)
		result = false;
	// . 或者 @出现在末尾
	if (index[3] == (s.length() - 1)||index[4]==(s.length()-1))
		result = false;
	//. 或者 @出现在开头
	if (index[3] == (0)||index[4]==(0))
		result = false;
	//出现多个..连着
	if (index[4] != -1)
		result = false;
	//没有@或者没有.
	if (index[2] == -1 || index[3] == -1)
		result = false;
	for (int i = 0; i < s.length(); i++) {
		if (na > 1)
			result = false;
		//统计@数量
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
		cout << "按ENTER键以继续，第一次要多按两下" << endl;
		cin.ignore(1024, '\n');
		cin.get();
		system("cls");
		cout << "e----------输入一个邮箱" << endl;
		cout << "r------------检测邮箱是否合法(采用正则表达式判断)" << endl;
		cout << "c-------------检测邮箱是否合法(采用if-else判断)" << endl;
		cout << "q---------退出" << endl;
		cout << "MAIL：";
		for (int i = 0; i < s.length(); i++)
			cout << s[i];
		cout << endl;
		cout << ">>";
		cin >> ch;
		switch (ch)
		{
		case ('e'):
		case ('E'):
			cout << "更改邮箱：" << endl;
			cout << ">>";
			cin >> s;
			break;
		case('R'):
		case('r'):
			if (isLegal_regex(s))
				cout << "是标准的邮箱格式" << endl;
			else
				cout << "不是标准的邮箱格式" << endl;
			break;
		case('c'):
		case('C'):
			if (isLegal_c(s))
				cout << "是标准的邮箱格式" << endl;
			else
				cout << "不是标准的邮箱格式" << endl;
			break;
		case ('q'):
		case('Q'):
			return;
			break;
		default:
			cout << "输入不合法！请重试！" << endl;
			break;
		}
	}
}
**/