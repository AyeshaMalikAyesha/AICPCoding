#include <iostream>
#include <iomanip>
#include <vector>


const int MAX_PASSENGERS_PER_COACH = 80;
const int TICKET_PRICE = 25;
const int GROUP_DISCOUNT_SIZE = 10;


struct TrainJourney {
    int passengers_up;
    int passengers_down;
    int up_money;
    int down_money;

    TrainJourney() : passengers_up(0), passengers_down(0), up_money(0), down_money(0) {}
};

// Function to display the available tickets or "Closed" if full
void displayTickets(int available_tickets) {
    if (available_tickets > 0) {
        std::cout << available_tickets << " tickets available";
    } else {
        std::cout << "Closed";
    }
}

int main() {
   
    std::vector<TrainJourney> train_journeys(4);

    
    int total_passengers = 0;
    int total_money = 0;

    // Task 1 - Start of the day
    std::cout << "Electric Mountain Railway - Start of the Day\n\n";
    std::cout << "Train Schedule (Up and Down)\n";
    std::cout << "----------------------------------\n";

    for (int i = 0; i < 4; i++) {
        std::cout << "Journey " << (i + 1) << " (09:00 - 10:00): ";
        displayTickets(MAX_PASSENGERS_PER_COACH * 6 - train_journeys[i].passengers_up);
        std::cout << " | ";
        displayTickets(MAX_PASSENGERS_PER_COACH * 6 - train_journeys[i].passengers_down);
        std::cout << std::endl;
    }

    // Task 2 - Purchasing tickets
    std::cout << "\nTicket Purchase\n";
    std::cout << "----------------\n";

    while (true) {
        int num_passengers;
        int journey_index;
        char direction;

        std::cout << "Enter the number of passengers (1-80): ";
        std::cin >> num_passengers;

        if (num_passengers < 1 || num_passengers > 80) {
            std::cout << "Invalid number of passengers. Please enter a number between 1 and 80.\n";
            continue;
        }

        std::cout << "Enter the journey index (1-4):\n";
        std::cout << "1. 09:00 - 10:00\n";
        std::cout << "2. 11:00 - 12:00\n";
        std::cout << "3. 13:00 - 14:00\n";
        std::cout << "4. 15:00 - 16:00\n";
        std::cin >> journey_index;

        if (journey_index < 1 || journey_index > 4) {
            std::cout << "Please select a journey between 1 and 4.\n";
            continue;
        }

        std::cout << "Enter 'U' for up journey, 'D' for down journey: ";
        std::cin >> direction;

        if ((direction != 'U') && (direction != 'D')) {
            std::cout << "Invalid direction. Please enter 'U' for up journey or 'D' for down journey.\n";
            continue;
        }

        TrainJourney& current_journey = train_journeys[journey_index - 1];

        if (direction == 'U' || direction=='u') {
            if (current_journey.passengers_up + num_passengers > MAX_PASSENGERS_PER_COACH * 6) {
                std::cout << "Tickets are not available for the up journey.\n";
                continue;
            }
            current_journey.passengers_up += num_passengers;
            current_journey.up_money += num_passengers * TICKET_PRICE;
        } else {
            if (current_journey.passengers_down + num_passengers > MAX_PASSENGERS_PER_COACH * 6) {
                std::cout << "Tickets are not available for the down journey.\n";
                continue;
            }
            current_journey.passengers_down += num_passengers;
            current_journey.down_money += num_passengers * TICKET_PRICE;
        }

        // Update total counts
        total_passengers += num_passengers;
        total_money += num_passengers * TICKET_PRICE;

        // Check for group discount
        if (num_passengers >= GROUP_DISCOUNT_SIZE) {
            int free_tickets = (num_passengers / GROUP_DISCOUNT_SIZE) * GROUP_DISCOUNT_SIZE;
            total_money -= free_tickets * TICKET_PRICE;
        }

        // Display the updated train schedule
        std::cout << "\nUpdated Train Schedule (Up and Down)\n";
        std::cout << "----------------------------------\n";

        for (int i = 0; i < 4; i++) {
            std::cout << "Journey " << (i + 1) << " (09:00 - 10:00): ";
            displayTickets(MAX_PASSENGERS_PER_COACH * 6 - train_journeys[i].passengers_up);
            std::cout << " | ";
            displayTickets(MAX_PASSENGERS_PER_COACH * 6 - train_journeys[i].passengers_down);
            std::cout << std::endl;
        }

        std::cout << "\nTotal Passengers: " << total_passengers << "\n";
        std::cout << "Total Money: $" << total_money << "\n";

        char cont;
        std::cout << "Do you want to make another purchase? (Y/N): ";
        std::cin >> cont;

        if (cont != 'Y' && cont != 'y') {
            break;
        }
    }

    // Task 3 - End of the day
    std::cout << "\nEnd of the Day Summary\n";
    std::cout << "-----------------------\n";

    for (int i = 0; i < 4; i++) {
        std::cout << "Journey " << (i + 1) << " (Up): " << train_journeys[i].passengers_up << " passengers, $" << train_journeys[i].up_money << "\n";
        std::cout << "Journey " << (i + 1) << " (Down): " << train_journeys[i].passengers_down << " passengers, $" << train_journeys[i].down_money << "\n";
    }

    // Calculate the train journey with the most passengers
    int max_passengers = 0;
    int max_journey_index = 0;

    for (int i = 0; i < 4; i++) {
        int total_passengers_journey = train_journeys[i].passengers_up + train_journeys[i].passengers_down;

        if (total_passengers_journey > max_passengers) {
            max_passengers = total_passengers_journey;
            max_journey_index = i;
        }
    }

    std::cout << "\nTrain journey with the most passengers: Journey " << (max_journey_index + 1) << "\n";
    std::cout << "Total Passengers for the day: " << total_passengers << " passengers\n";
    std::cout << "Total Money for the day: $" << total_money << "\n";

    return 0;
}
