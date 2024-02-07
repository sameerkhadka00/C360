//Answer of 2

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    bool isNaM;

public:
   
    Matrix(const std::string& input) {
        std::stringstream ss(input);
        int num;
        std::vector<int> row;

        while (ss >> num) {
            row.push_back(num);
            if (ss.peek() == ',') ss.ignore();
            if (ss.peek() == ';') {
                data.push_back(row);
                row.clear();
                ss.ignore();
            }
        }
        data.push_back(row);  

       
        int cols = data[0].size();
        isNaM = false;
        for (const auto& r : data) {
            if (r.size() != cols) {
                isNaM = true;
                break;
            }
        }
    }

    
    ~Matrix() {
        
        data.clear(); 
    }

   
    bool IsNaM() const { return isNaM; }

    
    int& operator()(int i, int j) { return data[i][j]; }
    const int& operator()(int i, int j) const { return data[i][j]; } 

   
};

int main() {
    
    Matrix m("1,2,3;4,5,6;7,8,9");

    
    if (m.IsNaM()) {
        std::cout << "The matrix is not valid.\n";
    } else {
        std::cout << "The matrix is valid.\n";
    }

    
    std::cout << "The element at (0, 0) is " << m(0, 0) << "\n";

    return 0;
}


