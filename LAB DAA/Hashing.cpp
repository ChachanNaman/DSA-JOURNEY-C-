#include <iostream>
#include <cstring>
#include <cstdio> 
using namespace std;
//hello 
const int SIZE = 10;

class Record {
public:
    int roll;
    char name[20];

    Record() {
        roll = -1;  
        strcpy(name, "NULL");
    }
};

class Hashing {
    Record table[SIZE];
    int method; 

public:
    Hashing(int m) {
        method = m;
    }

    int hashFunction(int roll) {
        return roll % SIZE;
    }

    void insert(Record r) {
        if (method == 1)
            insertWithoutReplacement(r);
        else
            insertWithReplacement(r);
    }

    void insertWithoutReplacement(Record r) {
        int index = hashFunction(r.roll);
        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;
            if (table[pos].roll == -1) {
                table[pos] = r;
                return;
            }
        }
        cout << "Hash table is full.\n";
    }

    void insertWithReplacement(Record r) {
        int index = hashFunction(r.roll);

        if (table[index].roll == -1) {
            table[index] = r;
        } else {
            int existingIndex = hashFunction(table[index].roll);
            if (existingIndex != index) {
                Record temp = table[index];
                table[index] = r;

                for (int i = 1; i < SIZE; i++) {
                    int newIndex = (index + i) % SIZE;
                    if (table[newIndex].roll == -1) {
                        table[newIndex] = temp;
                        return;
                    }
                }
                cout << "Hash table is full.\n";
            } else {
                for (int i = 1; i < SIZE; i++) {
                    int newIndex = (index + i) % SIZE;
                    if (table[newIndex].roll == -1) {
                        table[newIndex] = r;
                        return;
                    }
                }
                cout << "Hash table is full.\n";
            }
        }
    }

    void display() {
        cout << "\nIndex\tRoll\tName\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].roll != -1) {
                cout << i << "\t" << table[i].roll << "\t" << table[i].name << "\n";
            } else {
                cout << i << "\t---\t---\n";
            }
        }
    }

    int search(int roll) {
        int index = hashFunction(roll);
        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;
            if (table[pos].roll == roll)
                return pos;
        }
        return -1;
    }

    void modify(int roll) {
        int pos = search(roll);
        if (pos != -1) {
            cout << "Enter new name: ";
            cin >> table[pos].name;
            cout << "Modified.\n";
        } else {
            cout << "Not found.\n";
        }
    }

    void addRecord() {
        Record r;
        cout << "Enter roll no, name: ";
        cin >> r.roll >> r.name;
        insert(r);
    }

    void createDatabase() {
        int n;
        cout << "How many records? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            addRecord();
        }
    }

    void saveToFile() {
        FILE *fp = fopen("database.txt", "w");
        if (fp == NULL) {
            cout << "File couldn't be created.\n";
            return;
        }

        for (int i = 0; i < SIZE; i++) {
            if (table[i].roll != -1) {
                fprintf(fp, "%d %s\n", table[i].roll, table[i].name);
            }
        }

        fclose(fp);
        cout << "Data saved to database.txt\n";
    }

    void loadFromFile() {
        FILE *fp = fopen("database.txt", "r");
        if (fp == NULL) {
            cout << "File not found.\n";
            return;
        }

        Record r;
        while (fscanf(fp, "%d %s", &r.roll, r.name) == 2) {
            insert(r);
        }

        fclose(fp);
        cout << "Data loaded from database.txt\n";
    }
};

int main() {
    int method;
    cout << "Choose method:\n1. Without Replacement\n2. With Replacement\nEnter: ";
    cin >> method;

    Hashing h(method);

    int choice;
    do {
        cout << "\nMENU\n1. Create DB\n2. Display\n3. Add Record\n4. Search\n5. Modify\n6. Save to File\n7. Load from File\n8. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: h.createDatabase(); break;
            case 2: h.display(); break;
            case 3: h.addRecord(); break;
            case 4: {
                int roll;
                cout << "Enter roll: ";
                cin >> roll;
                int pos = h.search(roll);
                if (pos != -1)
                    cout << "Found at index " << pos << "\n";
                else
                    cout << "Not found.\n";
                break;
            }
            case 5: {
                int roll;
                cout << "Enter roll: ";
                cin >> roll;
                h.modify(roll);
                break;
            }
            case 6: h.saveToFile(); break;
            case 7: h.loadFromFile(); break;
            case 8: cout << "Bye.\n"; break;
            default: cout << "Invalid.\n";
        }

    } while (choice != 8);

    return 0;
}