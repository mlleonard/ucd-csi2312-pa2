//
// Created by Madeline Leonard on 11/13/15.
//

#ifndef PA4_INTERMEDIATE_EXCEPTION_H
#define PA4_INTERMEDIATE_EXCEPTION_H

#include <iostream>

namespace Clustering {
    class DimensionalityMismatchEx {

    private:
        std::string m_name;
        int m_dim1;
        int m_dim2;

        DimensionalityMismatchEx() {};

    public:
        DimensionalityMismatchEx(std::string name, int dim1, int dim2): m_name(name), m_dim1(dim1), m_dim2(dim2) {}
        std::string getName() {return m_name;}
        int getDim1() { return m_dim1; }
        int getDim2() { return m_dim2; }

        friend std::ostream &operator<<(std::ostream &os, DimensionalityMismatchEx &DimMisEx);

    };

    class OutOfBoundsEx {

    private:
        std::string m_name;
        int m_index;

        OutOfBoundsEx() {};

    public:
        OutOfBoundsEx(std::string name, int index): m_name(name), m_index(index) {}

        std::string getName() {return m_name;}
        int getIndex() { return  m_index;}

        friend std::ostream &operator<<(std::ostream& os, OutOfBoundsEx &OOBEx);
    };

    class RemoveFromEmptyEx{

    private:
        std::string m_name;
        int m_id;

        RemoveFromEmptyEx() {};


    public:
        RemoveFromEmptyEx(std::string name, int id): m_name(name), m_id(id) {}
        std::string getName() { return m_name;}
        int getId() { return m_id;}

        friend std::ostream &operator<<(std::ostream& os, RemoveFromEmptyEx &RemoveEmpt);
    };
};




#endif //PA4_INTERMEDIATE_EXCEPTION_H