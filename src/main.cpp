#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <cmath>
#include <Eigen/Dense>

const double gamma0 = 3.0;
const double a = 1.0;

std::complex<double> f(double kx, double ky) {
    using namespace std::complex_literals;
    return std::exp(1i * kx * a)
         + 2.0 * std::exp(-1i * kx * a / 2.0) * std::cos(ky * a * std::sqrt(3.0) / 2.0);
}

Eigen::MatrixXcd graphene_H(double kx, double ky) {
    Eigen::MatrixXcd H(2, 2);
    std::complex<double> fk = gamma0 * f(kx, ky);
    H << 0,               fk,
         std::conj(fk),   0;
    return H;
}

int main() {
    int nk = 200;
    std::ofstream out("bands.dat");

    double Gx = 0.0, Gy = 0.0;
    double Mx = M_PI / a, My = M_PI / (a * std::sqrt(3.0));
    double Kx = 2.0 * M_PI / (3.0 * a), Ky = 2.0 * M_PI / (std::sqrt(3.0) * a);

    std::vector<std::pair<double,double>> path;

    for (int i = 0; i < nk; i++) {
        double t = (double)i / nk;
        path.push_back({Gx + t*(Mx-Gx), Gy + t*(My-Gy)});
    }
    for (int i = 0; i < nk; i++) {
        double t = (double)i / nk;
        path.push_back({Mx + t*(Kx-Mx), My + t*(Ky-My)});
    }
    for (int i = 0; i <= nk; i++) {
        double t = (double)i / nk;
        path.push_back({Kx + t*(Gx-Kx), Ky + t*(Gy-Ky)});
    }

    for (int i = 0; i < (int)path.size(); i++) {
        auto [kx, ky] = path[i];
        Eigen::MatrixXcd H = graphene_H(kx, ky);
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> solver(H);
        out << i << " " << solver.eigenvalues()(0) << " " << solver.eigenvalues()(1) << "\n";
    }

    std::cout << "Done. Bands written to bands.dat\n";
    return 0;
}