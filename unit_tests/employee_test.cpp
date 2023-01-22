#include <gtest/gtest.h>
#include "../employee.h"


// global variables for initialization & testing
string name = "emp1";
string id = "001";
string job = "Eng";
int salary = 15;


struct Employee_fixture: public testing::Test
{
	Employee* emp_ptr;
	
	// called before a test
	void SetUp() {
		emp_ptr = new Employee(name,id,job,salary);
	}

	// called after a test
	void TearDown() {
		delete emp_ptr;
	}
};


TEST_F(Employee_fixture, test_name_initialization){
    
    ASSERT_STREQ(name.c_str(),emp_ptr->name.c_str());
}

TEST_F(Employee_fixture, test_id_initialization){
    
    ASSERT_STREQ(id.c_str(),emp_ptr->id.c_str());
}

TEST_F(Employee_fixture, test_job_initialization){
    
    ASSERT_STREQ(job.c_str(),emp_ptr->job.c_str());
}

TEST_F(Employee_fixture, test_salary_initialization){
    
    ASSERT_EQ(salary,emp_ptr->salary);
}

TEST(Employee_module, test_add_function){
	
	Employee emp(name,id,job,salary);
	Employee::add(emp);

	ASSERT_EQ(Employee::all_employees.size(), 1);
}

TEST(Employee_module, test_remove_function){
	
	Employee emp(name,id,job,salary);
	Employee::add(emp);
	emp.remove();

	ASSERT_EQ(Employee::all_employees.size(), 0);
}

TEST(Employee_module, test_search_by_name_function){
	Employee emp("first employee",id,job,salary);
	Employee::add(emp);

	vector<Employee> result = Employee::search(Name, "first");

	ASSERT_STREQ(result[0].name.c_str(), "first employee");
}

TEST(Employee_module, test_search_by_id_function){
	Employee emp(name,"0101",job,salary);
	Employee::add(emp);

	vector<Employee> result = Employee::search(ID, "0101");

	//compare with full ID, search by ID doesn't use reg ex
	ASSERT_STREQ(result[0].id.c_str(), "0101"); 
}

TEST(Employee_module, test_search_by_job_function){
	Employee emp(name,id,"senior qa",salary);
	Employee::add(emp);

	vector<Employee> result = Employee::search(Job, "qa");
	ASSERT_STREQ(result[0].job.c_str(), "senior qa");
}