#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::MatrixXcd H(2, 2);
    H << 0, 1,
         1, 0;

    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> solver(H);
    std::cout << "Eigenvalues:\n" << solver.eigenvalues() << std::endl;

    return 0;
}
