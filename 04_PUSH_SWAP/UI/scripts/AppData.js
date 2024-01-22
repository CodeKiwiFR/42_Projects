import Stack from "./Stack.js";
import CommandQueue from "./CommandQueue.js";

class AppData {
    constructor() {
        this.stack_a = new Stack("a");
        this.stack_b = new Stack("b");
        this.commands = new CommandQueue();
    }

    push(...nbs) {
        try {
            this.stack_a.push(...nbs);
        } catch (error) {
            throw error;
        }
    }

    sa() {
        if (this.stack_a.length() >= 2) {
            this.stack_a.swap();
            console.log("sa");
        }
    }

    sb() {
        if (this.stack_b.length() >= 2) {
            this.stack_b.swap();
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
    }

    pa() {
        if (this.stack_b.length() >= 1) {
            try {
                this.stack_a.push(this.stack_b.pop());
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
                console.log("pb");
            } catch (error) {
                throw error;
            }
        }
    }

    ra() {
        if (this.stack_a.length() >= 2) {
            this.stack_a.rot();
            console.log("ra");
        }
    }

    rb() {
        if (this.stack_b.length() >= 2) {
            this.stack_b.rot();
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
    }

    rra() {
        if (this.stack_a.length() >= 2) {
            this.stack_a.rev_rot();
            console.log("rra");
        }
    }

    rrb() {
        if (this.stack_b.length() >= 2) {
            this.stack_b.rev_rot();
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
}

export default AppData;
