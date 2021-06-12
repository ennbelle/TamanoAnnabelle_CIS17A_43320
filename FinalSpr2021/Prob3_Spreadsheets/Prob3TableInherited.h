/* 
 * File:   Prob3TableInherited.h
 * Author: Annabelle Tamano
 * Created on June 11, 2021, 1:57 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H
#include "Prob3Table.h"

template<class T>
class Prob3TableInherited : public Prob3Table<T> {
protected:
    T *augTable; //Augmented Table with sums
public:
    Prob3TableInherited(char *,int,int);          //Constructor
    ~Prob3TableInherited() {
        delete [] augTable;
    }; //Destructor

    const T *getAugTable(void) {
        return augTable;
    };
};

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char t[], int r, int c):Prob3Table<T>(t,r,c) {
        augTable=new T[(r+1)*(c+1)];
        
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                augTable[(i*(c+1))+j]=this->table[(i*c)+j];
            }
        }
        
        for(int i=0;i<r;i++) {
            augTable[i*(c+1)+c]=this->rowSum[i];
        }
        for(int j=0;j<c;j++) {
            augTable[((r+1)*c)+j-1]=this->colSum[j];
        }
    
        augTable[(r+1)*(c+1)-1]=this->grandTotal;
    };

#endif /* PROB3TABLEINHERITED_H */

