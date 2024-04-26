/*
macroeconomics project which calculates gdp, cpi, unemployment rate, national income, different approach to calculate gdp, GNP, NNP, NDP, PI, DI, Inflation, real gdp, nominal gdp, gdp deflator, PPI, labor force participation rate etc.
*/

#include <iostream>

using namespace std;

class EconomicIndicator
{
protected:
    string name;
    double value;
    string unit;

public:
    EconomicIndicator(string name, string unit) : name(name), unit(unit), value(0) {}

    // pure virtual function to calculate the value of the economic indicator
    // this function will be implemented in the derived classes
    virtual void calculate() = 0;
    virtual void askForInput() = 0;

    // function to display the value of the economic indicator
    void display() const
    {
        cout << name << ": " << value << " " << unit << endl;
    }
};

class GDP : public EconomicIndicator
{
private:
    double consumption;
    double investment;
    double governmentSpending;
    double exports;
    double imports;

public:
    GDP() : EconomicIndicator("GDP", "BDT"), consumption(0), investment(0), governmentSpending(0), exports(0), imports(0) {}

    void calculate() override
    {
        value = consumption + investment + governmentSpending + (exports - imports);
    }

    void setConsumption(double consumption)
    {
        this->consumption = consumption;
    }

    void setInvestment(double investment)
    {
        this->investment = investment;
    }

    void setGovernmentSpending(double governmentSpending)
    {
        this->governmentSpending = governmentSpending;
    }

    void setExports(double exports)
    {
        this->exports = exports;
    }

    void setImports(double imports)
    {
        this->imports = imports;
    }

    void display() const
    {
        cout << name << ": " << value << " " << unit << endl;
        cout << "Consumption: " << consumption << " " << unit << endl;
        cout << "Investment: " << investment << " " << unit << endl;
        cout << "Government Spending: " << governmentSpending << " " << unit << endl;
        cout << "Exports: " << exports << " " << unit << endl;
        cout << "Imports: " << imports << " " << unit << endl;
    }

    void askForInput() override
    {
        cout << "Enter Consumption: ";
        cin >> consumption;
        cout << "Enter Investment: ";
        cin >> investment;
        cout << "Enter Government Spending: ";
        cin >> governmentSpending;
        cout << "Enter Exports: ";
        cin >> exports;
        cout << "Enter Imports: ";
        cin >> imports;
    }
};

class CPI : public EconomicIndicator
{
private:
    double priceIndex;
    double baseYearPriceIndex;

public:
    CPI() : EconomicIndicator("CPI", ""), priceIndex(0), baseYearPriceIndex(0) {}

    void calculate() override
    {
        value = (priceIndex / baseYearPriceIndex) * 100;
    }

    void setPriceIndex(double priceIndex)
    {
        this->priceIndex = priceIndex;
    }

    void setBaseYearPriceIndex(double baseYearPriceIndex)
    {
        this->baseYearPriceIndex = baseYearPriceIndex;
    }

    void display() const
    {
        cout << name << ": " << value << endl;
        cout << "Price Index: " << priceIndex << endl;
        cout << "Base Year Price Index: " << baseYearPriceIndex << endl;
    }

    void askForInput() override
    {
        cout << "Enter Price Index: ";
        cin >> priceIndex;
        cout << "Enter Base Year Price Index: ";
        cin >> baseYearPriceIndex;
    }
};

int main()
{
start:
    cout << "1. GDP" << endl;
    cout << "2. CPI" << endl;
    cout << "3. Unemployment Rate" << endl;
    cout << "4. National Income" << endl;
    cout << "5. Different Approach to Calculate GDP" << endl;
    cout << "6. GNP" << endl;
    cout << "7. NNP" << endl;
    cout << "8. NDP" << endl;
    cout << "9. PI" << endl;
    cout << "10. DI" << endl;
    cout << "11. Inflation" << endl;
    cout << "12. Real GDP" << endl;
    cout << "13. Nominal GDP" << endl;
    cout << "14. GDP Deflator" << endl;
    cout << "15. PPI" << endl;
    cout << "16. Labor Force Participation Rate" << endl;
    cout << "17. Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
    {
        GDP gdp;
        gdp.askForInput();
        gdp.calculate();
        gdp.display();
        break;
    }
    case 2:
    {
        CPI cpi;
        cpi.askForInput();
        cpi.calculate();
        cpi.display();
        break;
    }
    case 17:
        return 0;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    cout << endl;
    cout << "Start again? (y/n): ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        goto start;

    return 0;
}