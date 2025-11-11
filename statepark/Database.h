// provided. do not modify. do not submit.
#ifndef PROVIDED_DATABASE_H_
#define PROVIDED_DATABASE_H_

#include <string>
#include <vector>
#include "Passport.h"
#include "StatePark.h"

class Database {
 private:
    std::vector<StatePark*> stateParkList;
    std::vector<Passport*> camperList;

 public:
    Database();
    ~Database();
    void addStatePark(std::string parkName, double entranceFee, double trailMiles);
    void addPassport(std::string camperName, bool isJuniorPassport);
    void addParkToPassport(std::string const& camperName, std::string const& parkName);
    std::vector<std::string> getParksInRevenueRange(double lowerBound, double upperBound) const;
    std::vector<std::string> getHikersAtLeastLevel(int level) const;
    StatePark* getParkAt(unsigned int i) { return stateParkList.at(i); }
    Passport* getCamperAt(unsigned int i) { return camperList.at(i); }
};

#endif  // PROVIDED_DATABASE_H_
