#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

vector<vector<double>> newmarkBeta(
    const vector<double> &data, const map<string, double>& params
)
{
    // Read File
    size_t n = data.size();

    // Variable
    double h = 0.03;
    double T = 1.0;
    double dt = 0.02;
    double beta = 0.25;
    if (params.count("h"))    h = params.at("h");
    if (params.count("T"))    T = params.at("T");
    if (params.count("dt"))   dt = params.at("dt");
    if (params.count("beta")) beta = params.at("beta");

    const double omega = 2.0 * M_PI / T;

    const double a = 1 + h * omega * dt + omega * omega * beta * dt * dt;
    const double b = omega * omega;
    const double c = 2 * h * omega + omega * omega * dt;
    const double d = h * omega * dt + (0.5 - beta) * omega * omega * dt * dt;

    // Calculate
    vector<vector<double>> R(n, vector<double>(7, 0.0)); // 0:time, 1:x0, 2:a, 3:v, 4:x

    R[0][1] = data[0];
    R[0][2] = -R[0][1];

    for (size_t i = 1; i < n; ++i)
    {
        R[i][0] = i * dt;
        R[i][1] = data[i];
        R[i][2] = -(b * R[i - 1][4] + c * R[i - 1][3] + d * R[i - 1][2] + data[i]) / a;
        R[i][3] = R[i - 1][3] + 0.5 * (R[i - 1][2] + R[i][2]) * dt;
        R[i][4] = R[i - 1][4] + R[i - 1][3] * dt + 
            (0.5 - beta) * R[i - 1][2] * dt * dt + beta * R[i][2] * dt * dt;
    }

    for (size_t i = 0; i < n; ++i)
    {
        R[i][2] += R[i][1];
    }

    return R;
}

vector<vector<vector<double>>> response_spectrum(
    const vector<double> &data, 
    const vector<double> &h_list, 
    const map<string, double> &params
)
{
    double max_T = 5.0;
    double dT = 0.02;
    double dt = 0.02;
    double beta = 0.25;
    if (params.count("max_T")) max_T = params.at("max_T");
    if (params.count("dT"))    dT = params.at("dT");
    if (params.count("dt"))    dt = params.at("dt");
    if (params.count("beta"))  beta = params.at("beta");

    vector<vector<vector<double>>> S(
        h_list.size(), vector<vector<double>>(4, vector<double>(0, 0.0))
    );

    for (size_t s = 0; s < h_list.size(); s++)
    {
        double h = h_list[s];
        double T = dT;
        while (T <= max_T)
        {
            map<string, double> new_params;
            new_params["h"] = h;
            new_params["T"] = T;
            new_params["dt"] = dt;
            new_params["beta"] = beta;

            vector<vector<double>> R = newmarkBeta(data, new_params);
            size_t N = R.size();
            double max_acc = 0, max_vel = 0, max_disp = 0;
            
            for (size_t i = 0; i < N; i++)
            {
                max_acc = max(max_acc, abs(R[i][2]));
                max_vel = max(max_vel, abs(R[i][3]));
                max_disp = max(max_disp, abs(R[i][4]));
            }
            S[s][0].push_back(T);        // T value [sec]
            S[s][1].push_back(max_acc);  // Acc. [gal]
            S[s][2].push_back(max_vel);  // Vel. [kine]
            S[s][3].push_back(max_disp); // Disp. [cm]
            T += dT;
        }
    }
    return S;
}