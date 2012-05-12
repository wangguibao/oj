/*
 * Problem: 3299, Humidex
 * User: LoiteringLeo
 * Memory: 784K     Time: 0MS
 * Language: G++    Result: Accepted
*/
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

typedef struct _HUMIDEX {
    double t;
    double d;
    double h;
} HUMIDEX;

int main()
{
    char ch1;
    char ch2;
    double num1;
    double num2;
    double temperature = 0.0;
    double dewpoint = 0.0;
    double humidex = 0.0;
    double e = 0.0;
    double temph = 0.0;
    vector<HUMIDEX> humv;
    vector<HUMIDEX>::iterator iter;
    HUMIDEX hum;
    
    while (1) {
        cin >> ch1;
        if (ch1 == 'E') {
            break;
        }
        else {
            hum.t = hum.d = hum.h = -201.0;
            cin >> num1 >> ch2 >> num2;
            if ((num1 > 100.0 || num1 < -100.0) ||
                (num2 > 100.0 || num2 < -100.0)) {
                    continue;
            }

            switch (ch1) {
                case 'T': hum.t = num1; break;
                case 'D': hum.d = num1; break;
                case 'H': hum.h = num1; break;
                default: break;
            }

            switch (ch2) {
                case 'T': hum.t = num2; break;
                case 'D': hum.d = num2; break;
                case 'H': hum.h = num2; break;
                default: break;
            }
            humv.push_back(hum);
        }
    }
    
    for (iter = humv.begin(); iter < humv.end(); iter++) {
        hum = *iter;
        if (hum.t < -200.0) {    // t not set
            e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (hum.d + 273.16))));
            temph = 0.5555 * (e - 10.0);
            temperature = (double)hum.h - temph;
            cout.precision(1);
            cout << fixed << "T " << temperature << " D " << (double)hum.d << " H " << (double)hum.h << endl;
        }
        else if (hum.d < -200.0) {
            temph = (double)(hum.h - hum.t);
            e = temph / 0.5555 + 10.0;
            dewpoint =  1 / (1/ 273.16 - log(e / 6.11) / 5417.7530) - 273.16;
            cout .precision(1);
            cout << fixed << "T " << (double)hum.t << " D " << dewpoint << " H " << (double)hum.h << endl;
        }
        else if (hum.h < -200.0) {
            e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (hum.d + 273.16))));                
            temph = 0.5555 * (e - 10.0);
            humidex = (double)hum.t + temph;
            cout.precision(1);
            cout << fixed << "T " << (double)hum.t << " D " << (double)hum.d << " H " << humidex << endl;
        }
    } 
    //system("PAUSE");
    return EXIT_SUCCESS;
}

