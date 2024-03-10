#include <iostream>
using namespace std;

class OrderedSequentialList {
private:
    int size;
    int capacity;
    int* data;

public:
    // 构造函数
    OrderedSequentialList(int cap = 10) : size(0), capacity(cap) {
        data = new int[cap];
    }

    ~OrderedSequentialList() {
        delete[] data;
    }

    // 插入元素
    void insert(int e) {
        if (size >= capacity) {
            cout << "Error: List is full!" << endl;
            return;
        }
        int i = size - 1;
        while (i >= 0 && data[i] > e) {
            data[i + 1] = data[i];
            --i;
        }
        data[i + 1] = e;
        ++size;
    }

    // 删除值为e的所有元素
    void remove(int e) {
        int i = 0, j = 0;
        while (i < size) {
            if (data[i] != e) {
                data[j++] = data[i];
            }
            ++i;
        }
        size = j;
        if (j == size) {
            cout << "Error: Value not found in the list!" << endl;
        }
    }

    // 合并两个有序顺序表
    OrderedSequentialList merge(OrderedSequentialList& other) {
        OrderedSequentialList merged(size + other.size);
        int i = 0, j = 0, k = 0;
        while (i < size && j < other.size) {
            if (data[i] <= other.data[j]) {
                merged.data[k++] = data[i++];
            } else {
                merged.data[k++] = other.data[j++];
            }
        }
        while (i < size) {
            merged.data[k++] = data[i++];
        }
        while (j < other.size) {
            merged.data[k++] = other.data[j++];
        }
        merged.size = k;
        return merged;
    }

    // 删除指定范围的元素
    void removeRange(int s, int t) {
        if (s >= t || size == 0) {
            cout << "Error: Invalid range or empty list!" << endl;
            return;
        }
        int i = 0, j = 0;
        while (i < size && data[i] < s) {
            data[j++] = data[i++];
        }
        while (i < size && data[i] < t) {
            ++i;
        }
        while (i < size) {
            data[j++] = data[i++];
        }
        size = j;
    }

    // 输出有序顺序表
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // 测试用例主函数
    static void test() {
        OrderedSequentialList list1;
        int num;
        cout << "Enter numbers (-1 to end): ";
        while (cin >> num && num != -1) {
            list1.insert(num);
        }

        list1.display();

        cout << "Enter value to remove: ";
        cin >> num;
        list1.remove(num);
        list1.display();

        OrderedSequentialList list2;
        cout << "Enter numbers for second list (-1 to end): ";
        while (cin >> num && num != -1) {
            list2.insert(num);
        }

        OrderedSequentialList mergedList = list1.merge(list2);
        cout << "Merged list: ";
        mergedList.display();

        cout << "Enter range to remove (s t): ";
        cin >> s >> t;
        mergedList.removeRange(s, t);
        cout << "List after removing range: ";
        mergedList.display();
    }
};

int main() {
    OrderedSequentialList::test();
    return 0;
}