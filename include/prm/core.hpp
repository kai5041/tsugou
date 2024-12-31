#ifndef PRM_CORE_HPP
#define PRM_CORE_HPP

#include <prm/command.hpp>
#include <prm/ctx.hpp>
#include <prm/utils.hpp>

#define PRM_VERSION "1.0.0"

namespace prm {

int version(Ctx *ctx = nullptr);
int init(Ctx *ctx);
int run(Ctx *ctx);
int build(Ctx *ctx);

static Commands commands = {
    {"version", "Print prm's version", "prm version", version},
    {"init", "Initialize new prm project", "prm init", init},
    {"run", "Run prm project", "prm run", run},};

} // namespace prm

#endif