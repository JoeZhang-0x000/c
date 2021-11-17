#include <stack>
#include <iostream>
using namespace std;
 
int main()
{
	stack<int> mystack;
	int sum = 0;
	for (int i = 0; i <= 10; i++){
		mystack.push(i);
	}
	cout << "size is " << mystack.size() << endl;
	while (!mystack.empty()){
		cout << " " << mystack.top();
		mystack.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}
//size is 11
// 10 9 8 7 6 5 4 3 2 1 0