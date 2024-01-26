import ConsoleManager from "./ConsoleManager.js";

class Console {
    static activationClassName = "active-console";

    constructor(elementId, buttonId, isActive = false) {
        this.element = document.getElementById(elementId);
        this.buttonElement = document.getElementById(buttonId);
        this.isActive = isActive;
        if (!this.element || !this.buttonElement) {
            throw new Error("ERROR - Element or button id is invalid");
        }
        this.buttonElement.addEventListener("click", (event) => {
            if (!this.isActive) this.activate();
        });
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
        this.isActive = isActive;
        this.element.classList.toggle(Console.activationClassName, isActive);
        this.buttonElement.classList.toggle(
            Console.activationClassName,
            isActive
        );
    }
}

export default Console;
