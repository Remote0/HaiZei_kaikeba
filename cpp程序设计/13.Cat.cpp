/*************************************************************************
	> File Name: 13.Cat.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 06 Mar 2021 07:04:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal{
public:
    Animal(string name = "mimi") : name(name) {
        cout << "Animal default constructor" << endl;
    }
    Animal(const Animal &a) : name(a.name) {
        cout << "Animal default constructor" << endl;
    } 
    void say() {
        cout << "my name is " << name << endl;
    }
    void rename(string name) {
        this->name = name;
        return ;
    }
    ~Animal() {
        cout << "Animal deconstructor" << endl;
    }
protected:
    string name;
};

class Cat : public Animal {
public:
    Cat() : Animal("Cat MIMI") {
        cout << "Cat default constructor" << endl;
    }
    Cat(const Cat &c) : Animal(c) {
        cout << "Cat copy constructor" << endl;
    }
    void say1() {
        cout << "miaomiaomiao, my name is " << name << endl;
    }
    ~Cat() {
        cout << "Cat deconstructor" << endl;
    }

};
/*
class Tigger : public Cat {
public:
    void say2() {
        cout << "houhouhou, my name is " << name << endl;
    }
};
*/

class A {
public:
    A() : x(123) {}
    int x;
};

class B : public A {
public:
    void setX(int x) { 
        cout << "set X, &X = " << &(this->x) << endl;
        this->x = x; 
        return ; 
    }
};

class C : public A {
public:
    int getX() { 
        cout << "get X, &x = " << &(this->x) << endl;
        return x; }
};

class D : public B, public C {

};

class Father {
public:
    Father(const Father &f) = default;
};

class Son : private Father {
public:
    Son(const Son &a) : Father(a) {}
};

int main() {
    cout << sizeof(Animal) << " " << sizeof(Cat) << endl;
    Cat c;
    Cat a = c;
    a.say1();
    c.say1();

    Animal *p = &c; //公有继承时，可以将子类地址转换成父类指针，但私有继承和保护不行,因为有可能转换后可以访问到继承自父类的属性和方法
    p->say();

    D d;
    cout << "get X : " << d.getX() << endl;
    d.setX(12345);
    cout << "get X : " << d.getX() << endl;
    return 0;
}
