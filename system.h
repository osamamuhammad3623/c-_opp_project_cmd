#include <iostream>
#include <vector>

using namespace std;

namespace System{

    void display_menu(void);

    void wait_for_user(void);

    bool user_login(void);

    string load_password(string file_name="user_pass");

    void store_password(string pass, string file_name="user_pass");

    int take_user_choice(void);

    /* definition is in the header file, visit: https://stackoverflow.com/questions/14005060/undefined-reference-to */
    template<typename T>
    void display_search_result(vector<T> &result){
        if (!result.empty()){
            system("clear");
            cout << "Search results:\n";
            for(T &obj: result){
                obj.display();
            }
        }else{
            cout << "No results\n";
        }
    }
}