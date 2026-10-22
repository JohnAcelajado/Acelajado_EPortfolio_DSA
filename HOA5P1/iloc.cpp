#include <iostream>
#include <ctime>
#include "queuell3.h"

int main() {
    Printer printer;

    std::cout << "======== Queueing Print Requests ========\n";
    printer.addJob(67, "Vince", 6);
    printer.addJob(68, "Naruto", 7);
    printer.addJob(69, "Goku", 9);

    std::cout << "\n======== Processing Print Requests ========\n\n";
    printer.processJobs();

    return 0;
}