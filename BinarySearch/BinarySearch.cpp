#include <iostream>
using namespace std;

class SearchAlgorithm {
private:
    int arr[20];
    int n;
    int i;

public:
    void input() {
        while (true) {
            cout << "Enter the number of elements in the array: ";
            cin >> n;
            if (n > 0 && n <= 20)
                break;
            else
                cout << "\nArray should have minimum 1 and maximum 20 elements.\n";
        }

        cout << "\n----------------------";
        cout << "\nEnter array elements";
        cout << "\n----------------------\n";
        for (i = 0; i < n; i++) {
            cout << "<" << (i + 1) << ">";
            cin >> arr[i];
        }
    }

    void binarySearch() {
        char ch;
        do {
            cout << "\nEnter element you want to search: ";
            int item;
            cin >> item;

            int lowerbound = 0;
            int upperbound = n - 1;
            int mid = (lowerbound + upperbound) / 2;
            int ctr = 0;

            while (item != arr[mid] && lowerbound <= upperbound) {
                if (item > arr[mid])
                    lowerbound = mid + 1;
                else
                    upperbound = mid - 1;

                mid = (lowerbound + upperbound) / 2;
                ctr++;
            }

            if (item == arr[mid])
                cout << "\n" << item << " found at position " << (mid + 1);
            else
                cout << "\n" << item << " not found in the array\n";

            cout << "\nNumber of comparisons: " << ctr;
            cout << "\nContinue search (y/n): ";
            cin >> ch;

        } while (ch == 'y' || ch == 'Y');
    }
};

int main() {
    SearchAlgorithm myList;
    myList.input();
    myList.binarySearch();

    return 0;
}
