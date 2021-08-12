//
// Created by Daniil Kolesnik on 08/08/2021.
//

#ifndef BAZA_AUG_ABST_H
#define BAZA_AUG_ABST_H

#include <string>
#include <map>
#include "Subject.h"
#include <vector>


class Abst {  //current


//    Для каждого факультета указан список дисциплин,
//            сгруппированных по кафедрам, для каждой дисциплины – кол-во преподавателей, которые её ведут.

private:




protected:

    std::vector <Subject> set_of_disciplines;
    std::string name;//название факультета
    std::string nuk;//НУК
    int n_kaf; // кол-во кафедр


public:
    bool type;
    Abst(){}
    Abst(std::string _name, std::string _nuk, int _n_kaf, std::vector<Subject>& vec, bool _type):name(_name),
    nuk(_nuk),n_kaf(_n_kaf),set_of_disciplines(vec), type(_type) {}

    std::string GetName() const { //функции доступа
        return name;
    }
    std::string GetNuk() const {
        return nuk;
    }
    int GetnKaf() const {
        return n_kaf;
    }

    void SetName(std::string _name) {
        name = _name;
    }

    void SetNuk(std::string _nuk) {
        nuk = _nuk;
    }

    void SetNkaf(int _n_kaf) {
        n_kaf = _n_kaf;
    }

    virtual void print( std::ofstream &stream) = 0;
    virtual void scan(std::ifstream &str) = 0;
    virtual ~Abst(){}

};







#endif //BAZA_AUG_ABST_H
