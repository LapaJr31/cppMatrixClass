#include <iostream>


class Matrix{
    private:
        int rows, cols;
        double *vals;

    public:
        Matrix(int r, int c){
            rows = r;
            cols = c;
            vals = new double[r*c] ;
        }

        ~Matrix(){
            delete[] vals;
        }

        double& operator()(int r, int c){
            int i = r * cols + c;
            return vals[i];
        }
        
};


int main(){

    Matrix m(4,5);
    m(1,2) = 5;
    std::cout << "value: " << m(1,2) << "\n";

    return 0;
}