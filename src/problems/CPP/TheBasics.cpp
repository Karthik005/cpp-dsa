#include<iostream>
#include<vector>
#include<exception>

using namespace std;

/* Consts and constexpr: 
 * const: Will not change value
 * contexpr: Evaluated at compile time  for const input: may be evaluated
 * at runtime for non-const input
 */

constexpr int square (int x) { return x*x;} //Evaluated at compile time for const input

/* Enums class values are in scope of their enum class so not visible outside*/
/* Used with namespace of the class */
enum class Color
{
    red,
    blue,
    green
};

/* Enum vals all publicly accessible (global scope)
 * Integer values
 */
enum OtherColor{
    red,
    blue,
    green
};

void show_basics_loop_cond()
{
    /*Types and assignment*/
    auto a = 15; //Use auto for automatic type inference
    int b{10};   //No type conversion unlike '=' assignment,
                 // Will result in error if wrong type in argument

    vector<int> apple{1, 2, 3, 4, 4}; //For collections
    int bee[]{1, 2, 3, 4, 5, 5};
    int cee[10] = {1, 2, 4};

    double *ptr;
    /* Loop Iterator */
    for (auto x : apple)
    { //Copy
        cout << x;
    }

    for (auto &x : bee)
    { //Reference
        x = x + 1;
        cout << x;
    }

    //bee = nullptr; : Can't modify an array value
    /*Shared pointer type value; don't use NULL as its not type safe*/
    ptr = nullptr;

    const int c = 10;
    switch (b)
    {
    case square(c): /*Switch takes constexprs only; const = constexpr = value*/
        /* code */
        break;

    default:
        break;
    }

    Color colr = Color::red; //Preferred
    OtherColor ocolr = red;
}

//Namespaces: All classes have namespace associated with them
// Can seperately define a namespace
namespace My_code
{
int main();
} // namespace My_code

int My_code::main()
{
    
    auto z2 = 10;
    std::cout << '{' << z2 << "}\n";
    /* Error handling Using exceptions */
    if (z2) {
        throw out_of_range("Testing exceptions");
    }
    // ...
}

int main(){
    try{
        My_code::main();
    } catch(out_of_range) {
        /*Catch the exception here*/
        /*Do stuff here */
    }

    /*
    * Static assertions
    * Will show up as compiler messages
    * Can be used to asser anything that is a constexpr
    */
    //static_assert(4>5, "Is lesser: made mistake"); //Will throw compilation error with the message

}

/*
 * Invariants
 * The constructor must make sure that all members are initialized properly
 * Must throw exceptions in case of non-conformity
 */

