#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long int factrial(long int n) {
   if (n == 0 || n == 1)
        return 1;
   else
       return n * factrial(n - 1);
}

long int combination(int n, int r) {
    return factrial(n) / (factrial(r) * factrial(n-r));
}

long int coefficient(int x, int y, int n, int r) {
    return x * y * combination(n, r);
}


string Binomial_Sigma(int x, int y, int n) {
    int j = 0;
    int x_co;
    int y_co;
    string ans;
    vector <int> terms;
    vector <int> x_coeffcient;
    vector <int> y_coeffcient;
    vector <int> x_power;
    vector <int> y_power;
    vector <string> result;
   
    for (j = 0; j < n+1; j++) 
    {
        if(x != 1) { // x is not 1
            x_co = pow(x, n-j);
            cout << "x-co is " << x_co << "when x is " << x << "and n-j is " << n-j << endl;
            x_coeffcient.push_back(x_co);
        }
        else {
            x_coeffcient.push_back(1);
        }
        if(y != 1) { // x is not 1
            y_co = pow(y, j);
            y_coeffcient.push_back(y_co);
        }
        else {
            y_coeffcient.push_back(1);
        }
        x_power.push_back(n-j);
        y_power.push_back(j);
        
    }
    
    for (int i = 0; i < y_power.size(); i++) {
            string term, x, y;
            if(x_power[i] == 0) x = "";
            else if(x_power[i] == 1) x = "x";
            else x = "x^"+to_string(x_power[i]);
            if(y_power[i] == 0) y = "";
            else if(y_power[i] == 1) y = "y";
            else y = "y^"+to_string(y_power[i]);
     
            if(i == 0) {
                result.push_back(to_string(coefficient(x_coeffcient[i], y_coeffcient[i], n, i)) + x + " + ");
            }

            else if(i == y_power.size()-1) {
                result.push_back(to_string(coefficient(x_coeffcient[i], y_coeffcient[i], n, i)) + y);
            }
            else {
                result.push_back(to_string(coefficient(x_coeffcient[i], y_coeffcient[i], n, i)) + x + "*" + y + " + ");
            }
            
            ans += result[i];
        }
    return ans;
}



int main() {

    int x = 0;
    int y = 0;
    int n = 0; // power

    cout << "Enter x-value (1 - 9)" << endl;
    cin >> x;
    cout << "Enter y-value (1 - 9)" << endl;
    cin >> y;
    cout << "Enter the power (1 - 9)" << endl;
    cin >> n;

    if(x >= 10 || y >= 10) cout << "[-] x or y is exceeding 10" << endl;
    else if (n >= 10) cout << "[-] power is exceeding 10" << endl;
    else if(n == 0 || y == 0 || x == 0) cout << "[-] Input cannot be 0" << endl;
    else cout << Binomial_Sigma(x, y, n) << endl;
}