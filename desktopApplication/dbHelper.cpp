#include "dbHelper.hpp"
#include <vector>

dbHelper::dbHelper(){

}

dbHelper::~dbHelper(){

}

std::string dbHelper::getNameOne() {
	try {
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "");

        con->setSchema("printer");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM print");

        std::vector<std::string> result;
        while (res->next())
            result.push_back(res->getString("filename"));

        delete res;
        delete stmt;
        delete con;

        return result[0];
	}
	catch (sql::SQLException & e) {
		return e.what();
	}
	
}