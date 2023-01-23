#include <gtest/gtest.h>
#include "../employee.h"


// global variable for initialization & testing
Employee g_emp("emp1", "001", "Eng", 15);


struct Employee_fixture: public testing::Test
{
	Employee* emp_ptr;
	
	// called before a test
	void SetUp() {
		emp_ptr = new Employee(g_emp.name,g_emp.id,g_emp.job,g_emp.salary);
	}

	// called after a test
	void TearDown() {
		delete emp_ptr;
	}
};


TEST_F(Employee_fixture, test_name_initialization){
    
    ASSERT_STREQ(g_emp.name.c_str(),emp_ptr->name.c_str());
}

TEST_F(Employee_fixture, test_id_initialization){
    
    ASSERT_STREQ(g_emp.id.c_str(),emp_ptr->id.c_str());
}

TEST_F(Employee_fixture, test_job_initialization){
    
    ASSERT_STREQ(g_emp.job.c_str(),emp_ptr->job.c_str());
}

TEST_F(Employee_fixture, test_salary_initialization){
    
    ASSERT_EQ(g_emp.salary,emp_ptr->salary);
}

TEST(Employee_module, test_add_function){
	
	Employee::add(g_emp);

	ASSERT_EQ(Employee::all_employees.size(), 1);
}

TEST(Employee_module, test_remove_function){
	
	Employee::add(g_emp);
	g_emp.remove();

	ASSERT_EQ(Employee::all_employees.size(), 0);
}

TEST(Employee_module, test_search_by_name_function){
	g_emp.name = "first employee";
	Employee::add(g_emp);

	vector<Employee> result = Employee::search(Name, "first");

	ASSERT_STREQ(result[0].name.c_str(), "first employee");
}

TEST(Employee_module, test_search_by_id_function){
	g_emp.id = "0101";
	Employee::add(g_emp);

	vector<Employee> result = Employee::search(ID, "0101");

	//compare with full ID, search by ID doesn't use reg ex
	ASSERT_STREQ(result[0].id.c_str(), "0101"); 
}

TEST(Employee_module, test_search_by_job_function){
	g_emp.job = "senior qa";
	Employee::add(g_emp);

	vector<Employee> result = Employee::search(Job, "qa");
	ASSERT_STREQ(result[0].job.c_str(), "senior qa");
}