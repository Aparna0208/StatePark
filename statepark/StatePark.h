// provided. do not modify. do not submit.
#ifndef PROVIDED_STATEPARK_H_
#define PROVIDED_STATEPARK_H_

#include <string>
#include <vector>
#include <iostream>

#define INFO(X) std::cout << "[INFO] (" << __func__ << ":" << __LINE__ << ") " << #X << " = " << X << std::endl;

// forward declaration because Passport and StatePark refer to each other
class Passport;

class StatePark {
 private:
    std::string parkName;
    double entranceFee;
    double trailMiles;
    std::vector<Passport*> camperLog;

 public:
    StatePark(std::string parkName, double entranceFee, double trailMiles);
    std::string getParkName() const;
    double getEntranceFee() const;
    double getTrailMiles() const;
    void addCamper(Passport* camper);
    double getRevenue() const;

    Passport* getCamperAt(unsigned int i) { return camperLog.at(i); }
};

#endif  // PROVIDED_STATEPARK_H_
