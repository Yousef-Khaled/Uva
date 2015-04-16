#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main() {

	string z;
	vector<string> vec;
	while (cin >> z) {
		if (z == "#") {
			break;
		}
		vec.push_back(z);
	}
	pair<char, char> p;
	map<pair<char, char>, int> m;
	vector<pair<char, char> > Help;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			for (int l = 0; l < min(vec[i].size(), vec[j].size()); l++) {
				if (vec[i][l] != vec[j][l]) {
					p.first = vec[i][l];
					p.second = vec[j][l];
					if (!m[p])
						Help.push_back(p);
					m[p]++;
					break;
				}
			}
		}
	}
	sort (Help.begin(),Help.end());
	vector<pair<int, char> > r;
	vector<char> temp;
	map<char, int> m2;
	int c = 0;

/*
	for (int i = 0; i < Help.size(); i++)
		cout << Help[i].first << " " << Help[i].second << endl;
*/



	for (int i = 0; i < Help.size(); i++) {
		m2[Help[i].first]++;
		temp.clear();
		c = 0;
		temp.push_back(Help[i].second);
		if (i != 0 && Help[i].first == Help[i - 1].first)
			continue;
		for (int j = 0; j < Help.size(); j++) {
			if (Help[i].first == Help[j].first)
				c++;
			else {
				for (int k = 0; k < temp.size(); k++) {
					if (temp[k] == Help[j].first) {
						c++;
						temp.push_back(Help[j].second);
						break;
					}
				}
			}

		}
		//cout << c << endl;
		r.push_back(make_pair(c, Help[i].first));
	}
	sort(r.begin(), r.end());
	reverse(r.begin(), r.end());
	for (int i = 0; i < Help.size(); i++) {
		if (!m2[Help[i].second]) {
			r.push_back(make_pair(0, Help[i].second));
			break;
		}
	}
	for (int i = 0; i < r.size(); i++) {
		cout << r[i].second;
	}

	cout << endl;
}
