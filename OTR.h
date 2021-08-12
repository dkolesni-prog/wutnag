//
// Created by Daniil Kolesnik on 08/08/2021.
//

#ifndef BAZA_AUG_OTR_H
#define BAZA_AUG_OTR_H
#include <string>
#include <map>
#include "Abst.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>

//Для отраслевого факультета также присутствует список названий дисциплин с кол-вом преподавателей,
//        сгруппированных по базовым организациям.

struct ORG{
public:
    ORG(){
        org_name = "NULL";
    }
    ORG(std::string arg) : org_name(arg){};
    std::string org_name;
};

class OTR :public Abst{
    std::map <Subject,ORG> set_of_subjects_by_org;
public:
    OTR(){};
//    bool type = 1;
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


    for (const auto& item : set_of_subjects_by_org) {
        str << item.first.name << " " << item.first.n_personnel << " " << item.second.org_name << std::endl;
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
        std::string name, number, org_name;
        ss >> name;
        ss >> number;
        ss >> org_name;
        int temp = 0;
        temp = std::stoi(number);
       // set_of_disciplines.push_back({name, temp});
       set_of_subjects_by_org[{name, n_kaf}] = ORG(org_name);

        std::getline(str, holder);



    }



}


};


#endif //BAZA_AUG_OTR_H