//
// Created by Daniil Kolesnik on 08/08/2021.
//

#ifndef BAZA_AUG_BD_H
#define BAZA_AUG_BD_H

#include <string>
#include <vector>
#include "REG.h"
#include "OTR.h"
#include <fstream>
#include <iostream>



class BD {
    std::string BD_name;
    std::vector <Abst*> some_fac;
//    std::vector <REG> REG_FAC_VEC; //вектор обычных факультетов
//    std::vector <OTR> OTR_FAC_VEC;// вектор отраслевых факультетов
public:

    BD(const std::string &name) : BD_name(name){} //insert
    void add (Abst* arg){
        some_fac.push_back(arg);
    }


    std::vector<std::string> GetFacultyName(){
        std::vector<std::string> fac_name;
        for (auto &item: some_fac) {
            fac_name.push_back(item->GetName() + " - обычный факултет");
        }
        for (auto &item: some_fac) {
            fac_name.push_back(item->GetName() + " - отраслевой факултет");
        }
        return fac_name;
    }

    static bool comparator_char( const Abst* arg1, const Abst* arg2){
        return (arg1->GetName() < arg2->GetName());
    }

    static bool comparator_int( const Abst* arg1, const Abst* arg2){
        return (arg1->GetnKaf() < arg2->GetnKaf());
    }

    void sort_by_aplhabet(){
        std::sort(some_fac.begin(),some_fac.end(), comparator_char);
    }

    void sort_by_n_kaf(){
        std::sort(some_fac.begin(),some_fac.end(), comparator_int);
    }



    void save (){
        std::ofstream out_s("FILE_NAME.txt",std::ios::out);
        for (auto item: some_fac) {
            item-> print(out_s);
        }
    }

    void scan (){
        std::string ind;
        std::string path = "/Users/daniilkolesnik/Desktop/FORHOMEWORK";//путь, где лежат БД

        std::ifstream indicator(path, std::ios::in);
        std::getline (indicator, ind);


            REG* reg = new REG();
            OTR* otr = new OTR();

            if (ind == "0") {
                reg->scan(indicator);
                add(reg);
            }
            else {
                otr->scan(indicator);
                add(otr);
            }


    }



};


#endif //BAZA_AUG_BD_H
