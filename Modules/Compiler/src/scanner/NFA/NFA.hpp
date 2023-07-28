#pragma once

#include "Types.hpp"
#include "../DFA/DFAState.hpp"
#include <memory>
#include <unordered_map>


namespace scanner {
    enum OperationType {
        CONCATENATION,
        UNION
    };

    class NFA {
    private:
        shared_ptr<NFAState> initialState;
        shared_ptr<NFAState> acceptingState;

        static auto GetSubExpressionEndOffset(const string &regex, int &i) -> int;
        static auto ConstructUnion(const NFA &nfa1, const NFA &nfa2) -> NFA;
        static auto ConstructStar(const NFA &nfa) -> NFA;
        static auto ConstructPlus(const NFA &nfa) -> NFA;
        static auto ConstructOptional(const NFA &nfa) -> NFA;
        static auto ConstructDot() -> NFA;
        static auto ConstructCharacter(const char character) -> NFA;
        static auto ConstructCharacterRange(const char startCharacter, const char endCharacter) -> NFA;
        static auto ConstructUpArrow(const char exceptCharacter) -> NFA;
        static auto ConstructConcatenation(const NFA &nfa1, const NFA &nfa2) -> NFA;

    public:
        NFA();

        auto GetInitialState() const -> shared_ptr<NFAState>;

        static auto FromRegex(const string &regex) -> NFA;
    };
}