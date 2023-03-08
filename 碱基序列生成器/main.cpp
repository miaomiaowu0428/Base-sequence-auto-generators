#include<iostream>
#include<fstream>
#include<map>
#include<ranges>
#include<string_view>
using namespace std;

int main(int argc, char* argv[]) {
	string path = argc > 1 ? argv[1] : "input.txt";
	fstream input_file;
	input_file.open(path, ios::in | ios::out);
	if (argc > 0 && !input_file.is_open()) {
		cout << "输入文件未找到，请检查路径或文件名是否拼写错误" << endl;
		exit(1);
	}
	fstream output_file;
	output_file.open("output.txt", ios::in | ios::out | ios::trunc);

	string input_text;
	input_file >> input_text;
	output_file << input_text << endl;

	std::map<char, char> transform_table{ {'A','T'},{'T','A'},{'C','G'},{'G','C'}, };
	for (char ch : input_text | views::transform([&transform_table](char& ch)->char {
		return transform_table.contains(ch) ? transform_table[ch] : ' ';
		})) {
		output_file << ch;
	}

	cout << "已完成，请检查 \"output.txt\" 文件" << endl;
}