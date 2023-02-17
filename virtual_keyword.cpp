// ======================================
// INTRO
// VIRTUAL KEYWORD CAN BE USED TO GET A FEEL OF RUN TIME POLYMORPHISM, LATE BINDING, DYNAMIC BINDINC
// ======================================
// HOW TO COMPILE?
// to compile in mobaxterm ==>gcc -g virtual_keyword.cpp -o virtual_keyword -lstdc++
// to run in mobaxterm ===> ./virtual_keyword
// ======================================
// OUTPUT
// parent_show
// parent_view
// parent_show
// child_view
// ======================================
#include<iostream>

class parent{
    public:
    void show(){
        std::cout<<"parent_show"<<std::endl;
    }
    virtual void view(){
        std::cout<<"parent_view"<<std::endl;
    }
};

class child: public parent{
    void show(){
        std::cout<<"child_show"<<std::endl;
    }
     void view(){
        std::cout<<"child_view"<<std::endl;
    }
};

int main(){
    parent* p;
    parent q;
    child* c;
    child c1;
    p=&q;

    p->show();
    p->view();
    p=&c1;
    p->show();
    p->view();
    return 0;
}
