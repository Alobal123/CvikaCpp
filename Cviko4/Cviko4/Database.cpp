
#include "stdafx.h"
#include "Database.h"

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
	std::vector<std::string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == std::string::npos) pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

void Database::AddRow(const std::string &row)
{
	std::vector<std::string> tokens = split(row, ",");
	for (size_t i = 0; i != tokens.size(); i++) {
		std::vector<std::string> key_value = split(tokens[i], ":");
		columns[key_value[0]]->add(key_value[1]);
	}
	number_of_rows++;
}


void Database::Print()
{
	for (size_t i = 0; i < number_of_rows; i++)
	{
		for (std::map<std::string, std::unique_ptr<AbstractColumn>>::iterator it = columns.begin(); it != columns.end(); ++it) {
			std::cout << columns[it->first]->get_at_as_string(i) << " ";
		}
		std::cout << std::endl;
		
	}

}

int main(){
	Database d = Database();
	d.InsertColumn("name", string);
	d.InsertColumn("age", integer);
	d.AddRow("name:Alex,age:7");
	d.AddRow("name:Kate,age:23");
	d.Print();


}
