import AppCanvas from "./AppCanvas.js";
import AppData from "./AppData.js";
import Canvas from "./Canvas.js";
import Console from "./Console.js";
import ConsoleManager from "./ConsoleManager.js";

const stackUpdateEvent = new CustomEvent("stackUpdate");

const appData = new AppData(stackUpdateEvent);
appData.push(45, 78, -1, 56, 0, 789, 65, 42, 788, 754, 712, 456, 123, 312);

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

/*
const consoleManager = new ConsoleManager();
const generalConsole = new Console(
    "consoleGeneral",
    "consoleGeneralButton",
    consoleManager,
    true
);
const stacksConsole = new Console(
    "consoleStacks",
    "consoleStacksButton",
    consoleManager
);
const commandConsole = new Console(
    "consoleCommands",
    "consoleCommandsButton",
    consoleManager
);
*/
