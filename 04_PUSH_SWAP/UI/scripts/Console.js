import ConsoleManager from "./ConsoleManager.js";

class Console {
    static activationClassName = "active-console";

    constructor(elementId, buttonId, consoleManager, isActive = false) {
        this.element = document.getElementById(elementId);
        this.buttonElement = document.getElementById(buttonId);
        if (!(consoleManager instanceof ConsoleManager)) {
            throw new Error(
                "ERROR - A ConsoleManager argument is required for creating a Console object"
            );
        }
        this.consoleManager = consoleManager;
        this.isActive = isActive;
        if (!this.element || !this.buttonElement) {
            throw new Error("ERROR - Element or button id is invalid");
        }
        this.buttonElement.addEventListener("click", (event) => {
            if (!this.isActive) this.activate();
        });
        this.consoleManager.addConsole(this);
    }

    clearConsole() {
        this.element.innerText = "";
    }

    appendConsole(str) {
        this.element.innerText += "\n" + str;
        this.element.scrollTop = this.element.scrollHeight;
    }

    activate() {
        this.setActiveState(true);
    }

    deactivate() {
        this.setActiveState(false);
    }

    setActiveState(isActive) {
        if (isActive) {
            this.consoleManager.deactivateAll();
        }
        this.isActive = isActive;
        this.element.classList.toggle(Console.activationClassName, isActive);
        this.buttonElement.classList.toggle(
            Console.activationClassName,
            isActive
        );
    }
}

export default Console;
