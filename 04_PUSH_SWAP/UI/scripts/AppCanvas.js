import Canvas from "./Canvas.js";
import Stack from "./Stack.js";

class AppCanvas {
    constructor({
        stackA = null,
        stackB = null,
        stackACanvasId = null,
        stackBCanvasId = null,
        height = 600,
        width = 512,
    }) {
        if (!(stackA instanceof Stack) || !(stackB instanceof Stack)) {
            throw new Error(
                "ERROR - Both stackA and stackB must be instances of Stack"
            );
        }

        this.stackA = stackA;
        this.stackB = stackB;
        this.width = width;
        this.height = height;
        this.widthMin = 20;
        this.widthMax = this.width;
        this.evalDimensions();

        try {
            this.canvasA = new Canvas(
                stackACanvasId,
                stackA,
                height,
                width,
                this.dh,
                this.dw,
                this.widthMin
            );
            this.canvasB = new Canvas(
                stackBCanvasId,
                stackB,
                height,
                width,
                this.dh,
                this.dw,
                this.widthMin
            );
        } catch (error) {
            throw error;
        }
        this.drawStacks();
    }

    evalDimensions() {
        this.stacksGlobalContent = [
            ...this.stackA.sortedContent,
            ...this.stackB.sortedContent,
        ];
        this.stacksGlobalContent.sort();
        const nbElt = this.stacksGlobalContent.length;
        if (nbElt === 0) {
            this.dh = 0;
            this.dw = 0;
        } else {
            this.dh = Math.floor(this.height / nbElt);
            this.dw = Math.floor((this.widthMax - this.widthMin) / nbElt);
        }
    }

    drawStacks() {
        this.canvasA.drawStack(this.stacksGlobalContent);
        this.canvasB.drawStack(this.stacksGlobalContent);
    }

    updateStacksHandler() {
        this.evalDimensions();
        this.drawStacks();
    }
}

export default AppCanvas;
