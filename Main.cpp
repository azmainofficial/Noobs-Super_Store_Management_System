#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

bool admin_login_states = false;
bool sales_login_states = false;

int colors[] ={ FOREGROUND_RED | FOREGROUND_INTENSITY, 
                FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
                FOREGROUND_GREEN | FOREGROUND_INTENSITY,
                FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
                FOREGROUND_BLUE | FOREGROUND_INTENSITY,
                FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,
                FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
                FOREGROUND_RED | FOREGROUND_INTENSITY, 
                FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
                FOREGROUND_GREEN | FOREGROUND_INTENSITY,
                FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
                FOREGROUND_BLUE | FOREGROUND_INTENSITY,
                FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,
                FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY  };


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void loadingBar() {
    int duration = 50;
    const int totalWidth = 50;
    for (int i = 0; i <= totalWidth; ++i) {
      

        system("cls");
        float progress = static_cast<float>(i) / totalWidth;
        int barWidth = static_cast<int>(progress * totalWidth);
        cout << "\033[1;32m";
        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "\033[0m";
        cout << "||               _______   _______   _______ _________    _________              _          _______                ||" << endl;
        cout << "                |       | |       | |            |            |     |         | | \\      | |                       " << endl;
        cout << "||              |       | |       | |            |            |     |         | |  \\     | |                       ||" << endl;
        cout << "                |_______  |       | |_______     |            |     |         | |   \\    | |_______                " << endl;
        cout << "||                      | |       | |            |            |     |         | |    \\   | |                       ||" << endl;
        cout << "                |       | |       | |            |            |     |         | |     \\  | |                       " << endl;
        cout << "||              |_______| |_______| |           _|_          _|_    |_________| |      \\_| |_______                ||" << endl;
        cout << "                                                                                                                     " << endl;
        cout << "||                                                                                                                 ||" << endl;
        cout << "                                                                                                                     " << endl;
        cout << "||                                                                                                                 ||" << endl;
        cout << "                                                                                                                     " << endl;
        cout << "||                                                                                                                 ||" << endl;
        cout << "                                                                                                                     " << endl;
        cout << "||                                                     LOADING                                                     ||" << endl;

        std::cout << "\r                              [";
        for (int j = 0; j < barWidth; ++j) {
            std::cout << "#";
        }
        for (int j = barWidth; j < totalWidth; ++j) {
            std::cout << " ";
        }
        std::cout << "] " << static_cast<int>(progress * 100.0f) << "%";
        std::cout.flush();
        cout<<"                                 " << endl;
    cout << "||                                                                                                                 ||" << endl;
    cout << "                                                                                                                     " << endl;
    cout << "||                                                                                                                 ||" << endl;
    cout << "                                                                                                                     " << endl;
    cout << "\033[1;32m";
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\033[0m";
        Sleep(duration);
    }
}

void top_nav()
{
    cout << "\033[1;32m";
    cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||    Soft Tune Super Store    |||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\033[0m";
}

void caption()
{
    cout << "\033[1;32m";
    cout << "\n+-------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|||||||||||||||||||||||||||||||       Allah Is The Almighty. May Allah Bless You !!       |||||||||||||||||||||||||||" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\033[0m";
    cout << "\nEnter your command:";
}

void welcome_1_temp()
{
    cout << "\n\t\t\t\t\t\n\n\n";
    cout << "\n\t\t\t\t\t    1. View Available Products";
    cout << "\n\t\t\t\t\t    2. Login to the System";
    cout << "\n\t\t\t\t\t    3. Exit from the System\n\n\n\n\n\n";
}

void login_temp()
{
    cout << "\n\t\t\t\t\t-------------: Login Panel :------------\n\n\n";
    cout << "\n\t\t\t\t\t             Login as\n\n\n";
    cout << "\n\t\t\t\t\t    1. Sales Executive";
    cout << "\n\t\t\t\t\t    2. Admin";
    cout << "\n\t\t\t\t\t    3. Back to Main panel\n\n\n\n\n";
}

void admin_panel_temp()
{
    cout << "\n\t\t\t\t\t-------------: Admin Panel :------------\n\n\n";
    cout << "\t\t\t\t\t\t   1. Inventory Management\n";
    cout << "\t\t\t\t\t\t   2. Sales Management\n";
    cout << "\t\t\t\t\t\t   3. Staff Management\n";
    cout << "\t\t\t\t\t\t   4. Membership Management\n";
    cout << "\t\t\t\t\t\t   5. Logout\n";
}

void inventory_management_panel_temp()
{
    cout << "\n\t\t\t\t\t-----: Inventory Management Panel :-----\n\n\n";
    cout << "\t\t\t\t\t\t   1. Search From Inventory\n";
    cout << "\t\t\t\t\t\t   2. Full Inventory View\n";
    cout << "\t\t\t\t\t\t   3. Add Goods To Inventory\n";
    cout << "\t\t\t\t\t\t   4. Remove Goods From Inventory\n";
    cout << "\t\t\t\t\t\t   5. Back To Admin Panel\n";
}

void staff_management_panel_temp()
{
    cout << "\n\t\t\t\t\t-------: Staff Management Panel :-------\n\n\n";
    cout << "\t\t\t\t\t\t   1. Staff Information Panel\n";
    cout << "\t\t\t\t\t\t   2. Add Stuff\n";
    cout << "\t\t\t\t\t\t   3. Remove Stuff\n";
    cout << "\t\t\t\t\t\t   4. Back To Admin Panel\n";
}

void staff_information_panel_temp()
{
    cout << "\n\t\t\t\t\t-------: Staff Information Panel :-------\n\n\n";
    cout << "\t\t\t\t\t\t    1. Full Staff List\n";
    cout << "\t\t\t\t\t\t    2. Search By ID\n";
    cout << "\t\t\t\t\t\t    3. Search By Name\n";
    cout << "\t\t\t\t\t\t    4. Search By Position\n";
    cout << "\t\t\t\t\t\t    5. Back To Staff Management Panel\n";
}

void membership_management_panel_temp()
{
    cout << "\n\t\t\t\t\t-----: Membership Management Panel :----\n\n\n";
    cout << "\t\t\t\t\t\t    1. Members Information List\n";
    cout << "\t\t\t\t\t\t    2. New Member\n";
    cout << "\t\t\t\t\t\t    3. Back To Admin Panel\n";
}

class Login{
    private:
        string admin_username = "a";
        string admin_password = "a";
        string sales_username = "s";
        string sales_password = "s";

    public:
        bool login(string username, string password){
            if (admin_username == username && admin_password == password){
                cout << "\n\t\t\t\t\t   Welcome to the system!" << endl;
                admin_login_states = true;
            }
            else if (admin_username == username){
                cout << "\t\t\t\t\t    Incorrect admin Password !!\n";
            }
            else if (sales_username == username && sales_password == password){
                cout << "\t\t\t\t\t     Welcome Sales Incharge\n";
                sales_login_states = true;
            }
            else if (sales_username == username){
                cout << "\t\t\t\t\t   Incorrect Sales Password !!\n";
            }
            else{
                cout << "\t\t\t\t\t   Incorrect Username & Password !!\n";
            }
        }

        void admin_login(string username, string password){
            if (admin_username == username && admin_password == password){
                cout << "\n\t\t\t\t\t   Welcome to the system!" << endl;
                admin_login_states = true;
            }
            else if (admin_username == username){
                cout << "\t\t\t\t\t    Incorrect admin Password !!\n";
            }
            else{
                cout << "\t\t\t\t\t    Incorrect Username & Password !!\n";
            }
        }

        void salesman_login(string username, string password){
            if (sales_username == username && sales_password == password){
                cout << "\n\t\t\t\t\t   Welcome to the system!" << endl;
                sales_login_states = true;
            }
            else if (sales_username == username){
                cout << "\t\t\t\t\t    Incorrect Password !!\n";
            }
            else{
                cout << "\t\t\t\t\t    Incorrect Username & Password !!\n";
            }
        }
};

class Product{
    private:
        string product_name;
        string id;
        double price;
        int quantity;
        string category;
        fstream Product_database;
    public:
        Product(){}

        void P_database_top_nav()
        {
            cout<<"+-------------------------------------------------------------------------------------------------------------------+"<<endl;
            cout<<"|                                        Product Database Information                                               |"<<endl;
            cout<<"+--------------+--------------------------+------------------------+-------------------------+----------------------+"<<endl;
            cout<<"|  Product ID  |       Product Name       |    Product Category    |      Product Price      |   Product Quantity   |"<<endl;
            cout<<"+--------------+--------------------------+------------------------+-------------------------+----------------------+"<<endl;
        }

        void stock_view(){

            Product_database.open("Product_database.txt", ios::in);

            string line;
            P_database_top_nav();

            while(getline(Product_database,line)){

                string p_id, p_name, p_category, p_price, p_quantity;
                stringstream ss(line);
                getline(ss, p_id, '$');
                getline(ss, p_name, '$');
                getline(ss, p_category, '$');
                getline(ss, p_price, '$');
                getline(ss, p_quantity, '$');

                cout << "| " << setw(12) << p_id << " | " << setw(24) << p_name << " | " << setw(22) << p_category << " | " << setw(23) << p_price << " | " << setw(20) << p_quantity << " |" << endl;
            }

            Product_database.close();
        }

        void searchByName(const string& name){
            Product_database.open("Product_database.txt",ios::in);
            string line;
            bool found = false;
            cout<<"Inventory Details of Product Name "<<name<<endl;

            if(!Product_database){
            cout << "Error opening the Product Database!\n";
            Sleep(2000);
            return;
            }
            P_database_top_nav();

            while(getline(Product_database,line)){
                size_t foundName = line.find(name);
                if(foundName != string::npos){
                    found = true;
                    string p_id, p_name, p_category, p_price, p_quantity;
                    stringstream ss(line);
                    getline(ss, p_id, '$');
                    getline(ss, p_name, '$');
                    getline(ss, p_category, '$');
                    getline(ss, p_price, '$');
                    getline(ss, p_quantity, '$');

                    cout << "| " << setw(12) << p_id << " | " << setw(24) << p_name << " | " << setw(22) << p_category << " | " << setw(23) << p_price << " | " << setw(20) << p_quantity << " |" << endl;

                }
            }//While

            if (!found) {
                cout << "\t\t\t\t\tProduct with name '" << name << "' not found." << endl;
                Sleep(2000);
            }
            Product_database.close();
        }//Search by name

        void addProductToInventory( string productId, string productName, string productCategory, double productPrice, int productQuantity) {

            Product_database.open("Product_database.txt", ios::in);
            ofstream tempFile("temp.txt", ios::out);

            if(!Product_database || !tempFile) {

                cout << "Error opening the Product Database!\n";
                Sleep(2000);
                return;
            }

            string line;
            bool found = false;

            while (getline(Product_database, line)) {

                stringstream ss(line);
                string p_id;
                getline(ss, p_id, '$');

                if (p_id == productId) {
                    found = true;
                    string p_name, p_category, p_price, p_quantity;
                    getline(ss, p_name, '$');
                    getline(ss, p_category, '$');
                    getline(ss, p_price, '$');
                    getline(ss, p_quantity, '$');

                    int currentQuantity = stoi(p_quantity);
                    currentQuantity += productQuantity;
                    tempFile << p_id << '$' << p_name << '$' << p_category << '$' << p_price << '$' << currentQuantity << '$' << endl;
                } 
                else {
                    tempFile << line << endl; 
               }
            }

            if(!found){   
                tempFile << productId << '$' << productName << '$' << productCategory << '$' << productPrice << '$' << productQuantity << '$' << endl;
            }

            Product_database.close();
            tempFile.close();

            remove("Product_database.txt");
            rename("temp.txt", "Product_database.txt");

            if(found) {
                cout << "Product quantity updated in inventory." << endl;
                Sleep(2000);
            }
            else{
                cout << "Product added to inventory successfully." << endl;
                Sleep(2000);
            }
    }

        void removeGoodsFromInventory(const string& productId, int quantityToRemove) {

            Product_database.open("Product_database.txt", ios::in);
            ofstream tempFile("temp.txt", ios::out);

            if(!Product_database || !tempFile) {
                cout << "Error opening the Product Database!\n";
                Sleep(2000);
                return;
            }

            string line;
            bool found = false;
            while(getline(Product_database, line)) {

                stringstream ss(line);
                string p_id;
                getline(ss, p_id, '$');

                if(p_id == productId) {
                    found = true;
                    string p_name, p_category, p_price, p_quantity;
                    getline(ss, p_name, '$');
                    getline(ss, p_category, '$');
                    getline(ss, p_price, '$');
                    getline(ss, p_quantity, '$');

                    int currentQuantity = stoi(p_quantity);

                    if(currentQuantity >= quantityToRemove) {
                        currentQuantity -= quantityToRemove;
                        tempFile << p_id << '$' << p_name << '$' << p_category << '$' << p_price << '$' << currentQuantity << '$' << endl;
                    }
                    else{
                    cout << "Error: Not enough quantity in stock to remove!" << endl;
                    tempFile << line << endl;
                    Sleep(2000);
                    }
                }
                else{
                tempFile << line << endl; 
                }
            }

            Product_database.close();
            tempFile.close();

            remove("Product_database.txt");
            rename("temp.txt", "Product_database.txt");

            if(found){
                cout << "Goods removed from inventory successfully!" << endl;
                Sleep(2000);
            }
            else{
                cout << "Product with ID '" << productId << "' not found in the inventory." << endl;
                Sleep(2000);
            }
        }

};

class Employee{
private:
    fstream Employee_database;
    string E_store_id;
    string E_name;
    string E_mobile_no;
    string E_permanent_address;
    string E_nid_no;
    string E_position;
    string E_bank_acc;

public:
    Employee(){}

    Employee(string id, string name, string m_no, string p_add, string nid, string poss, string acc)
    {
        this->E_store_id = id;
        this->E_name = name;
        this->E_mobile_no = m_no;
        this->E_permanent_address = p_add;
        this->E_nid_no = nid;
        this->E_position = poss;
        this->E_bank_acc = acc;
    }

    void display()
    {
        cout << "Store ID            : " << this->E_store_id << endl;
        cout << "Name                : " << this->E_name << endl;
        cout << "Mobile No           : " << this->E_mobile_no << endl;
        cout << "Permanent Address   : " << this->E_permanent_address << endl;
        cout << "NID NO              : " << this->E_nid_no << endl;
        cout << "Position            : " << this->E_position << endl;
        cout << "Bank Account Number : " << this->E_bank_acc << endl;
    }

    void E_database_top_nav()
    {
        cout << "+-------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                       Employee Database Information                                               |" << endl;
        cout << "+-----------+--------------------+---------------+-------------------------------------+---------------+------------+" << endl;
        cout << "| Store ID  |        Name        |   Mobile No   |          Permanent Address          |    NID NO     |  Position  |" << endl;
        cout << "+-----------+--------------------+---------------+-------------------------------------+---------------+------------+" << endl;
    }

    void add_to_database()
    {
        Employee_database.open("employee.txt", ios::app | ios::out);
        Employee_database << this->E_store_id << "$" << this->E_name << "$" << this->E_mobile_no << "$" << this->E_permanent_address << "$" << this->E_nid_no << "$" << this->E_position << "$" << this->E_bank_acc << endl;
        Employee_database.close();
        cout << "\t\t\t\tEmployee Data added successfully!" << endl;
        Sleep(2000);

    }

    void remove_from_database(string id)
    {
        ifstream inputFile("employee.txt");
        ofstream tempFile("temp_employee.txt");

        string line;
        bool found = false;

        while (getline(inputFile, line))
        {
            size_t foundId = line.find(id);
            if (foundId != string::npos)
            {
                found = true;
                continue; 
            }
            tempFile << line << endl;
        }

        inputFile.close();
        tempFile.close();

        if (found)
        {
            remove("employee.txt");
            rename("temp_employee.txt", "employee.txt");
            cout << "\n\n\n\t\t\t\t\tEmployee data removed successfully!" << endl;
            Sleep(2000);
        }
        else
        {
            remove("temp_employee.txt");
            cout << "\n\n\n\t\t\t\t\tEmployee ID not found in the database." << endl;
            Sleep(2000);
        }
    }

    void search_by_name(string name)
    {
        ifstream inputFile("employee.txt");
        string line;
        bool found = false;
        cout << "Employee details for name: " << name << endl;
        E_database_top_nav();

        while (getline(inputFile, line))
        {
            size_t foundName = line.find(name);
            if (foundName != string::npos)
            {
                found = true;
                string storeId, name, mobileNo, permanentAddress, nidNo, position, bankAcc;
                stringstream ss(line);
                getline(ss, storeId, '$');
                getline(ss, name, '$');
                getline(ss, mobileNo, '$');
                getline(ss, permanentAddress, '$');
                getline(ss, nidNo, '$');
                getline(ss, position, '$');
                getline(ss, bankAcc, '$');

                cout << "| " << setw(9) << storeId << " | " << setw(18) << name << " | " << setw(13) << mobileNo << " | " << setw(35) << permanentAddress << " | " << setw(13) << nidNo << " | " << setw(10) << position << " |" << endl;
            }
        }

        inputFile.close();

        if (!found)
        {
            cout << "No employee found with the name: " << name << endl;
            Sleep(2000);
        }
    }

    void search_by_id(string id)
    {
        ifstream inputFile("employee.txt");
        string line;
        bool found = false;
        cout << "Employee details for ID: " << id << endl;
        E_database_top_nav();

        while (getline(inputFile, line))
        {
            size_t foundId = line.find(id);
            if (foundId != string::npos)
            {
                found = true;
                string storeId, name, mobileNo, permanentAddress, nidNo, position, bankAcc;
                stringstream ss(line);
                getline(ss, storeId, '$');
                getline(ss, name, '$');
                getline(ss, mobileNo, '$');
                getline(ss, permanentAddress, '$');
                getline(ss, nidNo, '$');
                getline(ss, position, '$');
                getline(ss, bankAcc, '$');

                cout << "| " << setw(9) << storeId << " | " << setw(18) << name << " | " << setw(13) << mobileNo << " | " << setw(35) << permanentAddress << " | " << setw(13) << nidNo << " | " << setw(10) << position << " |" << endl;
                break;
            }
        }

        inputFile.close();

        if (!found)
        {
            cout << "No employee found with the ID: " << id << endl;
            Sleep(2000);
        }
    }

    void search_by_position(string position)
    {
        ifstream inputFile("employee.txt");
        string line;
        bool found = false;
        cout << "Employee details for position: " << position << endl;
        E_database_top_nav();

        while (getline(inputFile, line))
        {
            size_t foundPos = line.find(position);
            if (foundPos != string::npos)
            {
                found = true;
                string storeId, name, mobileNo, permanentAddress, nidNo, position, bankAcc;
                stringstream ss(line);
                getline(ss, storeId, '$');
                getline(ss, name, '$');
                getline(ss, mobileNo, '$');
                getline(ss, permanentAddress, '$');
                getline(ss, nidNo, '$');
                getline(ss, position, '$');
                getline(ss, bankAcc, '$');
                E_database_top_nav();

                cout << "| " << setw(9) << storeId << " | " << setw(18) << name << " | " << setw(13) << mobileNo << " | " << setw(35) << permanentAddress << " | " << setw(13) << nidNo << " | " << setw(10) << position << " |" << endl;
            }
        }

        inputFile.close();

        if (!found)
        {
            cout << "No employee found with the position: " << position << endl;
            Sleep(2000);
        }
    }

    void view_database()
    {
        ifstream inputFile("employee.txt");
        string line;

        E_database_top_nav();

        while (getline(inputFile, line))
        {
            string storeId, name, mobileNo, permanentAddress, nidNo, position, bankAcc;
            stringstream ss(line);
            getline(ss, storeId, '$');
            getline(ss, name, '$');
            getline(ss, mobileNo, '$');
            getline(ss, permanentAddress, '$');
            getline(ss, nidNo, '$');
            getline(ss, position, '$');
            getline(ss, bankAcc, '$');

            cout << "| " << setw(9) << storeId << " | " << setw(18) << name << " | " << setw(13) << mobileNo << " | " << setw(35) << permanentAddress << " | " << setw(13) << nidNo << " | " << setw(10) << position << " |" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
        }
        inputFile.close();
    }
    
};

class Member{
    private:
        fstream Member_database;

    public:

        void addNewMember( string id, string name, string address, string phone, int points) {

            Member_database.open("member_database.txt", ios::app | ios::out);

            if (!Member_database) {
                cout << "Error opening file!" << endl;
                Sleep(2000);
                return;
            }

            Member_database << id << "$" << name << "$" << address  << "$" << phone << "$" << points << endl;

            Member_database.close();
            cout << "\n\n\t\t\t\t\tNew member added successfully!" << endl;
            Sleep(2000);
        }

        void M_database_top_nav(){
                cout<<"+-------------------------------------------------------------------------------------------------------------------+"<<endl;
                cout<<"|                                          Members Database Information List                                        |"<<endl;
                cout<<"+--------------------+-----------------------+--------------------------------+--------------------+----------------+"<<endl;
                cout<<"|      Member ID     |      Member Name      |         Member Address         |    Phone Number    |  Total Points  |"<<endl;
                cout<<"+--------------------+-----------------------+--------------------------------+--------------------+----------------+"<<endl;            
        }
    
        void member_list_view(){

            Member_database.open("Member_database.txt", ios::in);
            string line;
            M_database_top_nav();
            while(getline(Member_database,line)){

                string M_id, M_name, M_add, M_mob_no , M_points;
                stringstream ss(line);
                getline(ss, M_id, '$');
                getline(ss, M_name, '$');
                getline(ss, M_add, '$');
                getline(ss, M_mob_no, '$');
                getline(ss, M_points, '$');

                cout << "| " << setw(18) << M_id << " | " << setw(21) << M_name << " | " << setw(30) << M_add << " | " << setw(18) << M_mob_no << " | " << setw(14) << M_points << " |" << endl;
                
            }
            cout<<"+--------------------+-----------------------+--------------------------------+--------------------+----------------+"<<endl;
            Member_database.close();
        }
    
    
};

class Cart{
    private:
    int total = 0 ;
    int quantity;

    public :

        fstream Product_database;
        fstream Cart_database;
        fstream Sales_record_database;

        void C_top_nav()
        {
            cout<<"+-------------------------------------------------------------------------------------------------------------------+"<<endl;
            cout<<"|                                                        Product Cart                                               |"<<endl;
            cout<<"+--------------+--------------------------+------------------------+-------------------------+----------------------+"<<endl;
            cout<<"|  Product ID  |                  Product Name                     |     Product Quantity    |     Product Price    |"<<endl;
            cout<<"+--------------+--------------------------+------------------------+-------------------------+----------------------+"<<endl;
        }

        void C_caption()
        {
            cout<<"+-------------------------------------------------------------------------------------------------------------------+"<<endl;
            cout<<"|                                                                                 Total Bill | "<< setw(15) << total<<" Taka |"<<endl;
            cout<<"+-------------------------------------------------------------------------------------------------------------------+"<<endl;
        }

        void cart_view(){

            Cart_database.open("Cart_database.txt",ios::in);

            string line;
            while (getline(Cart_database,line))
            {
                string p_id, p_name, p_price, p_quantity;
                stringstream ss(line);
                getline(ss, p_id, '$');
                getline(ss, p_name, '$');
                getline(ss, p_quantity, '$');
                getline(ss, p_price, '$');
                

                cout << "| " << setw(12) << p_id << " | " << setw(49) << p_name << " | " << setw(23) << p_quantity << " | " << setw(20) << p_price << " |" << endl;

            }
            Cart_database.close();
        
        }

        void add_to_cart(const string& product_id, int quantity) {
            ifstream Product_database("Product_database.txt");
            ofstream Cart_database("Cart_database.txt", ios::app);
            ofstream Temp_database("Temp_database.txt");

            if(!Product_database || !Cart_database || !Temp_database) {
                cout << "\t\t\t\tError opening database files." << endl;
                Sleep(2000);
                return;
            }

            string line;
            while (getline(Product_database, line)) {
                string p_id, p_name, p_quantity, p_category, p_price;
                stringstream ss(line);
                getline(ss, p_id, '$');
                getline(ss, p_name, '$');
                getline(ss, p_category, '$');
                getline(ss, p_price, '$');
                getline(ss, p_quantity, '$');

                if (p_id == product_id) {
                    int available_quantity = stoi(p_quantity);
                    if (quantity > available_quantity) {
                        cout << "\t\t\t\tNot enough stock available!" << endl;
                        Sleep(2000);
                        return;
                    }

                    total += quantity * stoi(p_price);

                    int updated_quantity = available_quantity - quantity;
                    Temp_database << p_id << "$" << p_name << "$" << p_category << "$" << p_price << "$" << updated_quantity << endl;

                    Cart_database << p_id << "$" << p_name << "$" << quantity << "$" << p_price << endl;

                    cout << "\t\t\t\tProduct added to cart successfully!" << endl;
                    Sleep(2000);
                }
                else{
                    Temp_database << line << endl;
                }
            }

            Product_database.close();
            Cart_database.close();
            Temp_database.close();

            remove("Product_database.txt");
            rename("Temp_database.txt", "Product_database.txt");
        }

        void record_cart() {
            ifstream Cart_database("Cart_database.txt");
            ofstream Sales_records("Sales_records_database.txt", ios::app);

            if (!Cart_database || !Sales_records) {
                cout << "Error opening database files." << endl;
                Sleep(2000);
                return;
            }

            Sales_records<<"+                                                                                                                   +"<<endl;
            Sales_records<<"+                                                                                                                   +"<<endl;
            Sales_records<<"+-------------------------------------------------------------------------------------------------------------------+"<<endl;
            Sales_records<<"|                                              Gross Invoice                                                        |"<<endl;
            Sales_records<<"+--------------+--------------------------+------------------------+-------------------------+----------------------+"<<endl;
            Sales_records<<"|  Product ID  |                   Product Name                    |     Product Quantity    |     Product Price    |"<<endl;
            Sales_records<<"+--------------+--------------------------+------------------------+-------------------------+----------------------+"<<endl;
        

            string line;
            while (getline(Cart_database, line)) {

                string p_id, p_name, p_price, p_quantity;
                stringstream ss(line);
                getline(ss, p_id, '$');
                getline(ss, p_name, '$');
                getline(ss, p_quantity, '$');
                getline(ss, p_price, '$');

                Sales_records << "| " << setw(12) << p_id << " | " << setw(49) << p_name << " | " << setw(23) << p_quantity << " | " << setw(20) << p_price << " |" << endl;
                Sales_records<<"---------------------------------------------------------------------------------------------------------------------"<<endl;


            }

            Sales_records<<"+-------------------------------------------------------------------------------------------------------------------+"<<endl;
            Sales_records<<"|                                                                                 Total Bill | "<< setw(15) << total<<" Taka |"<<endl;
            Sales_records<<"+-------------------------------------------------------------------------------------------------------------------+"<<endl;
            Sales_records<<"+                                                                                                                   +"<<endl;
            Sales_records<<"+                                                                                                                   +"<<endl;
            Sales_records<<"+===================================================================================================================+"<<endl;

            cout << "\t\t\t\tCheckout recorded successfully!" << endl;
            Sleep(1500);
            Cart_database.close();
            Sales_records.close();
        }

        void clean_cart_data() {
            ofstream Clean_Cart_database("Cart_database.txt", ios::trunc);

            if (!Clean_Cart_database) {
                cout << "Error opening Cart database file for cleaning." << endl;
                Sleep(2000);
                return;
            }

            Clean_Cart_database.close();
            cout << "\t\t\t\tCart data cleaned successfully!" << endl;
            Sleep(2000);
        }

        void sales_record_view()
        {
            Sales_record_database.open("Sales_records_database.txt", ios::in);
            string line;
            while (getline(Sales_record_database,line))
            {
                cout<<line<<"\n";
            }
            Sales_record_database.close();
        }

};

int main()
{
    fstream Employee_Database;
    Login o1;
    Product P1;
    Employee E1;
    Cart C1;
    Member M1;
    int choice;
    string sales_pw;
    string sales_un;
    loadingBar();

    //start of op
    do{
        open_bar:
        system("cls");
        top_nav();
        welcome_1_temp();
        caption();
        cin >> choice;
        switch (choice){
            //Stock view
            case 1:
            {
               system("cls");
               top_nav();
               P1.stock_view();
               caption();
               getch();
            }

            //Login
            case 2:
            {
                login_main:
                system("cls");
                int login_choice;
                top_nav();
                login_temp();
                caption();
                cin >> login_choice;
                switch (login_choice){

                //Sales Login!!
                case 1:
                {
                    system("cls");
                    top_nav();
                    cout << "\n\t\t\t\t\t---------------: WELCOME :--------------";
                    cout << "\n\t\t\t\t\t-------------: SALES PANEL :------------\n\n\n";
                    cout << "\n\t\t\t\t\t      Username :";
                    cin >> sales_un;
                    cout << "\n\t\t\t\t\t      Password :";
                    cin >> sales_pw;

                    o1.login(sales_un, sales_pw);

                    if (sales_login_states == false){
                        Sleep(2000);
                        goto login_main;
                    }
                    else{
                        cout << "\t\t\t\t\t        Login Successful\n\n\n\n\n\n\n\n";
                        caption();
                        Sleep(2000);
                        bool logout = 0;
                        do{
                            bill_panel:
                            system("cls");
                            int pressed;
                            
                            top_nav();
                            cout << "\n\t\t\t\t\t---------------: WELCOME :--------------";
                            cout << "\n\t\t\t\t\t-----------:   SALES PANEL   :----------\n\n\n";
                            cout << "\n\t\t\t\t\t             (1) to Make a Bill ";
                            cout << "\n\t\t\t\t\t       (0) to Logout From Sales Panel   \n\n\n\n";
                            caption();
                            cin>>pressed;
                            switch (pressed)
                            {
                                case 1:
                                {   
                                    int x_leb;
                                    do
                                    {
                                        x_leb_panel_X:
                                        system("cls");
                                        top_nav();
                                        C1.C_top_nav();
                                        C1.cart_view();
                                        C1.C_caption();
                                        cout << "\n\n\n\t\t\t\t\t(1) Add Item to Cart";
                                        cout <<       "\n\t\t\t\t\t(2) Place Order\n\n\n";
                                        caption();
                                        cin>>x_leb;
                                        if(x_leb == 1)
                                        {
                                            string id;
                                            cout<<"\t\t\t\t Enter the product Id    : ";
                                            cin >> id;
                                            int quantity;
                                            cout<<"\t\t\t\t Enter product Quantity  : ";
                                            cin >> quantity;
                                            C1.add_to_cart(id,quantity);
                                            cout<<"\t\t\t\t Press enter to continue -> !";
                                            getch();
                                            goto x_leb_panel_X;
                                        }
                                        if(x_leb == 2)
                                        {
                                            C1.record_cart();
                                            C1.clean_cart_data();
                                            goto bill_panel;
                                        }
                                        
                                        
                                    } while (x_leb!=2);
                                    
                                    
                                }

                                case 0:
                                {
                                    logout = 1;
                                }
                            }

                            
                        
                        } while (logout!=1);
                        
                        sales_login_states = false;
                        goto login_main;
                    }
                }
                //Admin Login!!
                case 2:
                {
                    system("cls");
                    string admin_un;
                    string admin_pw;
                    top_nav();
                    cout << "\n\t\t\t\t\t---------------: WELCOME :--------------";
                    cout << "\n\t\t\t\t\t----------: TO NUB SUPER STORE :--------\n\n\n";
                    cout << "\n\t\t\t\t\t     Enter Admin username:";
                    cin >> admin_un;
                    cout << "\n\t\t\t\t\t     Enter Admin password:";
                    cin >> admin_pw;
                    o1.login(admin_un, admin_pw);

                    if (admin_login_states == false){
                        caption();
                        Sleep(2000);
                        break;
                    }
                    else{
                        cout << "\t\t\t\t\t         Login successful!\n";
                        caption();
                        Sleep(2000);
                        int a_choice;

                        //Admin Panel
                        do{
                        admin_panel:
                        system("cls");
                        top_nav();
                        admin_panel_temp();
                        caption();
                        cin >> a_choice;
                        switch (a_choice){

                        //Inventory Main panel
                        case 1:
                        {
                            Inventory_panel:
                            system("cls");
                            int admin_choice_case_1;
                            top_nav();
                            inventory_management_panel_temp();
                            caption();
                            cin >> admin_choice_case_1;
                            switch(admin_choice_case_1){

                                //Search From Inventory
                                case 1:
                                {
                                    system("cls");
                                    string itemNameToSearch;
                                    top_nav();
                                    P1.stock_view();
                                    cout<<"\n\t\t\t\t\t Enter the name you want to Search!!\n\n\n";
                                    caption();
                                    cin>>itemNameToSearch;
                                    system("cls");
                                    top_nav();
                                    P1.searchByName(itemNameToSearch);
                                    caption();
                                    Sleep(2000);
                                    getch();
                                    goto Inventory_panel;
                                }

                                //Full Inventory View
                                case 2:
                                {
                                    system("cls");
                                    top_nav();
                                    P1.stock_view();
                                    caption();
                                    getch();
                                    goto Inventory_panel;
                                }

                                //Add Goods To Inventory
                                case 3:
                                {
                                    string id, name, category;
                                    double price;
                                    int quantity;
                                    system("cls");
                                    top_nav();
                                    cout<<"\n\n\n\n\n\t\t\t\t\t\tEnter Product ID        : ";
                                    cin>>id;
                                    cout<<"\t\t\t\t\t\tEnter Product Name      : ";
                                    cin.ignore();
                                    getline(cin, name);
                                    cout<<"\t\t\t\t\t\tEnter Product Category  : ";
                                    cin>>category;
                                    cout<<"\t\t\t\t\t\tEnter Product Price     : ";
                                    cin>>price;
                                    cout<<"\t\t\t\t\t\tEnter Product Quantity  : ";
                                    cin>>quantity;
                                    P1.addProductToInventory(id,name,category,price,quantity);
                                    caption();
                                    getch();
                                    goto Inventory_panel;
                                }

                                //Remove Goods form Inventory
                                case 4:
                                {
                                    system("cls");
                                    string id;
                                    int quantity;
                                    top_nav();
                                    cout<<"\n\n\n\n\n\n\t\t\t\t\tWhich Item you want to Remove!!\n";
                                    P1.stock_view();
                                    caption();
                                    cout<<"\n\n\t\t\t\t\tEnter data to remove Element\n Enter Product Id   :";
                                    cin>>id;
                                    cout<<"\nEnter the Quantity :";
                                    cin>>quantity;
                                    P1.removeGoodsFromInventory(id, quantity);
                                    goto Inventory_panel;
                                }

                                case 5:
                                {
                                    system("cls");
                                    goto admin_panel;
                                }
                            }

                        }//Inventory Main end!!

                        //SALES MANAGEMENT PANEL
                        case 2:
                        {
                            sales_panel:
                            system("cls");
                            int admin_choice_case_2;
                            top_nav();
                            cout << "\n\t\t\t\t\t-------: Sales Management Panel :-------\n\n\n";
                            cout << "\t\t\t\t\t\t   1. All Sale Invoices\n";
                            cout << "\t\t\t\t\t\t   2. Back To Admin Panel\n";
                            caption();
                            cin >> admin_choice_case_2;
                            switch (admin_choice_case_2)
                            {
                            case 1:
                            {
                                system("cls");
                                top_nav();
                                C1.sales_record_view();
                                getch();
                                goto sales_panel;
                            }

                            case 2:
                            {
                                goto admin_panel;
                            }                             

                            }

                        }//Sales-end
                        
                        //STAFF MANAGEMENT PANEL
                        case 3:
                        {
                            staff_management_panel:
                            system("cls");
                            int admin_choice_case_3;
                            top_nav();
                            staff_management_panel_temp();
                            caption();
                            cin >> admin_choice_case_3;
                            switch (admin_choice_case_3)
                            {
                            //Staff Information Panel
                            case 1:
                            {
                                staff_information_panel:
                                system("cls");
                                int sip_choice;
                                top_nav();
                                staff_information_panel_temp();
                                caption();
                                cin>>sip_choice;

                                switch (sip_choice)
                                {
                                //Full Staff List
                                case 1:
                                {
                                    system("cls");
                                    top_nav();
                                    E1.view_database();
                                    caption();
                                    getch();
                                    goto staff_information_panel;
                                }
                                //Search By ID
                                case 2:
                                {
                                    system("cls");
                                    string id;
                                    top_nav();
                                    cout<<"\n\n\n\n\t\t\t\t\t Enter the ID of Employee :";
                                    cin>>id;
                                    E1.search_by_id(id);
                                    caption();
                                    getch();
                                    goto staff_information_panel;
                                }
                                //Search By Name
                                case 3:
                                {
                                    system("cls");
                                    string name;
                                    top_nav();
                                    cout<<"\n\n\n\n\t\t\t\t\t Enter the Name of Employee :";
                                    cin>>name;
                                    E1.search_by_name(name);
                                    caption();
                                    getch();
                                    goto staff_information_panel;
                                }
                                //Search By Position
                                case 4:
                                {
                                    system("cls");
                                    string position;
                                    top_nav();
                                    cout<<"\n\n\n\n\t\t\t\t\t Enter the Position of Employee :";
                                    cin>>position;
                                    E1.search_by_id(position);
                                    caption();
                                    getch();
                                    goto staff_information_panel;
                                }
                                //Back To Staff Management Panel
                                case 5:
                                {
                                    goto staff_management_panel;
                                }                                
                                default:
                                {
                                    top_nav();
                                    cout<<"\n\n\n\n\t\t\t\t\t\tWrong input!!\n\n\n\n\n";
                                    caption();
                                    Sleep(1200);
                                    goto staff_information_panel;
                                }
                                }
                                break;
                            }
                            //Add Stuff
                            case 2:
                            {
                                system("cls");
                                top_nav();
                                cout<<"\n\n\n\t\t\t\t\t\tInput the following Data carefully!!\n\n";
                                string id,name,m_no,p_add,nid,poss,acc;
                                cout<<"\t\t\t\t\tEnter Employee ID                  : ";
                                cin>>id;
                                cout<<"\t\t\t\t\tEnter Employee Name                : ";
                                cin.ignore();
                                getline(cin, name);
                                cout<<"\t\t\t\t\tEnter Employee Mobile Number       : ";
                                cin>>m_no;
                                cout<<"\t\t\t\t\tEnter Employee Permanent Address   : ";
                                cin.ignore();
                                getline(cin, p_add);
                                cout<<"\t\t\t\t\tEnter Employee NID Number          : ";
                                cin>>nid;
                                cout<<"\t\t\t\t\tEnter Employee Position            : ";
                                cin.ignore();
                                getline(cin, poss);
                                cout<<"\t\t\t\t\tEnter Employee Bank Account Number : ";
                                cin>>acc;
                                Employee* Ex = new Employee(id,name,m_no,p_add,nid,poss,acc);
                                Ex->add_to_database();
                                cout<<"\n\n\n\n\t\t\t\t\tEmployee Information Saved!! ";
                                Sleep(2000);
                                caption();
                                goto staff_management_panel;

                            }
                            //Remove Stuff
                            case 3:
                            {
                                string id;
                                system("cls");
                                top_nav();
                                E1.view_database();
                                cout<<"\n\n\t\t\t\t\tEnter the ID of Employee to be Removed: ";             
                                cin>>id;
                                E1.remove_from_database(id);
                                caption();
                                Sleep(1000);
                                goto staff_management_panel;
                            }
                            //return to admin panel
                            case 4:
                            {
                                goto admin_panel;
                            }     
                            
                            default:
                            {
                                system("cls");
                                top_nav();
                                cout<<"\n\n\n\n\t\t\t\t\t\tWrong input!!\n\n\n\n\n";
                                caption();
                                Sleep(1200);
                                goto staff_management_panel;
                            }
                                
                            }
                        }

                        //MEMBERSHIP MANAGEMENT PANEL
                        case 4:
                        {
                            membership_management_panel:
                            system("cls");
                            int admin_choice_case_4;
                            top_nav();
                            membership_management_panel_temp();
                            caption();
                            cin >> admin_choice_case_4;
                            switch (admin_choice_case_4)
                            {
                                //Members Information List
                                case 1:
                                {
                                    system("cls");
                                    top_nav();
                                    M1.member_list_view();
                                    caption();
                                    getch();
                                    goto membership_management_panel;
                                }

                                //New Member
                                case 2:
                                {
                                    system("cls");
                                    string id, name, address, phone;
                                    int points = 0;
                                    top_nav();
                                    cout<<"\n\n\n\n\n\t\t\t\t\t\tEnter Member ID            : ";
                                    cin>>id;
                                    cout<<"\t\t\t\t\t\tEnter Member Name         : ";
                                    cin.ignore();
                                    getline(cin, name);
                                    cout<<"\t\t\t\t\t\tEnter Member address      : ";
                                    getline(cin,address);
                                    cout<<"\t\t\t\t\t\tEnter Member Phone Number : ";
                                    cin>>phone;
                                    M1.addNewMember(id, name, address, phone, points);
                                    caption();
                                    Sleep(1000);
                                    goto membership_management_panel;
                                }

                                //Back To Admin Panel
                                case 3:
                                {
                                    goto admin_panel;
                                }
                                
                                default:
                                {
                                    system("cls");
                                    top_nav();
                                    cout<<"\n\n\n\n\t\t\t\t\t\tWrong input!!\n\n\n\n\n";
                                    caption();
                                    Sleep(1200);
                                    goto membership_management_panel;
                                }
                            }
                            
                        }
                        
                        case 5:
                        {
                            system("cls");
                            admin_login_states = false;
                            goto open_bar;
                        }
                        default:
                        {
                            system("cls");
                            top_nav();
                            cout << "\n\n\n\n\t\t\t\t\tWrong Input!!\n\n\n\n\n";
                            caption();
                            Sleep(2000);
                            goto admin_panel;
                        }
                        }

                    } while (a_choice != 5);
                    admin_login_states = false;
                }

                }
                //return to open
                case 3:
                {
                    goto open_bar;
                }
                default:
                {
                    system("cls");
                    top_nav();
                    cout << "\n\n\n\n\t\t\t\t\tInvalid Input! Please select a valid option.\n\n\n\n\n";
                    caption();
                    Sleep(2000);
                    goto login_main;
                }

                }//End of Login
            }
            case 3:
            {
                    return 0;
            }
            default:
            {
                system("cls");
                top_nav();
                cout << "\n\n\n\n\t\t\t\t\tInvalid Input! Please select a valid option.\n\n\n\n\n";
                caption();
                Sleep(2000);
                goto open_bar;
            }
            
           

        }

    } while (choice != 3);
    //end of op
}
