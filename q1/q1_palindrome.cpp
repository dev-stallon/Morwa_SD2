//Design
//bool isPalindrome(const string& text);
//Step 1: another variable to hold palindrome

//Step 2: Remove punctuation -> remove any non-alpha character

//Step 3: to lower case

//madamine d enimadam


//Step 4: Checking if palindrome : Comparison
//madamine d enimadam

#include <iostream>
#include <string>
#include <algorithm>
#include <locale>

//using  std::string
//using namespace std;

bool isPalindrome(const std::string& text)
{
    std::string input = text; //Step 1 done

    //Step 2
    //remove_if(first, last, pred)
    //input = |n|U|n|"|:|,|,|
    auto newBegin = std::remove_if(input.begin(), input.end(), [](unsigned char c) { return !std::isalpha(c);});

    //Delete punctuation

    input.erase(newBegin,input.end());
    if(input.empty()) return false;

    //Step 3
    // transform(first, last,result, op)
    //sMDhjJ
    //first = 0
    //last = 6
    //result = 0
    std::transform(input.begin(), input.end(),input.begin(), [](unsigned char c) {return std::tolower(c);});

    //Step 4: Comparison
 
    return std::equal(input.begin(), input.begin() + input.size()/2, input.rbegin());


}

int main(){

    std::string palindrome = "A man, a plan, a canal- Panama!";

    if(isPalindrome(palindrome))  std::cout<<palindrome<<" is a palindrome "<<std::endl;
    else std::cout<<palindrome<<" is not a palindrome "<<std::endl;
  

    return 0;
}