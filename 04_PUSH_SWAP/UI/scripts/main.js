import AppData from "./AppData.js";

const app = new AppData();

console.log(String(app));

app.push(12, 24, -56, 789);
console.log(String(app));

app.pb();
app.sa();
console.log(String(app));

app.ra();
app.rb();
console.log(String(app));

app.pb();
app.rb();
console.log(String(app));

app.pb();
app.rr();
console.log(String(app));

app.push(77, 84, 13);
console.log(String(app));
app.push(77);