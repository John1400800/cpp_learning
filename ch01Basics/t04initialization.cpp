int main() {
    int a;              // default     initialization
    int b = 5;          // copy        initialization
    int c( 6 );         // direct      initialization

    // List initialization methods (C++11) (preferred)
    int d { 7 };        // direct list initialization
    int e = { 8 };      // copy   list initialization
    int f {};           // value       initialization

    return 0;
}
