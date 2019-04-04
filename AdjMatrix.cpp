/***************\
| AdjMatrix.cpp |
\***************/

/** TODO: függvénypointerekkel(??) megoldani a mátrix memory allocation + adatmásolást ***/

#include "AdjMatrix.h"
#include<iostream>

using namespace std;


AdjMatrix::AdjMatrix(int n_ = 0): n(n_) {

    /* Allocating space for 2D array */
    data = new int*[n_];
    for(int i = 0; i < n_; ++i)
        data[i] = new int[n_];

    /* Filling out the 2D array with 0s */
    for(int i = 0; i < n_; ++i) {
        for(int j = 0; j < n_; ++j) {
            data[i][j] = 0;
        }
    }
}

AdjMatrix::~AdjMatrix() {

    /* Freeing up the dynamically allocated memory */
    for(int i=0; i<n; ++i)
        delete[] data[i];
    delete[] data;
}

/* Adding a column and a row to a matrix */
void AdjMatrix::addColAndRow() {

    ++n; /* Changing the dimension indicator */

    int** newarray;
    /* Allocating memory for the new array */
    allocate(newarray);

    /* Copying data from the old array to the new one */
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(j<n-1 && i<n-1)
                newarray[i][j] = data[i][j];
            else
                newarray[i][j] = 0;
            }
    }

    /* Deleting the old array */
    for(int i=0; i<n-1; ++i)
        delete[] this->data[i];
    delete[] this->data;

    /* Change the data pointer to point to the new array */
    data = newarray;

}//END_OF_FUNCTION: addColAndRow()

/* Deletes a given row and column (square matrices) */
void AdjMatrix::delColAndRow(int id) {

    --n;
    int** smaller;
    allocate(smaller);

    /* Copying to the new array */
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(i<id) {
                if(j<id)
                    smaller[i][j] = data[i][j];
                else
                    smaller[i][j] = data[i][j+1];
            } else {
                if(j<id)
                    smaller[i][j] = data[i+1][j];
                else
                    smaller[i][j] = data[i+1][j+1];
            }
        }
    }

    /* Deleting the old array */
    for(int i=0; i<n+1; ++i)
        delete[] this->data[i];
    delete[] this->data;

    /* Change the data pointer to point to the new array */
    data = smaller;

}//END_OF_FUNCTION: addColAndRow(...)

bool AdjMatrix::isEqual(AdjMatrix& other) const {

    if(this->n == other.n) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(this->data[i][j] != other.data[i][j])
                    return false;
            }
        }
    } else return false;
    return true;
}//END_OF_FUNCTION:isEqual(...)

void AdjMatrix::equalTo(AdjMatrix& other) {

    if(this->n == other.n) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                this->data[i][j] = other.data[i][j];
            }
        }
    } else if(this->isNullMatrix()) {

         /* If you call the this function to a null matrix, then stretch
         * the null matrix to match the dimensions of the other matrix
         * and then do the copying.
         */
         AdjMatrix* newM = new AdjMatrix(other.n); /* Creating a new pointer to a matrix object */
         /* Copy the values */
         for(int i=0; i<other.n; ++i) {
            for(int j=0; j<other.n; ++j) {
                    newM->data[i][j] = other.data[i][j];
            }
         }
         /* Delete the initial null matrix */
         for(int i=0; i<this->n; ++i)
            delete[] this->data[i];
         delete[] this->data;
         /* Change the pointer */
         this->data = newM->data;
         this->n = newM->n;

    } else cout<< "\nERROR: two different size matrices (graphs) passed to AdjMatrix::equalTo(...) function through Graph::operator=(...)!" <<endl;

}//END_OF_FUNCTION:equalTo(...)

/************** HELPER FUNCTIONS *****************/

/* Memory allocator */
void AdjMatrix::allocate(int** &ptr) {

    ptr = new int*[n];
    for(int i = 0; i < n; ++i)
        ptr[i] = new int[n];
}//END_OF_FUNCTION: allocate(...)

/* Is null matrix? */
bool AdjMatrix::isNullMatrix() const {

    for(int i=0; i<this->n; ++i) {
        for(int j=0; j<this->n; ++j) {
            if(this->data[i][j] != 0)
                return false;
        }
    }
    return true;
}
