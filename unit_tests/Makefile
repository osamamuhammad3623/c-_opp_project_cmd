employee-test:
	@g++ main.cpp employee_test.cpp ../employee.cpp -o output -std=c++17 -lgtest -lgtest_main
	@./output

vehicle-test:
	@g++ main.cpp vehicle_test.cpp ../vehicle.cpp -o output -std=c++17 -lgtest -lgtest_main
	@./output

system-test:
	@g++ main.cpp system_test.cpp ../system.cpp -o output -std=c++17 -lgtest -lgtest_main
	@./output


test_sourcefiles = *.cpp ../employee.* ../vehicle.* ../system.*

all:
	@g++ $(test_sourcefiles) -o output -std=c++17 -lgtest -lgtest_main
	@./output
	