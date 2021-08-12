//
// Created by Daniil Kolesnik on 11/08/2021.
//

#ifndef BAZA_AUG_SUBJECT_H
#define BAZA_AUG_SUBJECT_H

class Subject{



public:
    std::string name;
    int n_personnel;
    Subject (std::string _name,int number) : name(_name) , n_personnel(number){}
};

#endif //BAZA_AUG_SUBJECT_H
