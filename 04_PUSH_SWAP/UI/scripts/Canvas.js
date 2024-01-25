import Stack from "./Stack.js";

class Canvas {
    constructor(elementId, stack) {
        this.element = document.getElementById(elementId);
        if (!this.element) {
            throw new Error(
                "ERROR - A ConsoleManager argument is required for creating a Console object"
            );
        }
        if (!(stack instanceof Stack)) {
            throw new Error(
                "ERROR - A Stack argument is required for creating a Canvas object"
            );
        }
        this.stack = stack;

        // Setting the right height and width
        this.element.height = 600;
        this.element.width = 512;

        this.context = this.element.getContext("2d");
        this.height = this.element.height;
        this.width = this.element.width;
        this.widthMin = 20;
        this.widthMax = this.width;
        if (this.stack.length() === 0) {
            this.dh = 0;
            this.dw = 0;
            this.writeEmptyStack();
        } else {
            this.dh = Math.floor(this.height / this.stack.length());
            this.dw = Math.floor(
                (this.widthMax - this.widthMin) / this.stack.length()
            );
            this.drawStack();
        }
    }

    clear() {
        this.context.clearRect(0, 0, this.width, this.height);
    }

    stackUpdateHandler() {
        this.dh = Math.floor(this.height / this.stack.length());
        this.dw = Math.floor(
            (this.widthMax - this.widthMin) / this.stack.length()
        );
        if (this.stack.length() == 0) {
            this.writeEmptyStack();
        } else {
            this.drawStack();
        }
    }

    writeEmptyStack() {
        const text = "The stack is empty";
        const fontSize = 20;
        this.context.imageSmoothingEnabled = false;
        this.context.font = `${fontSize}px Arial`;
        const textWidth = this.context.measureText(text).width;
        const x = (this.element.width - textWidth) / 2;
        const y = this.element.height / 2;
        this.context.fillStyle = "black";
        this.context.fillText(text, x, y);
    }

    drawStack() {
        let currentValue, sortedIndex, rectHeight, rectWidth, xPos, yPos;
        const stackLength = this.stack.length();

        this.clear();
        for (let i = 0; i < stackLength; i++) {
            currentValue = this.stack.content[stackLength - 1 - i];
            sortedIndex = this.stack.sortedContent.indexOf(currentValue);
            rectHeight = this.dh;
            rectWidth = this.widthMin + sortedIndex * this.dw;
            xPos = Math.floor(this.width / 2 - rectWidth / 2) * 0;
            yPos = this.height - (i + 1) * this.dh;
            this.drawRect("blue", [xPos, yPos], rectWidth, rectHeight);
        }
    }

    drawRect(color, pointA, width, height) {
        if (!Array.isArray(pointA) || pointA.length !== 2)
            throw new Error(
                "ERROR - In order to draw a rectangle, you have to pass to valid points"
            );
        this.context.fillStyle = color;
        this.context.fillRect(pointA[0], pointA[1], width, height);
    }
}

export default Canvas;
