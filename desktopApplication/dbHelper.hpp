#pragma once

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class dbHelper{

public:
	dbHelper();
	~dbHelper();

	std::string getNameOne();
};

