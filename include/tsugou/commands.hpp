#ifndef TSUGOU_COMMANDS_HPP
#define TSUGOU_COMMANDS_HPP

#include <tsugou/utils.hpp>

#include <tsugou/command.hpp>

#include <tsugou/exception.hpp>

#include <iostream>

namespace tsugou {

void init_project(Ctx &ctx);
void execute_script(Ctx &ctx);

void help(Ctx &ctx);

const Commands commands = {
    {"help", "Prints this message", "tsu help", help},
    {"init", "Initialize the current directory as a tsu project", "tsu init",
     init_project},
    {"exec", "Run a script", "tsu exec <script_name>", execute_script, 1},
};

} // namespace tsugou

#endif