#include "command.hpp" //THIS is the command.hpp file that contains EBW.
#include <string>
#include <vector>
#include <unordered_map>

EBW::Command fav_number = {
	.id = "fav_number",
	.display = "Choose a number!",
	.arguments = {
		{
			.id = "num",
			.display = "Number",
			.options = {
				{
					.id = "1",
					.display = "I like 1"
				},
				{
					.id = "2",
					.display = "I like 2"
				},
				{
					.id = "3",
					.display = "I like 3"
				},
				{
					.id = "4",
					.display = "I like 4"
				},
				{
					.id = "5",
					.display = "I like 5"
				},
				{
					.id = "6",
					.display = "I like 6"
				},
				{
					.id = "7",
					.display = "I like 7"
				},
				{
					.id = "8",
					.display = "I like 8"
				}
			}
		}
	},
	.execute = [](dpp::cluster& bot, const dpp::slashcommand_t& event, EBW::Evt cmd) {
		std::string choice = cmd.arg["num"];
		event.reply("You chose: " + choice + ". You're a COUNT dracula!");
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

EBW::Command ping = {
	.id = "ping",
	.display = "Ping",
	.response = "Pong!",
	.execute = [](dpp::cluster& bot, const dpp::slashcommand_t& event, EBW::Evt cmd) {
		std::string response = cmd.cmd.response;
		event.reply(response);
	}
};
std::vector<EBW::Command> registered_commands = {
		fav_number, greet, ping
};
