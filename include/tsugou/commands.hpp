#ifndef TSUGOU_COMMANDS_HPP
#define TSUGOU_COMMANDS_HPP

#include <tsugou/utils.hpp>

#include <tsugou/command.hpp>

#include <iostream>

namespace tsugou {

void init_project(Ctx &ctx);

void help(Ctx &ctx);

const Commands commands = {
    {"help", "Prints this message", "tsu help", help},
    {"init", "Initialize the current directory as a tsu project", "tsu init",
     init_project}};

} // namespace tsugou

#endif