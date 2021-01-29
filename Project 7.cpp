#include <iostream>
#include <vector>
#include <variant>
#include <sstream>
#include <algorithm>

struct CurrencyExchanger {
    int id = 0;
    double purchaseRate = 0;
    double sellingRate = 0;
    std::string nameOfExchanger;
};

int main()
{
    const char inputData[] = { "1,1.2,1.3,Str1\n2,1.1,1.4,Str2\n3,0.3,0.8,Str1\n4,1.2,1.3,Str1\n5,1.2,1.3,Str2" };

    std::vector<CurrencyExchanger> CurrencyExchangerVector;

    std::stringstream stream(inputData);

    for (int i = 0; stream;) {
        CurrencyExchanger data;
        stream >> data.id;
        if (stream.peek() == ',')
            stream.ignore();
        stream >> data.purchaseRate;
        if (stream.peek() == ',')
            stream.ignore();
        stream >> data.sellingRate;
        if (stream.peek() == ',')
            stream.ignore();
        stream >> data.nameOfExchanger;
        if (stream.peek() == '\n')
            stream.ignore();
        CurrencyExchangerVector.emplace_back(data);
    }

    decltype(CurrencyExchangerVector)::iterator maxEl1, maxEl2, maxEl3, maxEl4;
       
    maxEl1 = std::max_element(begin(CurrencyExchangerVector), end(CurrencyExchangerVector),
        [](const CurrencyExchanger& a, const CurrencyExchanger& b)
        {             
            return (a.nameOfExchanger > b.nameOfExchanger && a.sellingRate < b.sellingRate);
        });

     maxEl2 = std::max_element(begin(CurrencyExchangerVector), end(CurrencyExchangerVector),
        [](const CurrencyExchanger& a, const CurrencyExchanger& b)
        {          
             return (a.nameOfExchanger > b.nameOfExchanger && a.purchaseRate < b.purchaseRate);
        });    

     maxEl3 = std::max_element(begin(CurrencyExchangerVector), end(CurrencyExchangerVector),
         [](const CurrencyExchanger& a, const CurrencyExchanger& b)
         {                     
              return (a.nameOfExchanger < b.nameOfExchanger && a.sellingRate < b.sellingRate);
         });

     maxEl4 = std::max_element(begin(CurrencyExchangerVector), end(CurrencyExchangerVector),
         [](const CurrencyExchanger& a, const CurrencyExchanger& b)
         {                         
             return (a.nameOfExchanger < b.nameOfExchanger && a.purchaseRate < b.purchaseRate);
         });

    std::cout << "maxSellingRate Str1 " << maxEl1->sellingRate << " maxPurchaseRate Str1 " << maxEl2->purchaseRate << std::endl;
    std::cout << "maxSellingRate Str2 " << maxEl3->sellingRate << " maxPurchaseRate Str2 " << maxEl4->purchaseRate << std::endl;
    std::cout << "Difference between maxSellingRate and maxPurchaseRate of Str1 = " << maxEl1->sellingRate - maxEl2->purchaseRate << std::endl;
    std::cout << "Difference between maxSellingRate and maxPurchaseRate of Str1 = " << maxEl3->sellingRate - maxEl4->purchaseRate << std::endl;
}