import Stack from "./Stack.js";

class Canvas {
    constructor(elementId, stack, height = 600, width = 512) {
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

        // Setting the right height and width (Because of screen ratio)
        this.height = height;
        this.width = width;
        this.element.height = this.height;
        this.element.width = this.width;

        // Colors
        this.minColor = [230, 230, 255];
        this.maxColor = [0, 0, 77];

        // Dimension attributes
        this.context = this.element.getContext("2d");
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
        const x = (this.width - textWidth) / 2;
        const y = this.height / 2;
        this.context.fillStyle = "black";
        this.context.fillText(text, x, y);
    }

    drawStack() {
        let currentValue, sortedIndex, rectHeight, rectWidth, xPos, yPos, color;
        const stackLength = this.stack.length();

        this.clear();
        for (let i = 0; i < stackLength; i++) {
            currentValue = this.stack.content[stackLength - 1 - i];
            sortedIndex = this.stack.sortedContent.indexOf(currentValue);
            rectHeight = this.dh;
            rectWidth = this.widthMin + sortedIndex * this.dw;
            xPos = Math.floor(this.width / 2 - rectWidth / 2) * 0;
            yPos = this.height - (i + 1) * this.dh;
            color = this.getEltColor(sortedIndex / stackLength);
            this.drawRect(color, [xPos, yPos], rectWidth, rectHeight);
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

    // Fonction pour générer une couleur intermédiaire entre deux couleurs
    getEltColor(factor) {
        const result = this.minColor.map((channel, index) => {
            const diff = Math.abs(this.maxColor[index] - channel);
            if (this.maxColor[index] > channel) {
                return Math.round(channel + factor * diff);
            } else {
                return Math.round(channel - factor * diff);
            }
        });
        return `rgb(${result.join(",")})`;
    }
}

export default Canvas;
