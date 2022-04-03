/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    int value;//2
    std::string name;//3
    T(int v, const char* namePtr): value(v), name(namePtr){}  //1
};

struct Comparer                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float a { 0 }, b { 0 };
    float converge(float& updatedVal)      //12
    {
        std::cout << "U's a value: " << this->a << std::endl;
        this->a = updatedVal;
        std::cout << "U's a updated value: " << this->a << std::endl;
        while( std::abs(this->b - this->a) > 0.001f )
        {
            /*
             write something that makes the distance between that->b and that->a get smaller
             */
            this->b += 0.001f;
        }
        std::cout << "U's b updated value: " << this->b << std::endl;
        return this->b * this->a;
    }
};

struct Converger
{
    static float converge(U& that, const float& updatedVal)        //10
    {
        std::cout << "U's a value: " << that.a << std::endl;
        that.a = updatedVal;
        std::cout << "U's a updated value: " << that.a << std::endl;
        while( std::abs(that.b - that.a) > 0.001f )
        {
            /*
            write something that makes the distance between that->b and that->a get smaller
            */
            that.b += 0.1f;
        }
        std::cout << "U's b updated value: " << that.b << std::endl;
        return that.b * that.a;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(73, "Colin");                                             //6
    T t2(71, "Lynn");                                             //6
    
    Comparer f;                                            //7
    auto* smaller = f.compare(t1, t2);                              //8
    if(smaller != nullptr)
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    else
        std::cout << "Warning: smaller is pointing to a nullptr as the arguements passed to compare() were equal" <<std::endl; 
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Converger::converge( u1, updatedValue ) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.converge( updatedValue ) << std::endl;
}
