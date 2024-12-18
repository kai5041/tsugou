#ifndef PRM_CORE_HPP
#define PRM_CORE_HPP

#include <prm/command.hpp>
#include <prm/ctx.hpp>
#include <prm/utils.hpp>

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

namespace prm {

int init(Ctx &ctx);

inline std::vector<prm::Command> functions = {
    {"init", init},

};


} // namespace prm

#endif