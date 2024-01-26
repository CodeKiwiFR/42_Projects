import Console from "./Console.js";

class ConsoleManager {
    static validConsoleNames = ["general", "stacks", "commands"];

    constructor({
        generalConsoleId = null,
        generalConsoleButtonId = null,
        generalIsActive = false,
        stacksConsoleId = null,
        stacksConsoleButtonId = null,
        stacksIsActive = false,
        commandsConsoleId = null,
        commandsConsoleButtonId = null,
        commandsIsActive = false,
    }) {
        try {
            this.consoles = {
                general: new Console(
                    generalConsoleId,
                    generalConsoleButtonId,
                    generalIsActive
                ),
                stacks: new Console(
                    stacksConsoleId,
                    stacksConsoleButtonId,
                    stacksIsActive
                ),
                commands: new Console(
                    commandsConsoleId,
                    commandsConsoleButtonId,
                    commandsIsActive
                ),
            };
        } catch (error) {
            throw error;
        }
    }

    addConsole(name, console) {
        if (!(console instanceof Console)) {
            throw new Error(
                "ERROR - A ConsoleManager only manages Console objects"
            );
        }
        if (ConsoleManager.validConsoleNames.indexOf(name) == -1) {
            throw new Error("ERROR - Invalid Console name");
        }
        this.consoles[name] = console;
    }

    deactivateAll() {
        for (let name in this.consoles) {
            this.consoles[name].deactivate();
        }
    }
}

export default ConsoleManager;
