#include <gtest/gtest.h>
#include "../vehicle.h"


// global variable for initialization & testing
Vehicle g_vehicle("oem1", "model1", 100, 2010, 5);


struct Vehicle_fixture: public testing::Test
{
	Vehicle* vehicle_ptr;
	
	// called before a test
	void SetUp() {
		vehicle_ptr = new Vehicle(g_vehicle.oem, g_vehicle.model, g_vehicle.cost, g_vehicle.release_year, g_vehicle.stock);
	}

	// called after a test
	void TearDown() {
		delete vehicle_ptr;
	}
};


TEST_F(Vehicle_fixture, test_OEM_initialization){
    
    ASSERT_STREQ(g_vehicle.oem.c_str(), vehicle_ptr->oem.c_str());
}

TEST_F(Vehicle_fixture, test_model_initialization){
    
    ASSERT_STREQ(g_vehicle.model.c_str(),vehicle_ptr->model.c_str());
}

TEST_F(Vehicle_fixture, test_cost_initialization){
    
    ASSERT_EQ(g_vehicle.cost,vehicle_ptr->cost);
}

TEST_F(Vehicle_fixture, test_release_year_initialization){
    
    ASSERT_EQ(g_vehicle.release_year,vehicle_ptr->release_year);
}

TEST_F(Vehicle_fixture, test_stock_initialization){
    
    ASSERT_EQ(g_vehicle.stock,vehicle_ptr->stock);
}

TEST(Vehicle_module, test_add_function){
	
	Vehicle::add(g_vehicle);

	ASSERT_EQ(Vehicle::all_vehicles.size(), 1);
}

TEST(Vehicle_module, test_remove_function_with_stock_1){
	Vehicle::all_vehicles.clear();
	Vehicle temp_vehicle("temp1", "temp1", 100, 2010, 1);
	Vehicle::add(temp_vehicle);
	temp_vehicle.sell();

	ASSERT_EQ(Vehicle::all_vehicles.size(), 0);
}

TEST(Vehicle_module, test_remove_function_with_stock_more_than_1){
	Vehicle::all_vehicles.clear();
	Vehicle temp_vehicle("temp10", "temp10", 100, 2010, 2);
	Vehicle::add(temp_vehicle);
	temp_vehicle.sell();

	ASSERT_EQ(Vehicle::all_vehicles.size(), 1);
}

TEST(Vehicle_module, test_search_str_function_with_oem){
	g_vehicle.oem = "OEM2";
	Vehicle::add(g_vehicle);

	vector<Vehicle> result = Vehicle::search_str(OEM, "M2");

	ASSERT_STREQ(result[0].oem.c_str(), "OEM2");
}

TEST(Vehicle_module, test_search_str_function_with_model){
	g_vehicle.model = "model2";
	Vehicle::add(g_vehicle);

	vector<Vehicle> result = Vehicle::search_str(Model, "del2");

	ASSERT_STREQ(result[0].model.c_str(), "model2");
}

TEST(Vehicle_module, test_search_range_function_with_cost){
	
	// add 4 vehicles
	Vehicle v1 = g_vehicle;
	v1.cost = 150;

	Vehicle v2 = g_vehicle;
	v2.cost = 200;

	Vehicle v3 = g_vehicle;
	v3.cost = 250;

	Vehicle v4 = g_vehicle;
	v4.cost = 300;

	Vehicle::add(v1); // out-of-range
	Vehicle::add(v2);
	Vehicle::add(v3);
	Vehicle::add(v4); // out-of-range

	vector<Vehicle> result = Vehicle::search_range(Cost, 180, 280);

	ASSERT_EQ(result.size(), 2);
}

TEST(Vehicle_module, test_search_range_function_with_release_year){
	
	// add 4 vehicles
	Vehicle v1 = g_vehicle;
	v1.release_year = 2010;

	Vehicle v2 = g_vehicle;
	v2.release_year = 2015;

	Vehicle v3 = g_vehicle;
	v3.release_year = 2020;

	Vehicle v4 = g_vehicle;
	v4.release_year = 2025;

	Vehicle::add(v1); // out-of-range
	Vehicle::add(v2);
	Vehicle::add(v3);
	Vehicle::add(v4);

	vector<Vehicle> result = Vehicle::search_range(Release_Year, 2012, 2030);

	ASSERT_EQ(result.size(), 3);
}