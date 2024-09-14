//
// Created by stg05 on 14.09.2024.
//

#include <iostream>
#include <string>

class Student{
public:
    Student(): Student{"Dima", 0, 312};

    Student(const std::string& name,
            unsigned re_exam,
            unsigned group):
    m_name{name},
    m_re_exam{re_exam},
    m_group_number{group}
    {

    }
    void set_name(const std::string& name){
        m_name = name;
    }

private:
    std::string m_name;     //codestyle -- [m_...] = [member's_...]
    unsigned m_re_exam;
    unsigned m_group_number;
};

int main(){
    Student s{"Dimka", 0, 312};
    Student ss = Student{"Dimka", 0, 312};
    return 0;
}