#include<iostream>
using namespace std;

// Encapsulation: Tinh dong goi - Class phai duoc an giau tat ca du lieu (variable cannot access from outside)
// Abstraction: Tinh truu tuong - Only using methods are provided by owner (in public)
// Inheritance: Tinh ke thua - Class can be get same information(method, object) from another class
// + Destructor and constructor function cannot be inheritated.
// Polymorphism: Tinh da hinh - Same method but different result
class Student {
public: // can access from outside class
    // Constructor Function: Ham khoi tao
    Student(const string &Name, bool Alone = true, int Age = 18, int Ma = 0) 
        :name(Name), alone(Alone), age(Age), mathPoint(Ma) {} 
    
    // Destructor Function: Ham huy
    // Bien tinh(static variable) se tu dong chay ham huy truoc khi ket thuc chuong trinh
    ~Student() {
        cout << "Ban: " << name << " from TwinHter University" << '\n';
    } 

    void EnterPoint(int numMath) {
        mathPoint = numMath;
    }
    void PrintResult() {
        cout << "Math Point is: " << mathPoint << '\n';
        if(mathPoint >= 5) {
            cout << "Pass\n";
        }
        else {
            cout << "Fail\n"; 
        }
    }
    void HaveCrush() {
        if(alone == false) cout << "Already have GF\n";
        else alone = true;
    }
    void BreakUp() {
        if(alone == false) alone = true;
        else cout << "Have no GF :<\n";
    }
    virtual void Salary() {
        cout << "1 million euro\n";
    }

protected: // only access from class
    string name;
    bool alone; // co nguoi yeu?
    int age;
    int mathPoint;
};

// Inheritance
class GoodStudent : public Student {
public:    
    GoodStudent(const string &Name, bool Alone = true, int Age = 18, int Ma = 0) 
        :Student(Name, Alone, Age, Ma) {} 
    ~GoodStudent() {
        cout << "Ban: " << name << " from TwinHter University" << '\n';
    }

    void Scholarship() {
        if(mathPoint >= 9 && age >= 18) {
            cout << "Have Scholarship\n";
        }
        else {
            cout << "Fail to qualify\n";
        }
    }

    //Polymorphysm
    void Salary() {
        cout << "100 million VND\n";
    }
};

class BadStudent : public Student {

};

// Multi Inheritance (Diamond Inheritance) -> Avoid
class NormalStudent: public GoodStudent, public BadStudent {

};
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Student *Nguyen = new Student("Dang Nguyen", true, 18, 9);
    Student *Trong = new GoodStudent("Duc Trong", true, 18, 8);
    delete Nguyen;
    delete Trong;
}