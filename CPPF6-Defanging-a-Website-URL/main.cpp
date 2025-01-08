#include <iostream>
#include <string>

// Method 1: iterating through all characters, replacing the ., which will modify 
void defang(std::string& address) {
  // Initialize our index counter
  size_t i = 0;

  // Repeatedly find the length
  while (i != address.length() - 1) {
    if (address[i] == '.') {
      // Replace . with [.]
      address.replace(i, 1, "[.]");
      // Skip .]
      i += 2;
    }
    i++;
  }
}

// Method 2: appending to a new result string, returning it by value
std::string defangValue(std::string& address) {
  std::string res = "";
  for (int i = 0; i < address.length(); ++i) {
    if (address[i] == '.') {
      res += "[.]";
    } else {
      res += address[i];
    }
  }
  return res;
}

int main() {


  std::string address; // = "www.malware.com";
  std::cout << "\nEnter a website: ";
  std::cin >> address;

  // Use the returned by value string
  std::string returnedValue = defangValue(address);

  // Use the version that modifies the reference to the string itself
  defang(address);
  std::cout << address << std::endl;
}