#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <string>
#include "../file_to_string.h"


TEST_CASE( "Test functions for get in config define info.", "[get-functions]" ){
	SECTION("get connect string")
	{
		CHECK(file_to_string("../../file.txt") == ""
				"CREATE TABLE IF NOT EXISTS human ( "
					"id SERIAL PRIMARY KEY, "
					"name VARCHAR(16), "
					"patronymic VARCHAR(32), "
					"family VARCHAR(24) "
				"); "

				"CREATE TABLE IF NOT EXISTS username ( "
					"id SERIAL PRIMARY KEY, "
					"nick VARCHAR(16) UNIQUE NOT NULL, "
					"human_id INTEGER REFERENCES human(id) "
				"); "

				"CREATE TABLE IF NOT EXISTS groupname ( "
				"id SERIAL PRIMARY KEY, "
				"name VARCHAR(32) UNIQUE NOT NULL "
				"); "

				"CREATE TABLE IF NOT EXISTS groupname_username ( "
				"groupname_id INTEGER REFERENCES groupname(id), "
				"username_id INTEGER REFERENCES username(id) "
				"); "

				"ALTER TABLE groupname_username ADD "
				"CONSTRAINT gu_pk PRIMARY KEY (groupname_id, username_id);"
		);
	}
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}
