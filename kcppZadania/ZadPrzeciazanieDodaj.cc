#include <iostream>
#include <string>

// 1. Dodawanie liczb całkowitych (int)
int dodaj(int a, int b){
    return a + b;
}
// 2. Dodawanie liczb zmiennoprzecinkowych (float)
float dodaj(float a, float b){
    return a + b;
}

// 3. Konkatenacja napisów (std::string)
std::string dodaj(std::string a, std::string b) {
    return a + b; 
}

int main(){

    std::cout << "Dodaj dla calkowitych: " << dodaj(5,4) << std::endl;
    std::cout << "Dodaj dla zmiennoprzecinkowych: " << dodaj(3.5f,4.5f) << std::endl;
    std::string s1 = "Hello ";
    std::string s2 = "world!";
    std::cout << "Napis: " << dodaj(s1, s2) << std::endl;
    return 0;
}