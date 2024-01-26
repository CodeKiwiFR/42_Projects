import Stack from "./Stack.js";
import CommandQueue from "./CommandQueue.js";
import ConsoleManager from "./ConsoleManager.js";

class AppData {
    constructor(updateStackEvent = null, consoleManager) {
        this.stack_a = new Stack("a");
        this.stack_b = new Stack("b");
        this.commands = new CommandQueue();

        if (
            updateStackEvent != null &&
            !(updateStackEvent instanceof CustomEvent)
        ) {
            throw new Error(
                "ERROR - The parameter updateStackEvent is expected to be an instance of CustomEvent"
            );
        }
        this.updateStackEvent = updateStackEvent;

        if (!(consoleManager instanceof ConsoleManager)) {
            throw new Error(
                "ERROR - consoleManager has to be an instance of ConsoleManager"
            );
        }
        if (
            !consoleManager.consoles["stacks"] ||
            !consoleManager.consoles["commands"] ||
            !consoleManager.consoles["general"]
        ) {
            throw new Error(
                "ERROR - consoleManager should contain all consoles of the app"
            );
        }
    }

    push(...nbs) {
        try {
            this.stack_a.push(...nbs);
            this.triggerUpdateEvent();
        } catch (error) {
            throw error;
        }
    }

    sa() {
        if (this.stack_a.length() >= 2) {
            this.stack_a.swap();
            this.triggerUpdateEvent();
            console.log("sa");
        }
    }

    sb() {
        if (this.stack_b.length() >= 2) {
            this.stack_b.swap();
            this.triggerUpdateEvent();
            console.log("sb");
        }
    }

    ss() {
        let swapped_a = false;
        let swapped_b = false;

        if (this.stack_a.length() >= 2) {
            this.stack_a.swap();
            swapped_a = true;
        }
        if (this.stack_b.length() >= 2) {
            this.stack_b.swap();
            swapped_b = true;
        }
        if (swapped_a && swapped_b) {
            console.log("ss");
        } else if (swapped_a) {
            console.log("sa");
        } else if (swapped_b) {
            console.log("sb");
        }
        this.triggerUpdateEvent();
    }

    pa() {
        if (this.stack_b.length() >= 1) {
            try {
                this.stack_a.push(this.stack_b.pop());
                this.triggerUpdateEvent();
                console.log("pa");
            } catch (error) {
                throw error;
            }
        }
    }

    pb() {
        if (this.stack_a.length() >= 1) {
            try {
                this.stack_b.push(this.stack_a.pop());
                this.triggerUpdateEvent();
                console.log("pb");
            } catch (error) {
                throw error;
            }
        }
    }

    ra() {
        if (this.stack_a.length() >= 2) {
            this.stack_a.rot();
            this.triggerUpdateEvent();
            console.log("ra");
        }
    }

    rb() {
        if (this.stack_b.length() >= 2) {
            this.stack_b.rot();
            this.triggerUpdateEvent();
            console.log("rb");
        }
    }

    rr() {
        let rot_a = false;
        let rot_b = false;

        if (this.stack_a.length() >= 2) {
            this.stack_a.rot();
            rot_a = true;
        }
        if (this.stack_b.length() >= 2) {
            this.stack_b.rot();
            rot_b = true;
        }
        if (rot_a && rot_b) {
            console.log("rr");
        } else if (rot_a) {
            console.log("ra");
        } else if (rot_b) {
            console.log("rb");
        }
        this.triggerUpdateEvent();
    }

    rra() {
        if (this.stack_a.length() >= 2) {
            this.stack_a.rev_rot();
            this.triggerUpdateEvent();
            console.log("rra");
        }
    }

    rrb() {
        if (this.stack_b.length() >= 2) {
            this.stack_b.rev_rot();
            this.triggerUpdateEvent();
            console.log("rrb");
        }
    }

    rrr() {
        let rot_a = false;
        let rot_b = false;

        if (this.stack_a.length() >= 2) {
            this.stack_a.rev_rot();
            rot_a = true;
        }
        if (this.stack_b.length() >= 2) {
            this.stack_b.rev_rot();
            rot_b = true;
        }
        if (rot_a && rot_b) {
            console.log("rr");
        } else if (rot_a) {
            console.log("ra");
        } else if (rot_b) {
            console.log("rb");
        }
        this.triggerUpdateEvent();
    }

    toString() {
        return `Stack_a: [${this.stack_a.toString()}]\nStack_b: [${this.stack_b.toString()}]`;
    }

    isSorted(stackLetter) {
        if (stackLetter === "a") {
            return this.stack_a.isSorted();
        } else if (stackLetter === "b") {
            return this.stack_b.isSorted();
        } else {
            return false;
        }
    }

    isRevSorted(stackLetter) {
        if (stackLetter === "a") {
            return this.stack_a.isRevSorted();
        } else if (stackLetter === "b") {
            return this.stack_b.isRevSorted();
        } else {
            return false;
        }
    }

    pushCommands(...commands) {
        try {
            this.commands.push(...commands);
        } catch (error) {
            throw error;
        }
    }

    popCommand() {
        try {
            return this.commands.pop();
        } catch (error) {
            throw error;
        }
    }

    triggerUpdateEvent() {
        if (this.updateStackEvent != null) {
            document.dispatchEvent(this.updateStackEvent);
        }
    }
}

export default AppData;
