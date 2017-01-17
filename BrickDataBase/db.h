/*
*
* File: db.h
* Author: jtucker
*
* Created on 1_16_17
*/

#ifndef DB_H
#define DB_H

#include <sqlite3.h> 
#include <stdio.h>


	class DB {
		public: 
			int startDatabase();
			int insertIntoDatabase(char * sql);
			int closeDatabase();
			int getInfoFromDatabase(char * sql);
			int parseAndStore(std::string signature);
			int getAndRecreateSignature(int recordNum);
			int searchForSignature(std::string signature);

		private:
			sqlite3 * db;


	};



#endif
