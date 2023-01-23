#include "../system.h"
#include <gtest/gtest.h>
#include <fstream>
using namespace std;

TEST(Password_Control, test_load_password){
    // use System function to read, write with a stream

    string test_pass = "testing System::load_password";
    
    fstream file;
    file.open("../user_pass");
    
    if(file.is_open()){
        file << test_pass;
    }

    string stored_pass = System::load_password();

    ASSERT_STREQ(test_pass.c_str(), stored_pass.c_str());
}

// TEST(Password_Control, test_store_password){
//     // use System function to write, read with a stream

//     string test_pass = "testing System::store_password";
//     System::store_password(test_pass);

//     fstream file;
//     file.open("../user_pass");
    
//     string stored_pass{};
//     if(file.is_open()){
//         file >> stored_pass;
//     }

//     ASSERT_STREQ(test_pass.c_str(), stored_pass.c_str());
// }
