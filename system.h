#include <iostream>
using namespace std;

namespace System{

    void display_menu(void);

    void wait_for_user(void);

    void change_password(void);

    bool user_login(void);

    string load_password(string file_name="user_pass");

    void store_password(string pass, string file_name="user_pass");

    int take_user_choice(void);
}