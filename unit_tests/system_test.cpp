#include "../system.h"
#include <gtest/gtest.h>
#include <fstream>
using namespace std;

TEST(Password_Control, test_store_load_password){
    // test the load/store functions at once
    string p = "this is a test password";
    System::store_password(p, "../user_pass");

    string stored_p = System::load_password("../user_pass");
    ASSERT_STREQ(p.c_str(), stored_p.c_str());
}