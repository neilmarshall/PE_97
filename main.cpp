//
//  main.cpp
//  PE_97 (large non-Mersenne prime)
//
//  Created by Neil Marshall on 13/02/2016.
//  Copyright © 2016 Neil Marshall. All rights reserved.
//

#include <iostream>
#include "NumericString.hpp"
#include <cmath>

const long digit_limit = 10;

void restrict_digits(NumericString& string_to_be_restricted) {
    string temp_string = "";
    for (long i = string_to_be_restricted.size() - digit_limit; i < string_to_be_restricted.size(); ++i) {
        temp_string = temp_string + string_to_be_restricted.S[i];
    }
    string_to_be_restricted = temp_string;
}

int main() {
    
    long power_limit = 7830457;
    long max_power_indicator = log(power_limit) / log(2);
    vector<bool> power_indicator;
    vector<bool> ordered_power_indicator;
    vector<NumericString> powers;
    NumericString initial_var = fnStrRepresentation(1);
    NumericString multiple_var = fnStrRepresentation(2);
    NumericString temp_output_var = fnStrRepresentation(1);
    NumericString output_var = fnStrRepresentation(1);
    NumericString multiplier = fnStrRepresentation(28433);
    NumericString addition = fnStrRepresentation(1);
    
    for (long i = max_power_indicator; i >= 0; --i) {
        if (pow(2, i) <= power_limit) {
            power_indicator.push_back(true);
            power_limit = power_limit - pow(2, i);
        }
        else {
            power_indicator.push_back(false);
        }
    }
    
    for (long i = max_power_indicator; i >= 0; --i) {
        if (power_indicator[i] == true) {
            ordered_power_indicator.push_back(true);
        }
        else {
            ordered_power_indicator.push_back(false);
        }
    }
    
    powers.push_back(initial_var);
    for (long i = 1; i <= max_power_indicator; ++i) {
        powers.push_back(powers[i - 1] * multiple_var);
    }
    
    for (long i = 0; i <= max_power_indicator; ++i) {
        cout << "Checking power " << i << " of " << max_power_indicator << '\n';
        if (ordered_power_indicator[i] == true) {
            temp_output_var = output_var * powers[i];
            if (temp_output_var.size() > digit_limit) {
                restrict_digits(temp_output_var);
            }
            output_var = temp_output_var;
        }
    }
    
    output_var = output_var * multiplier + addition;
    restrict_digits(output_var);

    cout << output_var.value() << '\n';
    return 0;
}

//int main() {
//    
//    long power_counter = 0;
//    long power_limit = 7830457;
//    NumericString initial_var = fnStrRepresentation(2);
//    NumericString temp_output_var = fnStrRepresentation(1);
//    NumericString output_var = fnStrRepresentation(1);
//    
//    while (power_counter < power_limit) {
//        cout << "power_counter = " << power_counter << '\n';
//        temp_output_var = initial_var * output_var;
//        if (temp_output_var.size() > digit_limit) {
//            restrict_digits(temp_output_var);
//        }
//        output_var = temp_output_var;
//        ++power_counter;
//    }
//    
//    NumericString multiplier = fnStrRepresentation(28433);
//    NumericString addition = fnStrRepresentation(1);
//    output_var = output_var * multiplier + addition;
//    restrict_digits(output_var);
//    
//    cout << output_var.value() << '\n';
//    return 0;
//}