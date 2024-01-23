import Console from "./Console.js";

class ConsoleManager {
    constructor() {
        this.consoles = [];
    }

    addConsole(console) {
        if (!(console instanceof Console)) {
            throw new Error(
                "ERROR - A ConsoleManager only manages Console objects"
            );
        }
        this.consoles.push(console);
    }

    deactivateAll() {
        for (const console of this.consoles) {
            console.deactivate();
        }
    }
}

export default ConsoleManager;
