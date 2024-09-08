//
// Created by stg05 on 08.09.2024.
//

#include <iostream>

#define ACCURACY 1e-10
#define PI 3.14159265358979

namespace my_math {
    double sin(double x) {
        double answer = 0;
        double delim = 1;
        double xp = x;
        for (int counter = 1; true; counter += 2) {
            double delta = xp / delim;
            answer += delta;
            if (std::abs(delta) < ACCURACY) {
                break;
            }
            xp *= x * x;
            delim *= (counter + 1) * (counter + 2) * (-1);
        }
        return answer;
    }

    double cos(double x) {
        double answer = 1;
        double delim = 2;
        double xp = -x * x;
        for (int counter = 2; true; counter += 2) {
            double delta = xp / delim;
            answer += delta;
            if (std::abs(delta) < ACCURACY) {
                break;
            }
            xp *= x * x;
            delim *= (counter + 1) * (counter + 2) * (-1);
        }
        return answer;
    }

    double tan(double x) {
        return sin(x) / cos(x);
    }

    double asin(double x) {
        double answer = 0;
        double mult = 1;
        double xp = x;
        for (int counter = 1; true; counter += 2) {
            double delta = xp * mult / counter;
            answer += delta;
            if (std::abs(delta) < ACCURACY) {
                break;
            }
            xp *= x * x;
            mult *= 1.0 * counter / (counter + 1);
        }
        return answer;
    }

    double acos(double x) {
        return PI - asin(x);
    }

    double atan(double x) {
        double answer = 0;
        double mult = 1;
        double xp = x;
        for (int counter = 1; true; counter += 2) {
            double delta = xp * mult;
            answer += delta;
            if (std::abs(delta) < ACCURACY) {
                break;
            }
            xp *= x * x;
            mult = 1.0 * (((counter / 2) % 2) * (2) - 1) / (counter + 2);
        }
        return answer;
    }
}
