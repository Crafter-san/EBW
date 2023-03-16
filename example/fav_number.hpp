#include "command.hpp"
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
