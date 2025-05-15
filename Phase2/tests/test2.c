#include <stdio.h>

// Test function with undeclared variables and type mismatch
int test_function(int a, float b) {
    int x;
    int y;
    int f= 3;
    // Undeclared variable usage
    int z = 10;
    
    // Type mismatch 
    x = "string";
    
    // Variable redeclaration
    int x;
    
    // Type mismatch in return
    return "error";
}

// Test scope and variable visibility
void test_scope() {
    int outer = 10;
    
    {
        // Valid nested scope
        int inner = 20;
        outer = inner; // Valid - outer is visible here
    }
    
    // Error - inner not visible here
    inner = 30;
}

// Test array access
void test_array() {
    int arr[10];
    
    // Valid array access
    arr[0] = 5;
    
    // Invalid index type
    float index = 1.5;
    arr[index] = 10;
}

// Missing return in non-void function
int missing_return() {
    int x = 10;
    // No return statement
}

int main() {
    int a;
    float b;
    
    // Function call with undeclared function
    undeclared_function();
    
    // Valid function call
    test_function(a, b);
    
    // Test scopes
    test_scope();
    
    // Test arrays
    test_array();
    
    // Test missing return
    missing_return();
    
    return 0;
} 