// provided. do not modify. do not submit.
#ifndef PROVIDED_PASSPORT_H_
#define PROVIDED_PASSPORT_H_

#include <string>
#include <vector>
#include "StatePark.h"

class Passport {
 private:
    std::string camperName;
    bool isJuniorPassport;
    std::vector<StatePark*> parksVisited;

    double getMilesHiked() const;

 public:
    Passport(std::string camperName, bool isJuniorPassport);
    std::string getCamperName() const;
    bool checkJuniorPassport() const;
    void addParkVisited(StatePark* park);
    int getHikerLevel() const;

    StatePark* getParkAt(unsigned int i) { return parksVisited.at(i); }
};

#endif  // PROVIDED_PASSPORT_H_
