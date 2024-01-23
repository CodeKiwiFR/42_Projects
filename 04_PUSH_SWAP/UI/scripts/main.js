import AppData from "./AppData.js";
import Canvas from "./Canvas.js";
import Console from "./Console.js";
import ConsoleManager from "./ConsoleManager.js";

const appData = new AppData();

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

appData.push(12, 14, 15, 45);

const canvasA = new Canvas("stackA_canvas", appData.stack_a);
const canvasB = new Canvas("stackB_canvas", appData.stack_b);
