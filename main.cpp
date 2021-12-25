#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

int main() {
    std::ifstream fin("SHIPS.in");
    std::ofstream fout("SHIPS.out");
    if (std::filesystem::is_empty("SHIPS.in")) {
        fout << "empty file. " << std::endl;
    }

    int N = 0;
    fin >> N;
    fin.ignore(10, '\n');
    std::vector<std::string> Pier(N,"free");
    std::deque<std::string> deq;
    while (!fin.eof()) {
        int operation;
        std::string ShipName;
        fin >> operation;
        std::getline(fin, ShipName);
        if (operation == 1) {
            for (auto & i : Pier) {
                if (i == "free") {
                    i = ShipName;
                    break;
                }
                if (i == Pier[Pier.size() - 1]) {
                    deq.push_back(ShipName);
                }
            }
            continue;
        }
        if (operation == 2) {
            if (! deq.empty()) {
                Pier[std::stoi(ShipName) - 1] = deq[0];
                deq.erase(deq.begin());
            } else Pier[std::stoi(ShipName) - 1] = "free";
            continue;
        }
        if (operation == 3) {
            if (!(deq.empty())) {
                fout << "deque:  ";
                int counter = 0;
                for (const auto &i: deq) {
                    fout << i << "; ";
                    ++counter;
                    if (counter % 5 == 0) {
                        fout << '\n' << "\t\t";
                    }
                }
            } else {
                fout << "deque is empty \n";
            }
            std::cout << std::endl;
            continue;
        }
        if (operation == 4) {
            fout << "Pier: " << std::endl;
            for (int i = 0; i < Pier.size(); ++i) {
                fout << '\t' << i + 1 << ": "  << Pier[i] << '\n';
            }
            fout << std::endl;
            continue;
        }
    }
    return 0;
}
