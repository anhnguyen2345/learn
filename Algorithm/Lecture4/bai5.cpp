#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
stack<int> st;
int val[16];

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		} else if (s[i] == ')') {
			int v = ')', total = 0;
			while (v != '(') {
				v = st.top();
				st.pop();
				if (v != '(') total += v;
			}
			st.push(total);
		} else if (s[i] == 'C') {
            //cout << "stack push " << s[i] << endl;
			st.push(12);
        }
        else if (s[i] == 'H') {
            //cout << "stack push " << s[i] << endl;
            st.push(1);
        }
        else if (s[i] == 'O') {
            //cout << "stack push " << s[i] << endl;
            st.push(16);
        }
        else { // 2 -> 9
			int v = st.top();
            //cout << "stack pop " << v << endl;
            //cout << (s[i] - 48) << endl;
			st.pop();
			st.push(v * (s[i] - 48));
		}
        //cout << "stack top" << st.top() << endl;
	}

	int res = 0;
	while (!st.empty()) {
        //cout << "stack " << st.size() << endl;
		res += st.top();
		st.pop();
	}

	cout << res << endl;

	return 0;
}
