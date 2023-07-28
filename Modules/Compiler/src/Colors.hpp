#pragma once

#include <Types.hpp>



namespace Colors {
    // https://gist.github.com/vicenteguerra/e81189c7242631cd0832ccbc6f1976f9
    const string BLACK = "\x1b[30m";
    const string RED = "\x1b[31m";
    const string BRIGHT_RED = "\x1b[91m";
    const string GREEN = "\x1b[32m";
    const string YELLOW = "\x1b[33m";
    const string BRIGHT_YELLOW = "\x1b[93m";
    const string BLUE = "\x1b[34m";
    const string BRIGHT_BLUE = "\x1b[94m";
    const string MAGENTA = "\x1b[35m";
    const string CYAN = "\x1b[36m";
    const string WHITE = "\x1b[37m";

    const string RESET = "\x1b[0m";
    const string NO_COLOR = "\x1b[39m";
    const string BOLD = "\x1b[1m";
}