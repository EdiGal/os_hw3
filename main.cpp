#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

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
    /*Food(Food& dish){
        this->id = dish.getId();
        this->name = dish.getName();
        this->price = dish.getPrice();
        this->totalOredered = dish.getTotalOrdered();
    }*/
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
    void printDish(){
        cout << "#" << this->getId() << " " << this->getName() << " - " << this->getPrice() << endl;
    }
    void makeOrder(){
        this->totalOredered++;
    }
};

class Menu {
    vector<Food> dishes;
public:
    Menu(){
        this->fillMenu(3);
    }
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
            this->dishes[i].printDish();
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

    Food & getDishById(int id){
        bool found = false;
        for(int i = 0 ; i < dishes.size() ; i++){
            if(this->dishes[i].getId() == id){
                return dishes[i];
            }

        }
    }
};

class Order {
    Food dish;
    int amount;
    bool done;
public:
    Order(Food dish, int amount):dish(dish) {
        this->amount = amount;
        this->done = false;
    }

};

class Customer{
    Order *order;
    int customerId;
public:
};

void makeOrder(Customer customer, Menu menu){
    int choosenDishId = menu.getCustomerChoice();
    Food choosenDish = menu.getDishById(choosenDishId);
    cout << "how much " << choosenDish.getName() << " you want to order?"<<endl;
    int amount;
    cin >> amount;
    amount = amount > 4 ? 4 : amount < 1 ? 1 : amount;
//    customer->order = new Order(choosenDish, amount);
}

void mainProcess(){
    Menu menu;

}

int main() {
    pid_t pid = fork();
    if(pid == 0){
        cout << "im the parent with process " << pid << endl;
        cout << "im the parent, waiting fiir a child to end" << endl;
        wait(NULL);
        cout<<"end"<<endl;
    }
    else if(pid > 0){
        cout << "im the child with process " << pid << endl;
        //child process for "Main process" (the manager)
        mainProcess();
    }
    return 0;
}



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

/*
void f1(LogFile& log){
    for(int i = 0 ; i < 200 ; i++){
        log.shated_print("Hello from f1 ", i);
    }
}
*/