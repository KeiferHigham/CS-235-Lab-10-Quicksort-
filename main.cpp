#include <iostream>
#include <fstream>
#include <sstream>
#include "QuickSort.h"


using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out) {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }


    string command;
    QuickSort<int> addSort;


    for (string line; getline(in, line);) {
        stringstream input(line);
        input >> command;
        if (command == "QuickSort") {
            int capacity;
            out << line << " OK" << endl;
            input >> capacity;
            addSort.SetQuickSort(capacity);
        } else if (command == "Capacity") {
            out << line << " " << addSort.capacity() << endl;
        } else if (command == "Clear") {
            out << line << " OK" << endl;
            addSort.clear();
        } else if (command == "AddToArray") {
            stringstream iss;

            int num;
            while(input >> num) {
                iss << num << ",";
                addSort.addElement(num);
            }
            string addOutput = iss.str();
            addOutput.pop_back();
            out << command << " " << addOutput << " OK" << endl;
        } else if (command == "PrintArray") {
            if(addSort.size() == 0) {
                out << line << " Empty" << endl;
            }
            else {
                out << line << " " << addSort.toString() << endl;
            }
        } else if (command == "Size") {
            out << line << " " << addSort.size() << endl;
        } else if (command == "MedianOfThree") {
            size_t left;
            size_t right;
            input >> left;
            input >> right;
            out << command << " " << left << "," << right << " = " << addSort.medianOfThree(left, right) << endl;
        } else if (command == "Partition") {
            int left;
            int middle;
            int right;
            input >> left;
            input >> right;
            input >> middle;
            out << command << " " << left << "," << right << "," << middle << " = ";
            out << addSort.partition(left,right,middle) << endl;

        } else if (command == "SortAll") {
            out << line << " OK" << endl;
            addSort.sortAll();

        } else if (command == "Sort") {
           size_t left;
           size_t right;
           input >> left;
           input >> right;
           addSort.sort(left,right);
           out << command << " " << left << "," << right << " OK" << endl;
        } else if (command == "Stats") {
            out << line << endl;
        } else {
            continue;
        }
    }



    return 0;
}
