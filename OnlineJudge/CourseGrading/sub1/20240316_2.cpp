#include <iostream>
using namespace std;

struct PolyNode {
    int coefficient;
    int exponent;
    PolyNode* next;

    // 构造函数
    PolyNode(int coeff, int expo) {
        coefficient = coeff;
        exponent = expo;
        next = nullptr;
    }
};

class Polynomial {
private:
    PolyNode* head;

public:
    Polynomial() : head(nullptr) {}

    void Insert(int coeff, int expo) {
        PolyNode* newNode = new PolyNode(coeff, expo);
        if (head == nullptr) {
            head = newNode;
        } else {
            PolyNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void Print() {
        PolyNode* temp = head;
        while (temp != nullptr) {
            cout << temp->coefficient << ' ' << temp->exponent << ' ';
            temp = temp->next;
        }
        cout << endl;
    }

    Polynomial Add(Polynomial& another) {
        Polynomial result;
        PolyNode* poly_1 = head;
        PolyNode* poly_2 = another.head;

        // 判断指数，不相等时判断大小，小者直接插入。相等时相加再插入。
        while (poly_1 != nullptr && poly_2 != nullptr) {
            if (poly_1->exponent < poly_2->exponent) {
                result.Insert(poly_1->coefficient, poly_1->exponent);
                poly_1 = poly_1->next;
            } else if (poly_1->exponent > poly_2->exponent) {
                result.Insert(poly_2->coefficient, poly_2->exponent);
                poly_2 = poly_2->next;
            } else {
                int sumCoeff = poly_1->coefficient + poly_2->coefficient;
                result.Insert(sumCoeff, poly_1->exponent);
                poly_1 = poly_1->next; poly_2 = poly_2->next;
            }
        }

        if (poly_1 == nullptr) {
            while (poly_2 != nullptr) {
                result.Insert(poly_2->coefficient, poly_2->exponent);
                poly_2 = poly_2->next;
            }
        } else {
            while (poly_1 != nullptr) {
                result.Insert(poly_1->coefficient, poly_1->exponent);
                poly_1 = poly_1->next;
            }
        }
        return result;
    }
};

int main() {
    Polynomial poly[2];
    int coeff, expo;
    for (int i = 0; i < 2; i++) {
        while (cin >> coeff >> expo) {
            if (coeff == -100) break;
            poly[i].Insert(coeff, expo);
        }
    }
    Polynomial sum = poly[0].Add(poly[1]);
    sum.Print();
    return 0;
}