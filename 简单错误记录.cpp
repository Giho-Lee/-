/*
题目：https://www.nowcoder.com/practice/2baa6aba39214d6ea91a2e03dff3fbeb
*/

#include <iostream>
#include <map>
#include <string>
#include <cstddef>
#include <vector>
using namespace std;

#define RECORD_MAX 8

int main(void) {
    string filename, row_num, key;
    size_t name_size = 0;
    size_t start_index = 0;
    map<string, int> m_record;
    vector<string> s_record(RECORD_MAX, "");
	while (cin >> filename >> row_num) {
	    name_size = filename.length();
	    size_t index = filename.find_last_of("/\\");
	    index++;
	    if (index + 16 < name_size) {
	        index = name_size - 16;
	    }
	    key = filename.substr(index) + " " + row_num;
	    if (m_record.find(key) == m_record.end()) {
	        m_record[key] = 1;
	        s_record[start_index] = key;
	        start_index = (start_index + 1) % RECORD_MAX;
	    } else {
	        m_record[key]++;
	    }
	}
	
	for (int i = 0; i < RECORD_MAX; i++) {
	        if ("" != (key = s_record[start_index])) {
	            cout << key << " " << m_record[key] << endl;
	        }
	        
	        start_index = (start_index + 1) % RECORD_MAX;
	}
	
	return 0;
}