#include "MyBot.h"
#include <dpp/dpp.h>
#include <iostream>
#include <unordered_map>
#include "commands.hpp" // This is NOT the command.hpp file, this is a file that groups all the commands together.

/* Be sure to place your token in the line below.
 * Follow steps here to get a token:
 * https://dpp.dev/creating-a-bot-application.html
 * When you invite the bot, be sure to invite it with the 
 * scopes 'bot' and 'applications.commands', e.g.
 * https://discord.com/oauth2/authorize?client_id=940762342495518720&scope=bot+applications.commands&permissions=139586816064
 */
const std::string    BOT_TOKEN    = "";
const std::string    CHANNEL_ID   = "";

int main()
{
    
    /* Create bot cluster */
    dpp::cluster bot(BOT_TOKEN);

    /* Output simple log messages to stdout */
    bot.on_log(dpp::utility::cout_logger());

    /* Handle slash command */
    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        std::string command_name = event.command.get_command_name();
        EBW::Command& command = EBW::command_map[command_name];
        EBW::Cmd(bot, event, command);
    });


    
    /* Register slash command here in on_ready */
    bot.on_ready([&bot](const dpp::ready_t& event) {
        /* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
        if (dpp::run_once<struct register_bot_commands>()) {
            EBW::init_commands(bot, registered_commands);
            
            bot.message_create(dpp::message(CHANNEL_ID, "Bot Online!"));
        }
    });

    /* Start the bot */
    bot.start(dpp::st_wait);

    return 0;
}
