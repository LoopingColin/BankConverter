#include <iostream>
#include <iomanip>

struct Currency {
    std::string name;
    double exchange_rate;
};

double convertCurrency(double amount, const Currency& currency) {
    return amount * currency.exchange_rate;
}

int main() {
    Currency currencies[] = {
        {"Colombian Pesos (COP)", 0.00024},
        {"Brazilian Reais (BRL)", 0.20},
        {"Peruvian Soles (PEN)", 0.26},
        {"Euros (EUR)", 1.06},
        {"British Pounds (GBP)", 1.21}
    };

    while (true) {
        std::cout << "Currency Conversion Service\n";
        std::cout << "--------------------------\n";

      
        for (int i = 0; i < 5; i++) {
            std::cout << i + 1 << ". " << currencies[i].name << std::endl;
        }

       
        int choice;
        std::cout << "Select the currency you want to convert (1-5): ";
        std::cin >> choice;

        if (choice < 1 || choice > 5) {
            std::cout << "Invalid choice. Please select a valid option.\n";
            continue;
        }

        double currency_amount, usd_amount, conversion_charge;
        std::string currency_name = currencies[choice - 1].name;

       
        std::cout << "Enter the amount of " << currency_name << ": ";
        std::cin >> currency_amount;

    
        usd_amount = convertCurrency(currency_amount, currencies[choice - 1]);

       
        conversion_charge = usd_amount * 0.02;

    
        double usd_after_charge = usd_amount - conversion_charge;

      
        std::cout << "--------------------------\n";
        std::cout << "Currency Converted: " << currency_amount << " " << currency_name << std::endl;
        std::cout << "Total USD: $" << usd_amount << std::endl;
        std::cout << "Currency Conversion Charge (2%): $" << conversion_charge << std::endl;
        std::cout << "Amount in USD after charge: $" << usd_after_charge << std::endl;

      
        char another_conversion;
        std::cout << "Convert another currency? (Y/N): ";
        std::cin >> another_conversion;

        if (another_conversion != 'Y' && another_conversion != 'y') {
            std::cout << "Thank you for using our Currency Conversion Service. Goodbye!\n";
            break; 
        }
    }

    return 0;
}
