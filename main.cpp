#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <vector>

using namespace std;
/*
class LogFile {
    mutex m_mutex;
    ofstream f;
public:
    LogFile() {
        f.open("log.txt");
    }
    void shated_print(string id, int value){
            lock_guard<mutex> locker(m_mutex);
        f << "From " << id << ": " << value << endl;
    }
    ofstream& getStream() {return f;}
    void processf(void fun(ofstream&)){
        fun(f);
    }
};
*/

class Food {
    int id;
    string name;
    int price;
    int totalOredered;
public:
    Food(int id, string name, int price){
        this->id = id;
        this->name = name;
        this->price = price;
        this->totalOredered = 0;
    }
    string getName(){
        return this->name;
    }
    int getId(){
        return this->id;
    }
    int getPrice(){
        return this->price;
    }
    int getTotalOrdered(){
        return this->totalOredered;
    }
    void printMenu(){
        cout << "#" << this->getId() << " " << this->getName() << " - " << this->getPrice();
    }
    void makeOrder(){
        this->totalOredered++;
    }
};

class Menu {
    vector<Food> dishes;
public:
    void fillMenu(int num){
        string name;
        int price;
        string priceStr;
        cout << "Create a manu" << endl;
        for(int i = 1 ; i <= num ; i++) {
            cout << "Name: ";
            cin >> name;
            cout << "Price: ";
            cin >> priceStr;
            price = stoi(priceStr);
            Food food(this->dishes.size(), name, price);
            this->dishes.push_back(food);
        }
    }

    void printMenu(){
        for(int i = 0 ; i < this->dishes.size(); i++){
            cout << "#" << this->dishes[i].getId() << ": " << this->dishes[i].getName() << " - " << this->dishes[i].getPrice() << " qILS" << endl;
        }
    }
    int size(){
        return this->dishes.size();
    }

    int getCustomerChoice(){
        cout << "Welcome to restourant!" << endl;
        cout << "Choose a dish by id:" << endl;
        this->printMenu();
        string a;
        cin >> a;
        int b = stoi(a);
        return b;
    }

    Food getDishById(int id){
        bool found = false;
        for(int i = 0 ; i < dishes.size() ; i++){
            if(this->dishes[i].getId() == id){

            }

        }
        cout << "dish not found."<<endl;
        return null
    }
};

/*
void f1(LogFile& log){
    for(int i = 0 ; i < 200 ; i++){
        log.shated_print("Hello from f1 ", i);
    }
}
*/
vector<Food> order;





int main() {
    Menu menu;
    menu.fillMenu(3);
    int choosenDishId = menu.getCustomerChoice();


    return 0;
}
