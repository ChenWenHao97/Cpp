/*************************************************************************
	> File Name: iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 23时00分05秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<int> v{1,2,3,4,5};
    for (auto it = v.begin(); it != v.end() - 2; ++it) {
        cout << *it << *(it + 1) << *(it + 2) << endl;
    }

    return 0;
}

