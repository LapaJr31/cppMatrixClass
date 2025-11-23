#include <iostream>
#include <stdexcept>

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

        int operator()(std::string input){
            if (input == "size"){
                return rows * cols;
            } else if(input == "cols") {
                return cols;
            } else if(input == "rows") {
                return rows;
            } else {
                throw std::runtime_error("Invalid input");
            }
        }

          // addition
        Matrix operator+(Matrix& secMatrix){
            Matrix result(rows,cols);
            if ( rows != secMatrix.rows || cols != secMatrix.cols) {
                throw std::runtime_error("Matrices have different dimensions");
            } else {
                for (int i = 0 ; i < rows*cols; i++) {
                    result.vals[i] = vals[i] + secMatrix.vals[i];
                }
            }
        return result;
        }

        // subtraction
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
        
        // scalar multiplication
        Matrix operator*(double num){
            for (int i = 0; i < rows*cols; i++){
                vals[i] *=  num;
            }
            return *this;
        }

        // in progress matrix on matrix
        Matrix operator*(Matrix& secMatrix){
            Matrix result(rows,secMatrix.cols);

            if (cols != secMatrix.rows){
                throw std::runtime_error("Cols don't match the rows of second Matrix");
            }
            for (int i = 0 ; i < result.rows; i++) {
                for (int j = 0 ; j < result.cols; j++) {
                    double sum = 0.0;
                    for(int k = 0; k < cols; k++){
                        sum += (*this)(i,k) * secMatrix(k,j) ;
                    }
                    result(i,j) = sum;
                }
            }
            return result;
        }
};

int main(){

    int dim = 2;

    Matrix m(dim, dim);
    Matrix n(dim,dim);

    m(0,0) = 1.2;
    m(0,1) = 8.5;
    m(1,0) = 0.2;
    m(1,1) = 4.8;

    n(0,0) = 9.1;
    n(0,1) = 6.0;
    n(1,0) = 4.2;
    n(1,1) = 7.7;

    Matrix sum = m+n;
    Matrix dif = m-n;
    Matrix mult = m*n;

    std::cout << "Sum:\n";
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++){
            std::cout << sum(r, c) << "\n";
        }
    }
    std::cout << "\n";

    std::cout << "Dif:\n";
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++){
            std::cout << dif(r, c) << "\n";
        }
    }
    std::cout << "\n";

    std::cout << "Multiplications:\n";
    for (int r = 0; r < mult("rows"); r++) {
        for (int c = 0; c < mult("cols"); c++){
            std::cout << mult(r, c) << "\n";
        }
    }
    std::cout << "\n";

    return 0;
}