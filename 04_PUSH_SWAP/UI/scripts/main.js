import AppCanvas from "./AppCanvas.js";
import AppData from "./AppData.js";
import Console from "./Console.js";
import ConsoleManager from "./ConsoleManager.js";

// Creation of the consoles and the console manager
const consoleManager = new ConsoleManager({
    generalConsoleId: "consoleGeneral",
    generalConsoleButtonId: "consoleGeneralButton",
    generalIsActive: true,
    stacksConsoleId: "consoleStacks",
    stacksConsoleButtonId: "consoleStacksButton",
    commandsConsoleId: "consoleCommands",
    commandsConsoleButtonId: "consoleCommandsButton",
});

// Creation of stack data: two stacks, a stack Manager and a custom event for stack updates
const stackUpdateEvent = new CustomEvent("stackUpdate");

const appData = new AppData(stackUpdateEvent, consoleManager);
appData.push(789, 45, 78, -1, 56, 0, 65, 42, 754, 712, 456, 123, 312, 788);

// Creation of the two canvas 
const appCanvas = new AppCanvas({
    stackA: appData.stack_a,
    stackB: appData.stack_b,
    stackACanvasId: "stackA_canvas",
    stackBCanvasId: "stackB_canvas",
});

document.addEventListener("stackUpdate", (event) => {
    appCanvas.updateStacksHandler();
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
    appData.sa();
});
ButtonSB.addEventListener("click", (event) => {
    appData.sb();
});
ButtonSS.addEventListener("click", (event) => {
    appData.ss();
});
ButtonPA.addEventListener("click", (event) => {
    appData.pa();
});
ButtonPB.addEventListener("click", (event) => {
    appData.pb();
});
ButtonRA.addEventListener("click", (event) => {
    appData.ra();
});
ButtonRB.addEventListener("click", (event) => {
    appData.rb();
});
ButtonRR.addEventListener("click", (event) => {
    appData.rr();
});
ButtonRRA.addEventListener("click", (event) => {
    appData.rra();
});
ButtonRRB.addEventListener("click", (event) => {
    appData.rrb();
});
ButtonRRR.addEventListener("click", (event) => {
    appData.rrr();
});
