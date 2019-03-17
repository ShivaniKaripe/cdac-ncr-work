#include <iostream> 
 #include<string>
int main() 
{ 
    // String to be parsed 
    std::string str = "shiv"; 
  
    // val to store parsed floating type number 
    float val = std::stof(str); 
  
    // Printing parsed floating type number 
    std::cout << val; 
  
    return 0; 
} 