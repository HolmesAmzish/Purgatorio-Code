#include <iostream>
#include <fstream>

using namespace std;

struct employee {
    int no;
    string name;
    string depno;
    int salary;
    employee* next;
};

class EmployeeList {
private:
    employee head;
public:
    //构造函数初始化头节点
    EmployeeList() {
        head = new employee();
        head->next = nullptr;
    }

    //加载数据
    bool LoadData(const string& filename) {
        ifstream file(filename); //打开文件
        if (!file.is_open()) {
            cout << "Failed to open file." << endl;
            return false;
        }
        //读取内容
        while (!file.eof()) {
            employee* newEmployee = new employee();
            file >> newEmployee->Node
        }
    }
};

int main() {

}