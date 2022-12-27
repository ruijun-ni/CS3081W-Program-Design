#include <iostream>
#include <string>
using namespace std;

int getSplitIdx(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == '.') {
            return i;
        }
    }
    return -1;
}

int main() {
    /// TODO1: initialize the input/output variable and tld variables etc
    string address;
    string coreGtld1 = ".com";
    string coreGtld2 = ".net";
    string coreGtld3 = ".org";
    string coreGtld4 = ".info";

    /// TODO2: Repeatedly ask for user input and quit when user enters “q”
    while (address != "q") {
        cout << "Enter the next domain name (<Enter> to exit): " << endl;
        cin >> address;
        string oriAddress = address;
    
        
    // TODO3: convert to lowercase string
        for (int i = 0; i < address.length(); i++) {
            address.at(i) = tolower(address.at(i));
        }

    // TODO4: Check if string is a second level domain followed by a core Gtld.
    // hint: Extract the tld name starting at the period's position (can use substr()). Example: searchName = "example.com", extract ".com"
        int idx = getSplitIdx(address);

        string substring = address.substr(idx);
        if (idx <= 0 || (substring != coreGtld1 && substring != coreGtld2 && substring != coreGtld3 && substring != coreGtld4)) {
            cout << "\"" << oriAddress << "\"" << " is not a second-level domain followed by a core gTLD." << endl;
        } else {
            cout << "\"" << oriAddress << "\"" << " is a second-level domain followed by a core gTLD of " << substring << endl;
        } 
    }
    return 0;
}