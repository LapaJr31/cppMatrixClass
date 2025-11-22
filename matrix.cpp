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

        Matrix operator+(Matrix& secMatrix){
            Matrix result(rows,cols);

            if ( rows != secMatrix.rows || cols != secMatrix.cols) {
                std::cout << "Matrices have different dimensions";    
            } else {
                for (int i = 0 ; i < rows*cols; i++) {
                    result.vals[i] = vals[i] + secMatrix.vals[i];
                }
            }
        return result;
        }

        Matrix operator-(Matrix& secMatrix){
            Matrix result(rows,cols);

            if ( rows != secMatrix.rows || cols != secMatrix.cols) {
                std::cout << "Matrices have different dimensions";    
            } else {
                for (int i = 0 ; i < rows*cols; i++) {
                    result.vals[i] = vals[i] - secMatrix.vals[i];
                }
            }
        return result;
        }
        
};


int main(){

    int dim = 2;

    Matrix m(dim,dim);
    Matrix n(dim,dim);
    Matrix l(3,3);

    m(0,0) = 5.5;
    m(0,1) = 1.0;
    m(1,0) = 5.1;
    m(1,1) = 5.1;

    n(0,0) = 6.1;
    n(0,1) = 9.4;
    n(1,0) = 2.0;
    n(1,1) = 8.7;

    Matrix sum = m+n;
    Matrix dif = m-n;

    std::cout << "Sum:\n";
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++){
            std::cout << sum(r, c) << "\n";
        }
    }

    std::cout << "Dif:\n";
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++){
            std::cout << dif(r, c) << "\n";
        }
    }
    return 0;
}