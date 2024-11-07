#include <iostream>

struct GameSession {
    // Game session data here
};

void runGame(GameSession&) {
    throw 1;
}

void saveGame(GameSession&) {
    // Save user's game here
}

class DummyException { // a dummy class that cant be instantiated
    DummyException() = delete;
};

int main() {
    GameSession session{};
    try {
        runGame(session);
    }
#ifndef NDEBUG   // if we're in release node
    catch(...) { // compile in the cath-all handler
        std::cerr << "Abnormal termination\n";
    }
#else
    catch(DummyException) {
    }
#endif
    saveGame(session);
}
