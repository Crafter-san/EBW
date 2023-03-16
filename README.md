# EBW
Everlasting Bot Wrapper for D++

This is a simple ping-pong example, along with a choice example, using slash commands with the new Everlasting Bot Wrapper.
(The EBW only works in C++20 and up, so it is an optional feature)


main.cpp
```c++
#include "MyBot.h" //This file is REQUIRED by DPP
#include <dpp/dpp.h>
#include <iostream>
#include <unordered_map>
#include "commands.hpp"
 


int main() {
    dpp::cluster bot("BOT_TOKEN");
 
    bot.on_slashcommand([](auto event) {
        std::string command_name = event.command.get_command_name();
        EBW::Command& command = EBW::command_map[command_name];
        EBW::Cmd(bot, event, command);
    });
 
    bot.on_ready([&bot](auto event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            EBW::init_commands(bot, registered_commands);
        }
    });
 
    bot.start(dpp::st_wait);
}
```

commands.hpp
```c++
#include "command.hpp"
#include <string>
#include <vector>
#include <unordered_map>
EBW::Command ping = {
	.id = "ping",
	.display = "Ping",
	.response = "Pong!",
	.execute = [](dpp::cluster& bot, const dpp::slashcommand_t& event, EBW::Evt cmd) {
		std::string response = cmd.cmd.response;
		event.reply(response);
	}
};
EBW::Command greet = {
	.id = "greet",
	.display = "Choose a greeting!",
	.arguments = {
		{
			.id = "greeting",
			.display = "Specify a greeting.",
			.options = {
				{
					.id = "casual",
					.display = "Hi!",
					.response = "Hi, person!"
				},
				{
					.id = "formal",
					.display = "Hello!",
					.response = "Hello there, human!"
				},
				{
					.id = "query",
					.display = "How are you?",
					.response = "I'm doing great, how are you?"
				}
			}
		}
	},
	.execute = [](dpp::cluster& bot, const dpp::slashcommand_t& event, EBW::Evt cmd) {
		std::string choice = cmd.arg["greeting"];
		event.reply(cmd.cmd.argument_map["greeting"].option_map[choice].response);
	}
};
std::vector<EBW::Command> registered_commands = {
	ping, greet
};
```

