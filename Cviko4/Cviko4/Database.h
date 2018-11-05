#pragma once
#include<string>
#include<map>
#include<vector>
#include <memory>
#include<iostream>

enum allowed_types : int{
	string, integer, floating_point
};


class AbstractColumn {
public:
	std::string name;
	virtual std::string get_at_as_string(size_t index) = 0;
	virtual void add(std::string value) = 0;
};

class StringColumn : public AbstractColumn {
	std::vector<std::string> column;
public:
	StringColumn(std::string name_) {
		column = std::vector<std::string>();
		name = name_;
	}
	virtual std::string get_at_as_string(size_t index) {
		return column[index];
	}
	virtual void add(std::string value) {
		column.push_back(value);
	}
};

class IntegerColumn : public AbstractColumn {
	std::vector<int> column;
public:
	IntegerColumn(std::string name_){
		name = name_;
		column = std::vector<int>();
	}
	virtual std::string get_at_as_string(size_t index) {
		return std::to_string(column[index]);
	}
	virtual void add(std::string value) {
		column.push_back(std::stoi(value));
	}
};

class DoubleColumn : public AbstractColumn {
	std::vector<double> column;
public:
	DoubleColumn(std::string name_){
		column = std::vector<double>();
		name = name_;
	}
	virtual std::string get_at_as_string(size_t index) {
		return std::to_string(column[index]);
	}
	virtual void add(std::string value) {
		column.push_back(std::stod(value));
	}
};

class Database {
public:
	Database() {
		columns = std::map<std::string, std::unique_ptr<AbstractColumn>>();
	};
	void InsertColumn(const std::string &name, const allowed_types &type) {
		switch (type) {
		case string:
			columns[name] = std::make_unique<StringColumn>(name);
			break;
		case integer:
			columns[name] = std::make_unique<IntegerColumn>(name);
			break;
		case floating_point:
			columns[name] = std::make_unique<DoubleColumn>(name);
			break;
		}
		
	};
	void AddRow(const std::string &row);
	void Print();
private:
		std::map<std::string, std::unique_ptr<AbstractColumn>> columns;
		int number_of_rows;
		
};


