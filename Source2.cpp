
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;
	int l;
	while (cin >> n){

		cin >> l;
		vector<int> v1(n, 0);
		v1[0] = 1;
		int temp;
		int res = 1;
		for (int i = 0; i < n - 1; i++){
			cin >> temp;
			v1[i + 1] = v1[temp] + 1;
			if (v1[i + 1]>res){
				res = v1[i + 1];
			}
		}
		if (res < l + 1){
			int res_temp = res + (l - res + 1) / 2;
			if (res_temp > n){
				cout << n << endl;
			}
			else{
				cout << res + (l - res + 1) / 2 << endl;
			}

		}
		else{
			cout << l + 1 << endl;
		}
	}
	return 0;
}