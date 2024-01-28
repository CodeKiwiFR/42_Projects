import Console from "./Console.js";
import ConsoleManager from "./ConsoleManager.js";
import Stack from "./Stack.js";
import StackManager from "./StackManager.js";
import Canvas from "./Canvas.js";
import CanvasManager from "./CanvasManager.js";

// Creation of the consoles and the console manager
const consoleManager = new ConsoleManager({});
const generalConsole = new Console({
    elementId: "consoleGeneral",
    buttonId: "consoleGeneralButton",
    consoleManager: consoleManager,
});
const stacksConsole = new Console({
    elementId: "consoleStacks",
    buttonId: "consoleStacksButton",
    consoleManager: consoleManager,
});
const commandsConsole = new Console({
    elementId: "consoleCommands",
    buttonId: "consoleCommandsButton",
    isActive: true,
    consoleManager: consoleManager,
});
consoleManager.addConsole(generalConsole);
consoleManager.addConsole(stacksConsole);
consoleManager.addConsole(commandsConsole);

// Adding the listeners to the console buttons
generalConsole.buttonElement.addEventListener("click", (event) => {
    if (!generalConsole.isActive) {
        consoleManager.activate(generalConsole);
    }
});
stacksConsole.buttonElement.addEventListener("click", (event) => {
    if (!stacksConsole.isActive) {
        consoleManager.activate(stacksConsole);
    }
});
commandsConsole.buttonElement.addEventListener("click", (event) => {
    if (!commandsConsole.isActive) {
        consoleManager.activate(commandsConsole);
    }
});

// Creation of stack data: two stacks, a stack Manager and a custom event for stack updates
const stackUpdateEvent = new CustomEvent("stackUpdate");
const stackA = new Stack("A");
const stackB = new Stack("B");
const stackManager = new StackManager({
    stackA: stackA,
    stackB: stackB,
    updateStackEvent: stackUpdateEvent,
});
stackManager.push(789, 45, 78, -1, 56, 0, 65, 42, 754, 712, 456, 123, 312, 788);

// Creation of the two canvas and the canvas manager
const canvasManager = new CanvasManager({
    stackA: stackA,
    stackB: stackB,
});
const canvasA = new Canvas({
    elementId: "stackA_canvas",
    stack: stackA,
    height: canvasManager.height,
    width: canvasManager.width,
    dh: canvasManager.dh,
    dw: canvasManager.dw,
    widthMin: canvasManager.widthMin,
});
const canvasB = new Canvas({
    elementId: "stackB_canvas",
    stack: stackB,
    height: canvasManager.height,
    width: canvasManager.width,
    dh: canvasManager.dh,
    dw: canvasManager.dw,
    widthMin: canvasManager.widthMin,
});
canvasManager.addCanvas("A", canvasA);
canvasManager.addCanvas("B", canvasB);
canvasManager.drawStacks();

document.addEventListener("stackUpdate", (event) => {
    canvasManager.updateStacksHandler();
});
const ButtonSA = document.getElementById("buttonSA");
const ButtonSB = document.getElementById("buttonSB");
const ButtonSS = document.getElementById("buttonSS");
const ButtonPA = document.getElementById("buttonPA");
const ButtonPB = document.getElementById("buttonPB");
const ButtonRA = document.getElementById("buttonRA");
const ButtonRB = document.getElementById("buttonRB");
const ButtonRR = document.getElementById("buttonRR");
const ButtonRRA = document.getElementById("buttonRRA");
const ButtonRRB = document.getElementById("buttonRRB");
const ButtonRRR = document.getElementById("buttonRRR");
ButtonSA.addEventListener("click", (event) => {
    stackManager.sa();
});
ButtonSB.addEventListener("click", (event) => {
    stackManager.sb();
});
ButtonSS.addEventListener("click", (event) => {
    stackManager.ss();
});
ButtonPA.addEventListener("click", (event) => {
    stackManager.pa();
});
ButtonPB.addEventListener("click", (event) => {
    stackManager.pb();
});
ButtonRA.addEventListener("click", (event) => {
    stackManager.ra();
});
ButtonRB.addEventListener("click", (event) => {
    stackManager.rb();
});
ButtonRR.addEventListener("click", (event) => {
    stackManager.rr();
});
ButtonRRA.addEventListener("click", (event) => {
    stackManager.rra();
});
ButtonRRB.addEventListener("click", (event) => {
    stackManager.rrb();
});
ButtonRRR.addEventListener("click", (event) => {
    stackManager.rrr();
});
