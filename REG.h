//
// Created by Daniil Kolesnik on 08/08/2021.
//

#ifndef BAZA_AUG_REG_H
#define BAZA_AUG_REG_H
#include "Abst.h"
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



class REG: public Abst {
public:



//    std::string name;//название факультета
//    std::string nuk;//НУК
//    int n_kaf; // кол-во кафедр
//
//    std::vector <Subject> set_of_disciplines;

    REG(){};

    void print(std::ofstream &str){

        str << type << std::endl;
        str << GetName() << std::endl;
        str << GetnKaf() << std::endl;
        str << GetNuk() << std::endl;
        str << "----------------------------" << std::endl;
        for (auto &item: set_of_disciplines){
            str << item.name << " " << item.n_personnel << std::endl;
        }
        str << "----------------------------" << std::endl;
    }

    void scan(std::ifstream &str){
        std::string holder;
        std::getline(str,holder);
        name = holder;
        std::getline(str, holder);
        nuk = holder;
        std::getline(str, holder);
        n_kaf = std::stoi( holder );
        std::getline(str, holder);
        std::getline(str, holder);
        while (holder != "----------------------------"){
//            std::string str = "Hello 1234";
            std::stringstream ss{holder}; // создаем поток ss из строки str
            std::string name, number;
            ss >> name;
            ss >> number;
            int temp = 0;
            temp = std::stoi(number);
            set_of_disciplines.push_back({name, temp});
            std::getline(str, holder);
        }



    }


};


#endif //BAZA_AUG_REG_H
