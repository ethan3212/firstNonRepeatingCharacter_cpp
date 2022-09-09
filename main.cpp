#include <iostream>
#include <unordered_map>
using namespace std;

// O(n) time | O(1) space
int firstNonRepeatingCharacterHashTable(string string) {
   unordered_map<char, int> frequencies;// O(1) space
   for(char character : string) {// O(n) time
       if(frequencies.find(character) == frequencies.end()) {
           frequencies[character] = 0;
       }
       frequencies[character]++;
   }
   for(int i = 0; i < string.length(); i++) {// O(n) time
       char character = string[i];
       if(frequencies[character] == 1) {
           return i;
       }
   }
   return -1;
}

// O(n^2) time | O(1) space
int firstNonRepeatingCharacterNested(string string) {
    for(int i = 0; i < string.length(); i++) {// O(n) time
        bool foundDuplicate = false;
        for(int j = 0; j < string.length(); j++) {// O(n) time NESTED
            if(string[i] == string[j] && i != j) {
                foundDuplicate = true;
            }
        }
        if(!foundDuplicate) {
            return i;
        }
    }
    return -1;
}

int main() {
    return 0;
}
