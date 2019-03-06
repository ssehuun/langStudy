/*
19.02.14
<Stack implemented with STL>

input value
8
size
push 4
push 3
top
size
pop
top
size

output value
0
3
2
4
1
*/

#include <stack>
#include <iostream>
#include <string>
using namespace std;
 
int N, val;
string cmd;
int main(){
	stack<int> st;
 
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> cmd;
		if(cmd[0] == 's'){
			cout << st.size() << endl;
		}else if(cmd[0] == 'p'){
			if(cmd[1] == 'u'){
				cin >> val;
				st.push(val);
			}else if(cmd[1] == 'o'){
				st.pop();
			}
		}else if(cmd[0] == 't'){
			cout << st.top() << endl;
		}
	}
	return 0;
}
