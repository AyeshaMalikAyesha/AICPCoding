#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

const int NUM_BOATS = 10;
const int OPEN_HOUR = 10;
const int CLOSE_HOUR = 17;
const double HOURLY_RATE = 20.0;
const double HALF_HOUR_RATE = 12.0;

struct Boat {
    bool isAvailable;
    double moneyTaken;
    int totalHoursHired;
    time_t returnTime;
};

void initializeBoats(std::vector<Boat>& boats) {
    for (int i = 0; i < NUM_BOATS; ++i) {
        boats.push_back({true, 0.0, 0, 0});
    }
}

int getCurrentHour() {
    time_t now = time(0);
    tm* timeInfo = localtime(&now);
    return timeInfo->tm_hour;
}

bool isValidTime(int hour) {
    return hour >= OPEN_HOUR && hour <= CLOSE_HOUR;
}

void hireBoat(std::vector<Boat>& boats, int boatNumber, int hours) {
    if (isValidTime(getCurrentHour())) {
        if (boats[boatNumber - 1].isAvailable) {
            boats[boatNumber - 1].isAvailable = false;
            boats[boatNumber - 1].totalHoursHired += hours;
            boats[boatNumber - 1].moneyTaken += (hours >= 1) ? (hours * HOURLY_RATE) : HALF_HOUR_RATE;
            boats[boatNumber - 1].returnTime = time(0) + hours * 3600;

            std::cout << "Boat " << boatNumber << " hired for " << hours << " hours." << std::endl;
        } else {
            std::cout << "Boat " << boatNumber << " is not available. Next available time: "
                      << std::put_time(localtime(&boats[boatNumber - 1].returnTime), "%H:%M")
                      << std::endl;
        }
    } else {
        std::cout << "Boat cannot be hired before 10:00 or after 17:00." << std::endl;
    }
}

void task2(std::vector<Boat>& boats) {
    int currentHour = getCurrentHour();
    int nextAvailableHour = CLOSE_HOUR + 1;

    for (int i = 0; i < NUM_BOATS; ++i) {
        if (boats[i].isAvailable) {
            std::cout << "Boat " << i + 1 << " is available for hire." << std::endl;
        } else {
            nextAvailableHour = std::min(nextAvailableHour, static_cast<int>(boats[i].returnTime / 3600));
        }
    }

    if (nextAvailableHour <= CLOSE_HOUR) {
        std::cout << "Next available time for hiring: " << nextAvailableHour << ":00" << std::endl;
    } else {
        std::cout << "No boats available today." << std::endl;
    }
}

void task3(const std::vector<Boat>& boats) {
    double totalMoney = 0.0;
    int totalHours = 0;
    int unusedBoats = 0;
    int mostUsedBoat = 0;
    int maxHours = 0;

    for (int i = 0; i < NUM_BOATS; ++i) {
        totalMoney += boats[i].moneyTaken;
        totalHours += boats[i].totalHoursHired;

        if (boats[i].totalHoursHired == 0) {
            ++unusedBoats;
        }

        if (boats[i].totalHoursHired > maxHours) {
            maxHours = boats[i].totalHoursHired;
            mostUsedBoat = i + 1;
        }
    }

    std::cout << "\nEnd of Day Report:\n";
    std::cout << "Total money taken: $" << std::fixed << std::setprecision(2) << totalMoney << std::endl;
    std::cout << "Total hours cboats were hired: " << totalHours << " hours" << std::endl;
    std::cout << "Number of boats not used: " << unusedBoats << std::endl;
    std::cout << "Boat #" << mostUsedBoat << " was used the most with " << maxHours << " hours." << std::endl;
}

int main() {
    std::vector<Boat> boats;
    initializeBoats(boats);

    // Task 1 - Example: Hire Boat #3 for 2 hours
    hireBoat(boats, 3, 2);

    // Task 2 - Example: Check boat availability
    task2(boats);

    // Task 3 - Example: End of day report
    task3(boats);

    return 0;
}

