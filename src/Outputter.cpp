#include <map>
#include "Outputter.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include "IncrementalAlphabet.h"


namespace IO {
void Outputter::print(const std::map<std::string, WordDetails>& wordMap, size_t maxWordSize) {

    IncrementalAlphabet incAlph;
    auto wordWidth = static_cast<int>(maxWordSize * 1.6);
    auto alphabetWidth = static_cast<int>(wordMap.size()/26);

    for ( const auto& wrd: wordMap )
    {
        std::stringstream ss;
        ss << std::setw(alphabetWidth) << incAlph.getNext() << ".\t\t";
        ss << std::setw(wordWidth) << std::left << wrd.first;
        ss << std::right << "{" << wrd.second.count << ":";
        for ( auto i = wrd.second.position.begin(); i != wrd.second.position.end(); i++ )
        {
            ss << *i;
            if ( i != wrd.second.position.end() - 1 )
            {
                ss << ",";
            }
        }
        ss << "}\n";
        std::cout << ss.str();
    }
}
} // IO