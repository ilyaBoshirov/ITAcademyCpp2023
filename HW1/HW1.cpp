#include "КartingAssistant.h"

void menu(std::string programmName) {
    auto exitFlag = false;
    std::string userChoice{};

    RACEINFO history = loadResults();
    RACEINFO currentRasce{};

    while (!exitFlag) {
        printMenu();
        std::cout << std::endl << "Your choise: ";
        std::cin >> userChoice;
        std::cout << std::endl;

        try {
            switch (std::stoi(userChoice))
            {
            case 1:
                clearCmd();
                currentRasce = startNewRace();
                saveResults(currentRasce);
                history.insert(history.end(), currentRasce.begin(), currentRasce.end());
                backToMenu();
                break;

            case 2:
                printLastResult(history);
                break;

            case 3:
                printAllResults(history);
                break;

            case 4:
                printHelpMessage(programmName);
                break;

            case 5:
                clearCmd();
                break;

            case 6:
                std::cout << "Bye!" << std::endl;
                exitFlag = true;
                break;

            default:
                std::cout << "Wrong value! Please, try again" << std::endl;
                break;
            }
        }
        catch (std::invalid_argument const& e) {
            std::cout << "Please, type integer value. Try again" << std::endl;
        }
        catch (std::exception const& e) {
            std::cout << "Something get wrong." << std::endl;
            std::cout << "Message: " << e.what() << std::endl;
            std::cout << "Type:    " << typeid(e).name() << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    std::string programmName{ argv[0] };
    menu(programmName);
    return 0;
}
