#include "Parser.hpp"
#include "State.hpp"
#include "language/Language.hpp"
#include "language/Symbols.hpp"
#include "parser/Tables.hpp"

using language::Symbol;



namespace parser {
    namespace {
        bool initialized = false;
        shared_ptr<State> root;
    }

    auto Parse(const string &path, const vector<Line> &lines) -> shared_ptr<NonTerminal> {
        if (!initialized) {
            root = State::BuildRoot();
            initialized = true;
        }

        stack<shared_ptr<State>> stateStack;
        stack<Symbol> symbolStack;
        stateStack.push(root);
        int lineIndex = 0;
        int terminalIndex = 0;
        bool parseComplete = false;

        while (!parseComplete) {
            if (terminalIndex == lines.at(lineIndex).terminals.size()) {
                terminalIndex = 0;
                lineIndex++;
            }

            Terminal currentTerminal = lines.at(lineIndex).terminals.at(terminalIndex);
            Tables::Action action = Tables::GetAction(stateStack.top(), currentTerminal.type);

            switch (action.type) {
                case Tables::ACCEPT:
                    parseComplete = true;
                    break;

                case Tables::SHIFT:
                    stateStack.push(action.state);
                    symbolStack.push(currentTerminal.type);
                    terminalIndex++;
                    break;

                case Tables::REDUCE:
                    for (int i = 0; i < action.item.right.size(); i++) {
                        stateStack.pop();
                        symbolStack.pop();
                    }
                    symbolStack.push(action.item.left);
                    stateStack.push(Tables::GetGoto(stateStack.top(), action.item.left));
                    break;
            }

            cout << "[" << lineIndex << ":" << terminalIndex << "] ";
            switch (action.type) {
                case Tables::ACCEPT: cout << "ACCEPT"; break;
                case Tables::SHIFT: cout << "SHIFT " << action.state; break;
                case Tables::REDUCE: cout << "REDUCE " << language::ToString(action.item.left); break;
            }
            cout << "\n";

            cout << " symbols | ";
            for (stack<Symbol> clone = symbolStack; !clone.empty(); clone.pop()) {
                cout << language::ToString(clone.top().type) << " ";
            }
            cout << "\n";

            cout << " state |" << "\n";
            for (auto x : stateStack.top()->GetItems()) {
                cout << "  " << language::ToString(x.left) << " -> ";
                for (auto y : x.right) {
                    cout << language::ToString(y) << " ";
                }
                cout << "(" << x.position << ") { ";
                for (auto y : x.lookahead) {
                    cout << language::ToString(y) << " ";
                }
                cout << "}\n";
            }
            cout << "\n";
        }

        std::cout << "wtf it actually worked???????" << "\n";

        return nullptr;
    }
}